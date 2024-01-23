#include <stdio.h>
#include <stdlib.h>


int main() {

    int liv;
    int id;

    printf("Inserire quanti livelli vuoi:");
    scanf("%i", &liv);

    for(int i=0; i<liv; i++)
    {
        id=fork();
        if(id>=0)
            //per assicurarci che sia maggiore o uguale a 0
            if(id==0)
                printf("Sono il processo padre");
            if(id>0)
                printf("Sono il processo figlio");
    }
        return 0;
}