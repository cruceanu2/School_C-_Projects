#include<iostream>
using namespace std;

typedef struct element {
                        int info;
                        struct element *next;
                        struct element *prev;
                       };
class  doublelist {
private :
    int length;
    element *start,*current,*finalist;
    public :
    doublelist() { length=0; }
    int showlenght() {cout<<endl<<length;}
    int addLIFO(int thisvalue) {
        if(length == 0)
        {
            element * morty = new element;
            morty->info = thisvalue;
            start = morty;
            start->prev = NULL;
            start->next = NULL;
            finalist = start;
            length++;
            return 0;
        }
        element * morty = new element;
        morty->info = thisvalue;
        finalist->next = morty;
        finalist->next->prev = finalist;
        finalist = finalist->next;
        finalist->next = NULL;
        length++;
        return 0;
    }
    int showlist(bool direction)
    {
        if(length == 0)
        {
            return 0;
        }
        if(direction)
        {
            current = start;
            while(current != finalist->next)
            {
                cout<<current->info<<" ";
                current = current->next;
            }
            return 0;
        }
        current = finalist;
        while(current != start->prev)
        {
            cout<<current->info<<" ";
            current = current->prev;
        }
    }
    int delLIFO()
    {
        if(length == 0)
        {
            return 0;
        }
        else if(length == 1)
        {
            start->next = NULL;
            start->info = NULL;
            length --;
            return 0;
        }
        finalist->info = NULL;
        finalist = finalist->prev;
        finalist->next = NULL;
        length--;
    }
protected :
} somelist;



int main()
{
for(int i=1;i<=10;i++)
{
    somelist.addLIFO(i);
    somelist.showlist(1);
    cout<<endl;
}
for(int i = 1; i <= 10; i++)
{
    somelist.delLIFO();
    somelist.showlist(1);
    cout<<endl;
}
for(int i=1;i<=10;i++)
{
    somelist.addLIFO(i);
    somelist.showlist(0);
    cout<<endl;
}
for(int i = 1; i <= 10; i++)
{
    somelist.delLIFO();
    somelist.showlist(0);
    cout<<endl;
}
}
