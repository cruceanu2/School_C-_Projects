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
    }
};
int main()
{
    List mylist;
    for(int i = 1; i <= 10; i++)
    {
        mylist.push(i);
    }
    mylist.current = mylist.start;
    for(int i = 1; i <= 50; i++)
    {
        cout<<mylist.current->value<<" ";
        mylist.current = mylist.current->next;
    }
}
