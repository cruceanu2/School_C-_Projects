#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
char text[250];
struct Dictionar{
    int frequency;
    char letter;
}alphabet[26];
struct arbore{
    int frequency;
    char letter;
    arbore *stanga, *dreapta;
};
//arbore *my_arbore;
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
int set_arbore(arbore *my_arbore){
    cout<<"Intra in set_arbore()..."<<endl;
    my_arbore->dreapta->frequency = alphabet[0].frequency;
    cout<<"A setat frecventa pe dreapta"<<endl;
    my_arbore->dreapta->letter = alphabet[0].letter;
    cout<<"A setat litera pe dreapta"<<endl;
    my_arbore->stanga->frequency = alphabet[1].frequency;
    cout<<"A setat frecventa pe stanga"<<endl;
    my_arbore->stanga->letter = alphabet[1].letter;
    cout<<"Asetat litera pe stanga"<<endl;
    my_arbore->frequency = my_arbore->dreapta->frequency + my_arbore->stanga->frequency;
    cout<<"Intra in loop..."<<endl;
    for(int i = 2; i < 26; i++){
        arbore *morty = new arbore;
        morty->dreapta = my_arbore;
        morty->stanga->frequency = alphabet[i].frequency;
        morty->stanga->letter = alphabet[i].letter;
        my_arbore = morty;
        my_arbore->frequency = my_arbore->dreapta->frequency + my_arbore->stanga->frequency;
    }
    cout<<"Iese din set_arbore()..."<<endl;
}
int show_arbore(arbore * my_arbore){
    arbore *togothrough = new arbore;
    togothrough = my_arbore;
    int g = 0;
    int i = 0;
    while(togothrough->dreapta != NULL){
            i = 0;
        cout<<togothrough->stanga->letter<<endl<<"|";
        while(i != g){
            cout<<" ";
        i++;
        }
        cout<<"\ "<<endl;
        g++;
        i = 0;
        while(i != g){
            cout<<" ";
        }
        cout<<togothrough->dreapta->letter<<endl;
        g++;
    }
}
int main()
{
    arbore *my_arbore;
    cout<<"Introduceti textul: ";cin.getline(text, 250);
    set_alphabet();
    check_frequency();
    show();
    cout<<"Sorted: "<<endl;
    sort_alphabet();
    show();
    set_arbore(my_arbore);
    show_arbore(my_arbore);
}
