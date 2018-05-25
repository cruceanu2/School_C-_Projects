#include<iostream>
#include<stdio.h>
using namespace std;
int n;
int Graf[100][100];
int Stiva[100];
int Visited[100];
int read(){
    FILE *f;
    f = fopen("input.dat", "r");
    fscanf(f, "%i", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%i", &Graf[i][j]);
        }
    }
    //cout<<"iese din citire..."<<endl;
    fclose(f);
    return 0;
}
int init(){
    for(int i = 0; i < 100; i++){
        Stiva[i] = -1;
    }
}
int getTop(int S[]){
    //cout<<"intra in getTop()..."<<endl;
    int a = 0;
    while(S[a] != -1){
        a++;
    }
    //cout<<"iese din getTop()..."<<endl;
    return a;
}
int push(int i){
    Stiva[getTop(Stiva)] = i;
    cout<<i+1<<" ";
    Visited[i] = 1;
}
int BFS(){
    int a;
    for(int i = 0; i < getTop(Stiva); i++){
        a = Stiva[i];
        for(int j = 0; j < n; j++){
            if(Graf[a][j] != 0 && Visited[j] == 0){
                push(j);
            }
        }
    }
}
int main(){
    read();
    init();
    push(0);
    BFS();
}
 
