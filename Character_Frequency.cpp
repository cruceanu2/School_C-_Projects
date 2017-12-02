#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char text[250];
struct Dictionar{
    int frequency;
    char letter;
}alphabet[26];
int set_alphabet(){
    for(int i = 0; i < 26; i++){
        alphabet[i].letter = i + 97;
    }
}
int check_frequency(){
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < strlen(text); j++){
            if((text[j] == alphabet[i].letter) || (text[j] == alphabet[i].letter -32)){
                alphabet[i].frequency++;
            }
        }
    }
}
int show(){
    for(int i = 0; i < 26; i++){
        if(alphabet[i].frequency != 0){
            cout<<alphabet[i].letter<<"  --->  "<<alphabet[i].frequency<<endl;
        }
    }
}
int sort_alphabet(){
Dictionar swap_space;
    for(int i = 25; i >= 2; i--){
        for(int j = 0; j <= i-1; j++){
            if(alphabet[j].frequency > alphabet[j+1].frequency){
                swap_space = alphabet[j];
                alphabet[j] = alphabet[j+1];
                alphabet[j+1] = swap_space;
            }
        }
    }
}
int main()
{
    cout<<"Introduceti textul: ";cin.getline(text, 250);
    set_alphabet();
    check_frequency();
    show();
    cout<<"Sorted: "<<endl;
    sort_alphabet();
    show();
}
