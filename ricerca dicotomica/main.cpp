/*
 * RICERCA DICOTOMICA
 * --> vedi classroom
 */



#define DIM 1500
#define RANGE 250
#define RICERCHE 100000  //numero di richerche per la piccola statiste

#include <iostream>
#include <string>
#include <time.h>
using namespace std;

void stampaVettore(int d, int w[], string commento );

int ricercaElemento(int d, int w[], int elemento);


int main() {
    cout <<"\nRICERCA DICOTOMICA";
    int v[DIM];
    int n =0; //è l'elemnto che deve essere inserito randomico
    int elemento ; //elemnto da cercare
    int passi=0; //numero di passi (if)

    //caricamento random del vettore
    srand(time (NULL));
    for(int i=0; i<DIM; i++)
        v[i]= 1+rand()%RANGE; //con questa funzione andiamo da 1 a RANGE compreso estremi


    stampaVettore(DIM, v, "Vettore Originale ");
    int somma=0;

    for (int k=1;  k<=RICERCHE; k++){//non parte da zero

        elemento= 1+rand()%RANGE;
        passi= ricercaElemento(DIM,v, elemento);
        somma+=passi;

        cout <<"\n"<< k<<") n.passi="<<passi;
        /* SECONDA VERSIONE
         * L'elemento da cercare no c'è mai perchè il range è troppo alto che la probabilà di cercare quel numero
         * è molto bassa DUNQUE PER AUMENTARE SI DEVE far che il numero di range e ricerche
         * siamo uguali
         */

    }
    cout <<"\n\nMedia dei passi eseguiti ="<< (float)somma/RICERCHE;

    /* NELLA PRIMA VERSIONE
    per il momento pensa che il valore ci sia all'interno dunque bisogna
    cercare qualche numero che è già presente, e l
    unica funzione è quella di vedere in quanto tempo si trova il num*/



    return 0;
}

void stampaVettore(int d, int w[], string commento )
{
    cout <<"\n"<<commento<<"\n";
    for (int i=0; i<d; i++){
        cout <<w[i]<<'\t';
        if( i%25==0 && i!=0)
            cout <<"\n";
    }
}

int ricercaElemento(int d, int w[], int elemento )
{
    int p=1; //numero di passi (if)
    for (int i=0; i<d; i++){
        if(w[i]==elemento)
            return p; //elemento trovato
        else
            p++; //elemnto non è stato trovato
    }
    return p; //elemnto non esiste
}