#include<iostream>
using namespace std;
typedef struct element {
  int info;
    struct element *next, *prev;
}termen;
class doublelist {
private:
    int length;
    element *start, *current, *finalist;
public:
    int delLIFO(int *oldtop)
    {
        if(length != 0)
        {
            current = finalist->prev;
            finalist = NULL;
            finalist = current;
            current->next = NULL;
            return 0;
        }
        finalist = NULL;
    }
    int printLIST(int direction)
    {
        //direction = 1 -> stanga la dreapta; direction = 0 -> dreapta la stanga;
        return 0;
    }
    doublelist() {   // constructor explicit fara parametrii (nu are tip intors si este functie cu numele clasei
        length = 0;
    }
    int showlength()
    {
        cout<<endl;
        return length;
    }
    int addLIFO(int thisvalue)
    {
        element *toadd = new element;
        toadd->info = thisvalue;
        if(length == 0)
        {
            start = toadd;
            start = current = finalist;
            length++;
        }
        else{
            finalist->next->prev = finalist;
            finalist = finalist->next;
            finalist = toadd;
            length++;
        }
        return 0;
    }

protected:

}somelist; //instantiez un reprezentant al clasei doublelist numit somelist, initializat prin constructor explicit fara parametrii
/* metodele unui obiect sunt functii care pot fi apelate
 (din exterior cele cu nivel de acces public, din interior cele de nivel de acces private, protected)
 sunt si metode speciale de tipul unor evenimente
 adica este vorba de functii care se apeleaza automat intr-un anumit context (declansatoare, triggers)
 din clasa metodelor speciale fac parte constructorii si destructorii
 o declaratie a unui obiect de tipul
 clasa nume_clasa
 {
    corp descriptiv..
  };
  se comporta precum in situatia declararii unui tip propriu (typedef)
  adica numele clasei descrise poate fi utilizat ulterior pentru a "declara obiecte"
  in momentul executiei unei secvente de cod
  nume_clasa nume;
  spunem ca se instantiaza un obiect identificat prin "nume", reprezentant al clasei "nume_clasa"
  "Instantierea" inseamna ca nu este vorba doar de alocare, ci si de initializari de practicat in spatiul alocat pe zona proprietatilor (datelor, valorilorexplicite)
  Aceste "si initializari" se pot executa automat sau explicit prin intermediul executiei unor functii care ruleaza automat in momentul instantierii unui obiect
  Aceste functii sunt constructorii;
  La orice instantiere
  nume_clasa se apeleaza si constructorul
  Acesta poate fi :
  1. Cel implicit
  2. Unul din cei expliciti (constructorii pot fi polimorfici)

*/
 doublelist another_one;
int main() {
    for(int i = 1; i < 11; i++)
    {
        somelist.addLIFO(i);
        cout<<somelist.showlength();
    }
}
