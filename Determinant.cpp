#include<iostream>
using namespace std;
int n;
#define LUNGIME 9
int setN(){
    cout<<"Numarul elementelor: ";cin>>n;
}
struct element{
    int value;
    element *prev;
};
class Stack{
public:
    int length;
    int permutare[LUNGIME];
    int toate_permutarile[LUNGIME * 40320][LUNGIME];
    int Matrice[LUNGIME][LUNGIME];
    int permutare_curenta = 0;
    element *top = new element;
    Stack(){
        length = 0;
        top = NULL;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout<<"M["<<i+1<<"]["<<j+1<<"] = ";cin>>Matrice[i][j];
            }
        }
    }
    int baga_permutare(){
        element *morty = new element;
        morty = top;
        for(int i = 1; i <= n; i++){
            toate_permutarile[permutare_curenta][n - i] = morty->value;
            morty = morty->prev;
        }
        permutare_curenta++;
    }
    int push(int newvalue){
        //cout<<"Intra in push..."<<endl;
        element *morty = new element;
        morty->value = newvalue;
        morty->prev = top;
        top = morty;
        length++;
        //cout<<"Iese din push..."<<endl;
        return 0;
    }
    int pop(){
        //cout<<"Intra in pop..."<<endl;
        if(length != 0){
            element *aux = new element;
            aux = top->prev;
            delete top;
            top = aux;
            length--;
        }
        //cout<<"Iese din pop..."<<endl;
        return 0;
    }
    int check(int thisvalue){
        //cout<<"Intra in check..."<<endl;
        element *morty = new element;
        morty = top;
        if(thisvalue > n){
            return 0;
        }
        while(morty != NULL){
            if(morty->value == thisvalue){
                    //cout<<"Iese din check (nu l-a luat)..."<<endl;
                return 0;
            }
            morty = morty->prev;
        }
        //cout<<"Iese din check (l-a luat)..."<<endl;
        return 1;
    }
    int factorial(int g){
        //cout<<"Intra in factorial..."<<endl;
        int *newvalue = new int;
        *newvalue = g;
        g = 1;
        for(int i = 1; i <= *newvalue; i++){
            g *= i;
        }
        delete newvalue;
        //cout<<"Iese din factorial..."<<endl;
        return g;
    }
    int show()
    {
        for(int i = 0; i < n; i++){
            cout<<toate_permutarile[permutare_curenta - 1][i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    int permutari(int n){
        //cout<<"Cand intra in permutare: "<<length<<endl;
        int i = 1;
        int counter = 1;
        int maxcounter = factorial(n);
        while(counter <= maxcounter){
            if(i > n){
                //pop();
                i = top->value + 1;
                pop();
            }
            if(check(i)){
                    //cout<<"Da push de: "<<i<<endl;
                push(i);
                //if((i + 1 > n) && length != n){
                    i = 0;
                //}
            }
            i++;
            if(length == n){
                counter++;
                baga_permutare();
                //show();
                pop();
                if(length == 0)
                {
                    return 0;
                }
                i = top->value + 1;
                pop();
            }
        }
    }
    int inversiuni(int i){
        int semn = 1;
        for(int g = 0; g < n; g++){
            for(int j = g; j < n; j++){
                if(toate_permutarile[i][g] > toate_permutarile[i][j]){
                    semn *= -1;
                }
            }
        }
        return semn;
    }
    int calcul_determinant(){
        int long long determinant = 0;
        int long long produs = 1;
        for(int i = 0; i < factorial(n); i++){
            for(int j = 0; j < n; j++){
                produs *= Matrice[j][toate_permutarile[i][j]-1];
            }
            produs *= inversiuni(i);
            determinant += produs;
            produs = 1;
        }
        cout<<determinant<<endl;
    }
};
int main(){
    setN();
    if(n == 0){
        return 0;
    }
    Stack *mystack = new Stack;
    mystack->permutari(n);
    mystack->calcul_determinant();
}
