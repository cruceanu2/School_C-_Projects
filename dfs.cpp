#include<iostream>
#include<stdio.h>
using namespace std;
struct Element{
    int i, j, whereweleftoff;
    Element *prev;
};
struct Stiva{
    int length;
    Element *start, *finish;

};
Stiva *mystack = new Stiva;
int * m;
int n;
int push(int a, int b){
    Element *morty = new Element;
    morty->i = a;
    morty->j = b;
    if(mystack->length == 0){
        morty->prev = NULL;
        mystack->start = mystack->finish = morty;
        mystack->finish->whereweleftoff = 0;
        mystack->length = 1;
        return 0;
    }
    morty->prev = mystack->finish;
    mystack->finish = morty;
    mystack->finish->whereweleftoff = 0;
    mystack->length++;
    return 0;
}
int pop(){
    if(mystack->length == 0){
        return 0;
    }
    if(mystack->length == 1){    //notat, nu ii place == pentru verificare, da crash
        delete mystack->start;
        mystack->length = 0;
        return 0;
    }
    Element *morty = new Element;
    morty = mystack->finish->prev;
    delete mystack->finish;
    mystack->finish = morty;
    mystack->length--;
    return 0;
}
int init(){
  FILE * f;
  f = fopen("dfs.dat", "r");
  fscanf(f, "%i", &n);
  m = new int[n*n];
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      fscanf(f, "%i", &m[i*n + j]);
    }
  }
  mystack->length = 0;
  push(0,0);
  cout<<mystack->finish->i+1<<endl;
  mystack->finish->whereweleftoff = 0;
  return 0;
}
int iterative(){
    while(mystack->length != 0){
        while(mystack->finish->whereweleftoff < n){
          if(m[n*mystack->finish->j + mystack->finish->whereweleftoff] == 1){
            push(mystack->finish->whereweleftoff, mystack->finish->whereweleftoff);
            cout<<mystack->finish->i+1<<endl;
            mystack->finish->whereweleftoff = mystack->finish->j - 1;
          }
          mystack->finish->whereweleftoff++;
        }
        pop();
        if(mystack->finish != NULL){
          mystack->finish->whereweleftoff++;
        }
    }
    return 0;
}
int main(){
    init();
    iterative();
}
