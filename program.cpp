/*

Liste alocate dinamic simplu inlantuite
" oarecare " - fara operare cu o strategie impusa

Inseamna ca operatii sunt permise oriunde in cadrul listei

Functii :

[1] Adaugare element

Adaugarea unui nou element s eva executa in raport cu pozitia elementului
curent din lista

    a) Adaugare la stanga curent
    b) Adaugare la dreapta curent

Pentru pozitionarea pe un anumit element trebuie

    c) Cautare element
( daca valoarea cautata exista in lista curent devine pozitionat
  pe prima pozitie unde se gaseste valoarea cautata , in caz contrar
  curent ramane in pozitia anteriorara )

  particularitati :
  - cautarea porneste din pozitia elementului curent catre pozitia ultimului
    element din lista
  - in cazul in care valoarea cautata nu exista lista va ramane nemodificata
    insa trebuie sa interceptez situatia

*/

#include<iostream>
using namespace std;
typedef struct element {
                         int info;
                         struct element *next;
                       } termen;

typedef struct {
                int length;
                termen *start,*current,*finalist;
                } lista;

lista *L;

lista *initlist()
{
lista *result=new lista;
result->length=0;
result->start=result->current=result->finalist=NULL;
return result;
}

int isempty(lista *L)
{return  (L->length==0);}
lista *addleft(lista*L, int value)
{
if (isempty(L)){
            element *new_one=new element;
            if (new_one!=NULL)
            {
                new_one->info=value;
                new_one->next=NULL;
                L->length++;
                L->start=L->current=L->finalist=new_one;
            }
            return L;
        }
        if(L->current == L->start)
        {
            element *newone = new element;
            newone->info = L->start->info;
            newone->next = L->start->next;
            L->start->info = value;
            L->start->next = newone;
            L->length++;
            return L;
        }
    termen *carrier = new termen;
    carrier = L->start;
    while(carrier != NULL && carrier->next != L->current)
    {
        carrier = carrier->next;
    }
    termen *toadd = new termen;
    toadd->info = value;
    toadd->next = L->current;
    carrier->next = toadd;
    L->length++;
    return L;
}
lista *addright(lista *L,int value)
{
    if (isempty(L))  {
                    element *new_one=new element;
                    if (new_one!=NULL)
                       {
                        new_one->info=value;
                        new_one->next=NULL;
                        L->length++;
                        L->start=L->current=L->finalist=new_one;
                       }
                    return L;
                  }
    else if(L->current == L->finalist)
    {
        element *new_one = new element;
        if(new_one != NULL)
        {
            new_one->info = value;
            new_one->next = L->current->next;
            L->current->next = new_one;
            L->length++;
        }
        return L;
    }
element *new_one=new element;
if (new_one!=NULL) { new_one->info=value;
                     new_one->next=L->current->next;
                     L->length++;
                     L->current->next=new_one;
                  }
return L;
}
int searchvalue(lista **L,int value)
{
termen *carrier;
carrier=(*L)->start;
while ((carrier!=NULL)&&(carrier->info!=value)) { carrier=carrier->next;}
if (carrier==NULL) { return 0;}
(*L)->current=carrier;
return 1;
}

int showmeplease(lista *L)
{cout<<endl;
if(isempty(L))
{
    cout<<"Lista vida..."<<endl;
    return 0;
}
termen *carrier = new termen;
carrier=L->start;
int counter=L->length;
while (counter>0) { cout<<carrier->info<<" "; carrier=carrier->next;
                     counter--; }
}

int main()
{
L=initlist();
showmeplease(L);

}

// 1. addright
// 2. addleft
// 3. delrigth
// 4. delleft
