#include<iostream>
using namespace std;
typedef struct termen{
    int value;
    termen * next;
    };
class List{
public:
    int length = 0;
    termen *start, *current, *finalist;
    int getvalue(int value)
    {
        current = start;
        while(current->value != value)
        {
            current = current->next;
            if(current == finalist && current->value != value)
            {
                cout<<"Nu s-a gasit valoarea cautata in lista"<<endl;
                current = NULL;
                return 0;
            }
        }
    }
    termen *getprev()
    {
        termen *previous = new termen;
        previous = start;
        while(previous->next != current)
        {
            previous = previous->next;
        }
        return previous;
    }
    int push(int newvalue)
    {
        if(length == 0)
        {
            termen *morty = new termen;
            morty->value = newvalue;
            start = current = finalist = morty;
            finalist->next = NULL;
            length++;
            return 0;
        }
        termen *morty = new termen;
        morty->value = newvalue;
        finalist->next = morty;
        finalist = finalist->next;
        finalist->next = start;
        length++;
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
    int pop(int value)
    {
        if(length == 0)
        {
            return 0;
        }
        getvalue(value);
        if(current == NULL)
        {
            return 0;
        }
        if(current == start)
        {
            finalist->next = start->next;
            delete start;
            start = finalist->next;
            current = start;
            length--;
            return 0;
        }
        termen *previous = new termen;
        previous = getprev();
        previous->next = current->next;
        delete current;
        current = previous->next;
        length--;
    }
};
int main()
{
    List mylist;
    for(int i = 1; i <= 10; i++)
    {
        mylist.push(i);
    }
    mylist.showlist();
    mylist.pop(1);
    mylist.showlist();
    mylist.pop(5);
    mylist.showlist();
}
