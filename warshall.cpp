#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
bool Graf[100][100], CanDo[100][100];
int read_data(){
    FILE *f;
    f = fopen("input.dat", "r");
    fscanf(f, "%i", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fscanf(f, "%i", &Graf[i][j]);
        }
    }
}
int write_data(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<Graf[i][j]<<" ";
        }
        cout<<endl;
    }
}
int roywarshall(){
    /*

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(Graf[i][j] == 1){
                CanDo[i][j] = 1;
            }
            for(int k = i; k >= 0; k--){
                if(CanDo[i][j]){
                    CanDo[k][i] = 1;
                }
            }
        }
    }

*/
    for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                for (int k=0; k<n; k++){
                        Graf[i][k] = max(Graf[i][k], Graf[j][k]);
                }
            }

    }
}
int main(){
read_data();
roywarshall();
write_data();

}
