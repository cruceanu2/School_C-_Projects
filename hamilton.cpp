#include<iostream>
#include<stdio.h>
using namespace std;
int *m;
int n;
bool state = 1;
struct Stack{
    int value;
    Stack *prev;
};
struct List{
    int length = 0;
    Stack *start, *finish;
};
List *mystack = new List;
bool is_valid_option(int i){
    Stack *morty = new Stack;
    morty = mystack->finish;
    while(morty != mystack->start->prev){
        if(morty->value == i){
            return 0;
        }
        morty = morty->prev;
    }
    cout<<"a ajuns pana aici, ramane de vazut cum merge..."<<endl;
    morty = morty->prev;
    delete morty;
    cout<<"hai mai ca a mers"<<endl;
    return 1;
}
void Read(){
    FILE *f;
    f = fopen("hamilton.dat", "r");
    fscanf(f, "%i", &n);
    m = new int[n * n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%i ", &m[n*i + j]);
        }
    }
}
void push(int i){
    Stack *morty = new Stack;
    morty->value = i;
    if(mystack->length == 0){
        morty->prev = NULL;
    }
    else{
        morty->prev = mystack->finish;
    }
    mystack->finish = morty;
    mystack->length++;
}
void dfs(int value){
    if(state == 0){
        return;
    }
    for(int i = 0; i < n; i++){
        if(mystack->length == n){
            cout<<"Este hamiltonian: "<<endl;
            Stack *morty = new Stack;
            morty = mystack->finish;
            while(morty != mystack->start->prev){
                cout<<morty->value<<" - ";
                mystack = mystack->prev;
            }
            state = 0;
        }
    }
}
int main(){
    //Stack *mystack = new Stack;
    cout<<mystack->length;
    Read();
    for(int i = 0; i < n; i++){
        push(i);
        //dfs(i);
    }
}
