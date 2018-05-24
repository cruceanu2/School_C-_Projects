#include<iostream>
using namespace std;
int n = 6;
int *C1 = new int [1000];
int nc1;
int *C2 = new int [10000];
int nc2;
int Graf[100][100] = {{0, 1, 0, 1, 0, 0},
                      {1, 0, 1, 0, 1, 1},
                      {0, 1, 0, 1, 0, 0},
                      {1, 0, 1, 0, 0, 0},
                      {0, 1, 0, 0, 0, 1},
                      {0, 1, 0, 0, 1, 0}
                     };
int Grade[100];
int Visited[100];
int Stiva[100];
int init(){
    for(int i = 0; i < 10000; i++){
        cout<<C1[i]<<" ";
    }
    cout<<endl;
    for(int i = 0; i < 100; i++){
        Stiva[i] = -1;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            Grade[i] += Graf[j][i];
        }
    }
}
int refresh(){
    for(int i = 0; i < nc2; i++){
        C2[i] = 0;
        Visited[i] = 0;
    }
    nc2 = 0;
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
    C2[a] = i;
    Grade[i]--;
    nc2++;
}
int pop(){
    Stiva[top(Stiva)-1] = -1;
}
int killAll(){
    while(top(Stiva)){
        pop();
    }
}
int insertion(int k){
    if(k < nc1){
        for(int i = 0; i < nc2; i++){
            C1[i+k+nc2-1] = C1[i+k];
        }
    }
    for(int i = 0; i < nc2; i++){
        C1[k+i] = C2[i];
    }
    nc1 += nc2;
    cout<<"C1: ";
    for(int i = 0; i < nc1; i++){
        cout<<C1[i]+1<<" ";
    }
    cout<<endl;
    cout<<"C2: ";
    for(int i = 0; i < nc2; i++){
        cout<<C2[i]+1<<" ";
    }
    cout<<endl;
}
int DFS(int node){
    push(node);
    Visited[node] = 1;
    int g;
    while(top(Stiva)){
        g = Stiva[top(Stiva)-1];
        for(int i = 0; i < n; i++){
            if(Graf[g][i] != 0 && Visited[i] != 1 && Grade[i]){
                Visited[i] = 1;
                push(i);
                Grade[i]--;
                if(Graf[i][node] == 1 && Stiva[1] != i){
                    cout<<"stiva: "<<Stiva[1]<<endl;
                    C2[top(Stiva)] = node;
                    cout<<"i: "<<i<<endl;
                    cout<<"top(Stiva): "<<top(Stiva)<<endl;
                    cout<<"node: "<<node<<endl;
                    nc2++;
                    killAll();
                }
                break;
            }
            else if(i == n-1){
                pop();
            }
        }
    }
}
int euler(){
    DFS(1);
    insertion(0);
    refresh();
    DFS(1);
    insertion(0);
    refresh();

}
int main(){
    init();
    euler();
    for(int i = 0; i < 10000; i++){
        cout<<C1[i]<<" ";
    }
    cout<<endl;
}
