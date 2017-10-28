#include<iostream>
using namespace std;
typedef struct termen{
    int value;
    termen * next, * prev;
    };
typedef struct stermen{
    int value;
    stermen *next;
    };
class List{
public:
    int length = 0;
    };
class Simple: public List{
public:
    stermen *start, *current, *finalist;
};
class SLIFO: public Simple{
public:
    int getprev()
    {
        current = start;
        while(current->next != finalist)
        {
            current = current->next;
        }
    }
    int push(int newvalue)
    {
        if(length == 0)
        {
            stermen *morty = new stermen;
            morty->value = newvalue;
            start = current = finalist = morty;
            finalist->next = NULL;
            length++;
            return 0;
        }
        stermen *morty = new stermen;
        morty->value = newvalue;
        finalist->next = morty;
        finalist = finalist->next;
        finalist->next = NULL;
        length++;
    }
    int pop()
    {
        if(length == 0)
        {
            return 0;
        }
        if(length == 1)
        {
            delete start;
            length--;
            return 0;
        }
        getprev();
        delete finalist;
        finalist = current;
        length--;
    }
    int showlist()
    {
        if(length == 0)
        {
            return 0;
        }
        current = start;
        for(int i = 1; i <= length; i++)
        {
            cout<<current->value<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};
class SFIFO: public Simple{
public:
    int push(int newvalue)
    {
        if(length == 0)
        {
            stermen *morty = new stermen;
            morty->value = newvalue;
            start = finalist = morty;
            length++;
            return 0;
        }
        stermen *morty = new stermen;
        morty->value = newvalue;
        current = start;
        start = morty;
        morty->next = current;
        length++;
    }
    int pop()
    {
       if(length == 0)
       {
           return 0;
       }
       if(length == 1)
       {
           delete start;
           length--;
           return 0;
       }
       current = start->next;
       delete start;
       start = current;
       length--;
    }
    int showlist()
    {
        if(length == 0)
        {
            return 0;
        }
        current = start;
        for(int i = 1; i <= length; i++)
        {
            cout<<current->value<<" ";
            current = current->next;
        }
        cout<<endl;
    }
};
int main()
{
    SLIFO mylist;
    for(int i = 1; i <= 10; i++)
    {
        mylist.push(i);
    }
    mylist.showlist();
    for(int i = 1; i <= 15; i++)
    {
        mylist.pop();
        mylist.showlist();
    }
}
