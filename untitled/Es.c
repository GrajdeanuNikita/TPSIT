#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 100 //dimensione del vettore -->  i 2 processi ciascuno DIM/2
#define RANGE 100
#define NC 25

/*
 * SCOPO: fare un bubble sort classico (1 processo) misurando
 * la complessità algoritmica del bubble
 *  1) CaricaVettore  (...) carica il vettore v di dimensione DIM in modo random
 *    stdlib.h --> rand() srand ()
 *    time.h
 *  2)StampaVettore --> stampa il vettore passato
 */

//prototipi delle funzioni

void  CaricaVettore (int w[], int dim);
void StampaVettore (int w[], int dim, char *commento);
int BubbleSort(int w , int dim);

int main () {
    printf("BUBBLE SORT NORMALE A 1 PROCESSO CON RICERCA DELLA COMPLESSITA ALGORITMICA\n");
    int v [DIM];
    // w è il parametro formale
    CaricaVettore(v, DIM);
    StampaVettore(v, DIM, "VETTORE ORIGINALE");
    int scambi = BubbleSort(v, DIM);
    StampaVettore(v,DIM, "VETTORE ORDINATO");
    printf("\n\nNumero degli scambi :%d", scambi);
    return 0;
}

//CORPI

void CaricaVettore( int w[], int dim){
    srand(time(NULL));
    for(i=0; i<dim; i++){
        w[i]=1+ rand () % RANGE;
}


void StampaVettore(int w[], int dim, char *commento ) {
    printf("\n%s\n", commento);
    for(int j = 0; j < dim; j++){
        if (1%NC==0)
            printf("\n");
        else
            printf("%j", &w[j]);

    }
}

int BubbleSort(int w , int dim){
    int conta=0;
    int tmp;
    for(i=0;i<dim; i++ ){
        for(j=i: j<dim; j++){
            if(w[i]>w[j]){
                //scambio
                tmp=w[i];
                w[i]=w[j];
                w[j]=tmp;
                conta++
            }
            return conta;
        }
    }
  }
