#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    printf("Eu sou o processo %d\n",getpid());

    pid = fork(); //criação do filho 

    if (pid < 0){
        printf("Erro na criação do filho!\n");
    }

    else if(pid == 0){ 
        /* processo filho */
        printf("Eu sou o processo filho %d\n", getpid());
        exit(0); //finaliza processo
    }

    else {
        /* de volta para o processo pai */
        sleep(10); //aguardando execução do filho que já encerrou
        printf("Fim do processo!\n");
        return 0;
    }

    return 0;
}