#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    int pipe_fd[2];
    int n;

    if (pipe(pipe_fd) == -1) {
        perror("errore");
        exit(1);
    }
    pid_t fd = fork();

    if (fd == -1) {
        perror("errore");
        exit(2);
    }



    if (fd == 0) {
        close(pipe_fd[1]);
        int received_array[10];
        read(pipe_fd[0], received_array, sizeof(received_array));
        for (int i = 0; i < n; i++) {
            printf("%d", received_array[i]);
        }
        printf("\n");

        close(pipe_fd[0]);
    }else{
        close(pipe_fd[0]);

        int array[10];
        printf("Quanti dati vuoi passare?");
        for(int i=0; i<n; i++){
            scanf("%d", &array[i]);
        }
    }
    write(pipe_fd[1], array, sizeof(array));
    close(pipe_fd[1]);

    wait(NULL);
    return 0;
}
