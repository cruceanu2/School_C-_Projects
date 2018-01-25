#include<iostream>
#include<string.h>
using namespace std;
char text[1000];
int litere, cifre, caractere_speciale;
int main(){
    cout<<"Text: ";cin.getline(text, 1000);
    for(int i = 0; i< strlen(text); i++){
        if(text[i] > 47 && text[i] < 58){
            cifre++;
        }
        else if((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123)){
            litere++;
        }
        else{
            caractere_speciale++;
        }
    }
    cout<<"Litere: "<<litere<<endl<<"Cifre: "<<cifre<<endl<<"Caractere speciale: "<<caractere_speciale;
}
