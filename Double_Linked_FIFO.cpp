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
                   doublelist() { length=0; start=NULL;current=NULL;finalist=NULL;}
                   int addFIFO(int thisvalue)
                   {
                       if(length == 0)
                       {
                           element * morty = new element;
                           morty->info = thisvalue;
                           finalist = morty;
                           finalist->next = NULL;
                           finalist->prev = NULL;
                           start = current = finalist;
                           length++;
                           return 0;
                       }
                       element * morty = new element;
                       morty->info = thisvalue;
                       start->prev = morty;
                       start->prev->next = start;
                       start = start->prev;
                       start->prev = NULL;
                       length++;
                   }
                   int delFIFO()
                   {
                       if(length == 0)
                       {
                           return 0;
                       }
                       else if(length == 1)
                       {
                           start->next = NULL;
                           start->prev = NULL;
                           start->info = NULL;
                           start = current = finalist = NULL;
                           length--;
                           return 0;
                       }
                       start->info = NULL;
                       start = start->next;
                       //start->prev->next = NULL;
                       start->prev = NULL;
                       length--;
                   }
                   int printLIST(bool direction)
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
                   protected :
                  };

doublelist somelist;

int main()
{
for(int i=1;i<=10;i++)
{
    somelist.addFIFO(i);
    somelist.printLIST(1);
    cout<<endl;
}
for(int i = 1; i <= 10; i++)
{
    somelist.delFIFO();
    somelist.printLIST(1);
    cout<<endl;
}
for(int i=1;i<=10;i++)
{
    somelist.addFIFO(i);
    somelist.printLIST(0);
    cout<<endl;
}
for(int i = 1; i <= 10; i++)
{
    somelist.delFIFO();
    somelist.printLIST(0);
    cout<<endl;
}
}

