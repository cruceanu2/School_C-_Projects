#include<iostream>
using namespace std;
typedef struct termen{
    int value;
    termen * next, * prev;
    };
class  List { //Asta e clasa de baza din care deriva toate celelalte
public:
    int length;
    termen *start, *current, *finalist;
    void write() {
        cout << "List" << endl;
    }
protected:
private:
};

/*
ierarhia vine asa:

List -|-public:Simple-|public SLIFO
      |               |private SFIFO
      |               |protected SFREE
      |
      |-public:Double-|public DLIFO
                      |provate DFIFO
                      |protected DFREE

tre sa folosim denumirile astea pt ca o sa folosim ierarhia asta
pentru listele folosite in programele anterioare

termenii public, private si protected inseamna diferite
chestii in functie de unde is folositi:

-in interiorul unui clase: variabilele si metodele (functiile)
 declarate cu unul din termenii astia dicteaza vizibilitatea
 acelor date din exterior (adica daca poti sa o folosesti sau nu
 IN AFARA clasei); public inseamna acces liber, private inseamna
 numai din clasa si protected e cam la fel ca la private, numai ca
 poti accesa ce e protected si din clasele derivate

-la declararea unei clase derivate din alta clasa: determina
 cum se schimba accesul la proprietatile din clasa mama

vezi aici toate combinatiile de derivare (inheritance) si modurile de acces:
https://stackoverflow.com/questions/5447498/what-are-access-specifiers-should-i-inherit-with-private-protected-or-public

tl;dr: cu programu asta vrem sa vedem combinatii de clase
derivate si variabile cu diferite moduri de acces si sa vedem
unde da erori in compiler si unde nu, cum e si in linku ala

!!!NOTA!!!
nu am inteles in totalitate schema facuta de giu in zona
declararii lui Simple si Double, nu tin minte daca trebuiau
ambele declarate public
il intreb maine pe prof si, daca trebuie schimbat ceva, acolo
unde e declarata clasa schimbi din public in ce trebuie si testezi
pe obiectele modificate in main ce merge si ce nu merge, uitandute
la erorile date la final (unde zice plain text ce are, nu te lua dupa
dreptunghiul ala rosu, arata aiurea cateodata)

eventual imi dai mesaj daca e ceva si iti dau eu versiunea buna
*/

class Simple: public List {
public:
    void writemore() {
        cout << "Simple" << endl;
    }
protected:
private:
};

class Double: public List {
public:
    void writemore() {
        cout << "Double" << endl;
    }
protected:
private:
};

class SLIFO: public Simple {
public:
    int push(int newvalue)
    {
        if(length == 0)
        {
            termen *morty = new termen;
            morty->value = newvalue;
            start = finalist = morty;
            return 0;
        }
        termen *morty = new termen;
        morty->value = newvalue;
        finalist->next = morty;
        finalist->next->prev = finalist;
        finalist = finalist->next;
    }
    int pop()
    {
        if(length == 0)
        {
            return 0;
        }
        if(length == 1)
        {
            delete finalist;
            length--;
            return 0;
        }
        finalist = finalist->prev;
        delete finalist->next;


    }
    void writelast() {
        cout << "SLIFO" << endl;
    }
protected:
private:
};

class SFIFO: protected Simple {
public:
    void writelast() {
        cout << "SFIFO" << endl;
    }
protected:
private:
};

class SFREE: private Simple {
public:
    void writelast() {
        cout << "SFREE" << endl;
    }
protected:
private:
};

class DLIFO: public Double {
public:
    void writelast() {
        cout << "DLIFO" << endl;
    }
protected:
private:
};

class DFIFO: protected Double {
public:
    void writelast() {
        cout << "DFIFO" << endl;
    }
protected:
private:
};

class DFREE: private Double {
public:
    void writelast() {
        cout << "DFREE" << endl;
    }
protected:
private:
};

int main() {
}
