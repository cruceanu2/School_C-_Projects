#include<iostream>
using namespace std;
int n = 5;
int Graf[5][5] = {{0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0}};
/*
    1-2-3-4
        |
        5
*/
int Visited[100];
int Stiva[100][2];
int init(){
    for(int i = 0; i < 100; i++){
        Stiva[i][0] = -1;
        Stiva[i][1] = 0;
    }
}
int top(int S[100][2]){
    int a = 0;
    while(S[a][0] != -1){
        a++;
    }
    return a;
}
int push(int i){
    int a = top(Stiva);
    Stiva[a][0] = i;
}
int pop(){
    Stiva[top(Stiva)-1][0] = -1;
}
int DFS(){
    int g;
    int h;
    while(top(Stiva)){
        g = Stiva[top(Stiva)-1][0];
        h = Stiva[top(Stiva) - 1][1];
        for(h; h <= n; h++){
            if(Graf[g][h] != 0 && h < n){
                if(Visited[h] == 1){
                    cout<<"Graful este ciclic..";
                    return 0;
                }
                Stiva[top(Stiva) - 1][1] = h+1;
                Visited[h] = 1;
                push(h);
                break;
            }
            if(h >= n-1 ){
                pop();
            }
        }
    }
    cout<<"Graful este aciclic!";
}
int main(){
    init();
    push(0);
    DFS();
}
