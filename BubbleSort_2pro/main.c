#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // gestisce il wait , fork ...
#include <sys/wait.h>

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

//prototipi delle fun
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// zioni

void  CaricaVettore (int w[], int dim);
void StampaVettore (int w[], int dim, char *commento);
int BubbleSort(int w[] , int dim);

int main () {
    int v[DIM];
    int v1[DIM/2] ; //padre
    int v2[DIM/2]; //figlio

    CaricaVettore(v, DIM);
    StampaVettore(v, DIM, "VETTORE ORIGINALE");

    //SPEZZO IN DUE IL VETTORE V
    for(int i=0; i<DIM/2; i++)
        v1[i]=v[i]; //parte inferiore del vettore
    for(int i=DIM/2, j=0; i<DIM; i++)
        v2[j]=v[i]; //parte superiore del vettore

    //GENERAZIONE DEI DUE PROCESSI
    int id=fork();
    if(id==0){
        //SIAMO NEL FIGLIO
        printf("sono il figlio");
        int scambi_figlio= BubbleSort(v2, DIM/2);
        StampaVettore(v2, DIM/2, "VETTORE ORDINATO DAL FIGLIO");
        printf("\n\nScambi effetuati dal figlio : %d", scambi_figlio);
    }else{
        //SIAMO NEL PADRE
        printf("sono il padre");
        int scambi_padre= BubbleSort(v1, DIM/2);
        StampaVettore(v1, DIM/2, "VETTORE ORDINATO DAL PADRE");
        printf("\n\nScambi effetuati dal padre : %d", scambi_padre);
        wait(NULL);
    }

    printf("PROGRAMMA PER IL BUBBLE SORT CON 2 PROCESSI\n");
    return 0;
}

//CORPI

void CaricaVettore( int w[], int dim){
    srand(time(NULL));
    for(int i=0; i<dim; i++)
        w[i]=1+rand()%RANGE;
}


void StampaVettore(int w[], int dim, char *commento ) {
    printf("\n%s\n", commento);
    for(int j = 0; j < dim; j++)
        if (j%NC==0)
            printf("\n");
        else
            printf("%j", &w[j]);


}

int BubbleSort(int w , int dim)
    int conta=0;
    int tmp;
    for(i=0;i<dim; i++ ){
        for(j=i: j<dim; j++){
            if(w[i]>w[j]){
                //scambio
                tmp=w[i];
                w[i]=w[j];
                w[j]=tmp;
                conta++;
            }
            return conta;
        }
    }
