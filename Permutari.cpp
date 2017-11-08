// This is something we had to do in the 10th class, but I needed that for a personal small project of mine, and I made this version, just to have as a model, and I posted it so I have a clean copy of it whatever happens
#include<iostream>
using namespace std;
int n;
struct element{
    int value;
    element *prev;
};
class Stack{
public:
    int length;
    element *top = new element;
    Stack(){
        length = 0;
        top = NULL;
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
        cout<<"Intra in factorial..."<<endl;
        int *newvalue = new int;
        *newvalue = g;
        g = 1;
        for(int i = 1; i <= *newvalue; i++){
            g *= i;
        }
        delete newvalue;
        cout<<"Iese din factorial..."<<endl;
        return g;
    }
    int show()
    {
        int *v = new int[length];
        element *morty = new element;
        morty = top;
        for(int i = 1; i <= length; i++){
            v[length - i] = morty->value;
            morty = morty->prev;
        }
        for(int i = 0; i < length; i++){
            cout<<v[i]<<" ";
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
                show();
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

};
int main(){
    Stack *mystack = new Stack;
    cout<<"Numarul elementelor: ";cin>>n;
    mystack->permutari(n);
}
