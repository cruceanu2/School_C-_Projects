#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int n;
struct Element{
    int value;
    Element *prev, *next;
};
struct List{
    int length;
    Element *start, *current, *finish;
};
List *mylist = new List;
void init(){
    //cout<<"intra in init()..."<<endl;
    mylist->start = mylist->finish = NULL;
    //cout<<"i-a setat start-ul si finish-ul"<<endl;
    //mylist->start->prev = NULL;
    //cout<<"i-a setat si pointer-ul inapoi..."<<endl;
    mylist->length = 0;
    //cout<<"iese din init()..."<<endl;
}
void push(int i){
    Element *morty = new Element;
    morty->value = i;
    if(mylist->length == 0){
        mylist->start = mylist->finish = morty;
    }
    else{
        morty->prev = mylist->finish;
        mylist->finish->next = morty;
        mylist->finish = morty;
    }
    mylist->length++;
}
void check_more_characters(){
    Element *morty = new Element;
    morty = mylist->start;
    int holder;
    while(morty != mylist->finish->next){
            if(morty == mylist->finish){
                if(morty->value > 10){
                    holder = morty->value / 10;
                    morty->value %= 10;
                    push(holder);
                    check_more_characters();
                }
            }
        if(morty->value > 10){
            holder = morty->value / 10;
            morty->value %= 10;
            morty->next->value += holder;
        }
        morty = morty->next;
    }
}
int factorial(int i){
    //cout<<"intra aici"<<endl;
    int result;
    if(mylist->length == 0){
            //cout<<"a intrat si a dat push"<<endl;
        push(1);
    }
    mylist->current = mylist->finish;
    //cout<<"a iesit din aia"<<endl;
    while(true){
        mylist->current->value *= i;
        if(mylist->current == mylist->start){
            break;
        }
        mylist->current = mylist->current->prev;
    }
    check_more_characters();
}
void Write(){
    FILE *f = fopen("factorial.out", "w");
    mylist->current = mylist->finish;
    for(int i = 0; i < mylist->length; i++){
        fprintf(f, "%i", mylist->current->value);
        mylist->current = mylist->current->prev;
    }
    /*mylist->current = mylist->start;
    while(mylist->current != mylist->finish){
        cout<<mylist->current->value;
        mylist->current = mylist->current->next;
    }*/
}
int main(int argc, char *argv[]){
    init();
    n = atoi(argv[1]);
    for(int i = 1; i <= n; i++){
        factorial(i);
    }
    Write();
}
