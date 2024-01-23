#include <string.h>
#include <iostream>

// ci sono delle funzioni che permettono di semplificare la creazione di metodi

class Stringa{
private:
    char *_Stringa;
    int l;

public:
    Stringa(){
        l=0;
        _Stringa= new char [l+1];
        _Stringa[0]='\0';
        for(int i=0; i<l; i++){
            _Stringa[i]='\0';
        }
    }

    void set(void){
        std::cout <<" Inserisci la stinga:";
        std::cin >>_Stringa;
    }

    void stampa(){
        std::cout << "La stringa è: "<< _Stringa <<std::endl;
    }


    Stringa reverse(void){
        Stringa v;
        for(int i=l-1;i>=0; i--){
            v._Stringa[l-i-1]=_Stringa[i];
        }
        v.l=l;
        return v;
    }

    int cerca(char c){
        for (int i=0; i<l; i++){
            if(_Stringa[i]==c){
                return i;
            }
        }
        return-1;
    }

    int conta(char c){
        int contatore=0;
        for(int i=0;i<l; i++){
            if(_Stringa[i]==c){
                contatore++;
            }
        }
        return contatore;
    }



    void toUpper(){
        for(int i=0;i<l; i++){
            if(_Stringa[i]>= 'A'&& _Stringa[i]<='Z'){
                _Stringa-=32;
            }
        }
    }

    void toLower(){
        for(int i=0;i<l; i++){
            if(_Stringa[i]>= 'a'&& _Stringa[i]<='z'){
                _Stringa+=32;
            }
        }
    }

    void toFlip(){
        for(int i=0;i<l; i++){
            if(_Stringa[i]>= 'a'&& _Stringa[i]<='z'){
                _Stringa+=32;
            }else if(_Stringa[i]>= 'A'&& _Stringa[i]<='Z'){
                _Stringa-=32;
            }
        }
    }

    bool operator==(Stringa v2){
        return 0;
    }

    bool palindroma(){
        for (int i=0; i<l/2;i++){
            if(_Stringa[i] != _Stringa[l-1-i]){
                return false;
            }
        }
        return true;
    }
    /*
     * bool scritta dal professore
     * char *p1,*p2;
     * p1=s;
     * p2=&s[strlen(s)-1*];
     * while(p2>p1) {
     *   while(*p1== '')p1++;
     *   while(*p2== '')p2--;
     *   if(tolower(*p2)!=tolower(*p1))
     *      return false;
     *   p1++;
     *   p2--;
     *  }
     *  return true;
     *
     *
     */


};



int main() {
    Stringa v1, v2;

    std::cout<<"Inserisci una stringa";
    // Imposta e stampa la stringa v1
    v1.set();
    v1.stampa();

    //Converte la stringa v1 in minuscolo
    std::cout<<"Stringa in minuscolo";
    v1.toLower();
    v1.stampa();

    //converte la stringa v1 in maiuscolo
    std::cout<<"Stringa in maiuscolo";
    v1.toUpper();
    v1.stampa();

    //converte lastringa v1 in minuscolo se in maiuscolo e viceversa
    std::cout<<"Stringa in maiuscolo e minuscolo";
    v1.toFlip();
    v1.stampa();

    std::cout<<"Stringa all'incontrario";
    v1.reverse();
    v1.stampa();


    int conta_a = v1.conta('a');
    printf("Il numero di occorrenze di 'a' è: %d\n", conta_a);


    bool palindroma = v1.palindroma();
    if (palindroma) {
        printf("La stringa è palindroma\n");
    } else {
        printf("La stringa non è palindroma\n");
    }

    /* v3 = v1 + v2;
     v3.stampa();
     */

    bool uguali = v1 == v2;

    // Stampa il risultato del controllo
    if (uguali) {
        printf("Le stringhe sono uguali\n");
    } else {
        printf("Le stringhe non sono uguali\n");
    }



}



//operator non è un int
// palindroma con due puntatori
//i topi non avevano nipoti