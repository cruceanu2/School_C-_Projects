#include<iostream>
using namespace std;
int n = 5;
int Graf[5][5] = {{0, 1, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 0, 1, 1},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0}};
/*
    1-2-3-4
        |
        5
*/
int Visited[100];
int Stiva[100];
int init(){
    for(int i = 0; i < 100; i++){
        Stiva[i] = -1;
    }
}
int top(int S[]){
    int a = 0;
    while(S[a] != -1){
        a++;
    }
    return a;
}
int push(int i){
    int a = top(Stiva);
    Stiva[a] = i;
    Visited[i] = 1;
}
int pop(){
    Stiva[top(Stiva)-1] = -1;
}
int DFS(){
    int g;
    while(top(Stiva)){
        g = Stiva[top(Stiva)-1];
        for(int i = g; i < n; i++){
            if(Graf[g][i] != 0 && Visited[i] != 1){
                push(i);
                break;
            }
            else if(i == n-1){
                pop();
            }
        }
    }
}
int isConex(){
    DFS();
    int a = 0;
    for(int i = 0; i < n; i++){
        a += Visited[i];
    }
    if(a == 1){
        cout<<"Graful are o componenta conexa";
        return 0;
    }
    cout<<"Graful are "<<a<<" componente conexe";
}
int main(){
    init();
    push(0);
    isConex();
}
