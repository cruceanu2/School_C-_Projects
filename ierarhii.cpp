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
    int length;
    };
class Simple: public List{
public:
    stermen *start, *current, *finalist;
};
class SLIFO: public Simple{
public:
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
    }
};
SLIFO mylist;
int main()
{
    //SLIFO mylist;
    for(int i = 1; i <= 10; i++)
    {
        mylist.push(i);
        cout<<mylist.length<<" ";
    }
    mylist.showlist();
}
