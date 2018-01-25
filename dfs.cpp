#include<iostream>
#include<stdio.h>
using namespace std;

int * m;
int n;
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
}
int main(){
  init();
  
}
