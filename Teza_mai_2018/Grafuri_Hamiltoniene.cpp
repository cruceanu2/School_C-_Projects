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
int refresh(){
    for(int i = 0; i < n; i++){
        Visited[i] = 0;
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
                Visited[i] = 1;
                push(i);
                if(top(Stiva) == n){
                    return 1;
                }
                break;
            }
            else if(i == n-1){
                pop();
            }
        }
    }
    return 0;
}
int main(){
    init();
    for(int i = 0; i < n; i++){
        push(i);
        Visited[i] = 1;
        if(DFS()){
            cout<<"Graful este Hamiltonian!"<<endl;
            return 0;
        }
        refresh();
    }
    cout<<"Graful nu este Hamiltonian.."<<endl;
}
