#include <stdio.h>
#include "unistd.h"
#include "pthread.h"

void thread_function(){
    printf("\pSono il thread %i", id);
}

int main() {

    int num;
    printf("Quanti thread vuoi creare?");
    scantf("%d", &num);

    for(int i=0; i<num, i++){

    }

    return 0;
}
