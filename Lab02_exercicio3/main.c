/* bibliotecas */
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

/*variavel global */
int value = 5;

int main(){
    int pid;
    pid = fork();

    if (pid == 0) { 
        /* processo filho */
        value += 15;
        printf("FILHO: valor = %d\n", value);
        return 0;
    }

    else if (pid > 0) { 
        /* processo pai */
        wait(NULL);
        printf("PAI: valor = %d\n\n",value); /* LINHA A */
    }

    return 0;
}