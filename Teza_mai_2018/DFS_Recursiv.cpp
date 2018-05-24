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
int Exclusions[100];
int DFS(int a){
    Visited[a] = 1;
    for(int i = 0; i < n; i++){
        if(Visited[i] == 1 && Exclusions[i] != 1){
            cout<<i+1<<" ";
        }
    }
    cout<<endl;
    for(int i = 0; i < n; i++){
        if(Graf[a][i] != 0 && Visited[i] != 1){
            DFS(i);
        }
    }
    Exclusions[a] = 1;
}
int main(){
    DFS(0);
}
