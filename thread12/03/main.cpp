#include <iostream>
#define NBYTE 8
#define MAXBYTE 100
#define PATCH C:\Utenti\9698080\Download\pippo.txt
#include <iostream>
#include <fstream>
#include <list>
#include <string.h>

using namespace std;

void DES_encode(char input[], char output[], char key[]); //cripta
void DES_decode(char input[], char output[], char key[]);
void leggiFile(string nomefile);

void leggiLista(list<parola> l)


list<parola> list1;
list<parola> list1;


struct parola {
    char p[NBYTE];  //parola.p
};


int main() {
    string nf;
    cout<< "\nInserire il nome dle file:";
    cin>>nf;
    leggiFile(nf);

    cout <<"\nNumero di parole inserite: "<<list1.size();
    return 0;
}


void DES_encode(char input[], char output[], char key[]){
    for(int i=0; i<NBYTE; i++)
        output[i]=input[i]^key[i];
    output[i]='\0';
    return;
}

void leggiFile(string nomefile){
    ifstream file;
    parola p1;
    file.open(PATH+nomefile);
    if(!file){
        cout<<"\nPROBLEMI DI APERTURA DEL FILE";
        return -1;

    }

    //se siamo qui il file originale si è aperto
    char c ; //vyte elementare
    int conta=0;

    while (!file.eof()){
        /* funzionerà sempre questo metodo perchè prenderà
        èsempre leggerà sempre un carattere al colpo e mette dentro
        la p della struttura il carattere letto(è un vettore di array
        torna su legge il terzo arrivando a 8 che resetta la variabile
        conta, e mette in push back la struttura +1, la get nel file da sola
         legge e si sposta in modo autonomo, non siamo noi che
         dobbiamo avanzare nel file.
         */
        c=file.get();
        p1.p[conta]=c;
        conta++;
        if (conta==NBYTE){
            conta=0;
            list1.push_back(p1);
        }
    }
    file.close();

}

void leggiLista(list<parola> l ){
    //variabiele clocale
    char tmpParola[NBYTE+1];

    list<parola>:: iterator it;

    for(....sulla lista l)
}