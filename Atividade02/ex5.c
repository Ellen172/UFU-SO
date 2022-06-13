#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
estados do processo
p - pronto 
e - executando
b - bloqueado 
f - finalizado
*/

struct processo {
    char nome[5], estado;
    int cpuBurst, tinicio, tfinal;
};

int main(){

    FILE *tarefas = fopen("tarefas.txt", "r");

    if(tarefas == NULL){
        printf("Erro ao abrir o arquivo!\n");
        return 0;
    }

    struct processo prog[5];
    int i=0;
    while(!feof(tarefas)){
        //lê do arquivo
        fscanf(tarefas, "%s %d", prog[i].nome, &prog[i].cpuBurst);
        i++;
    }
    fclose(tarefas);

    for(int i=0; i<5; i++){
        prog[i].estado = 'p'; //todos iniciando em pronto
        prog[i].tinicio = -1; //todos iniciando sem tinicio definido
        prog[i].tfinal = -1; //todos iniciando sem tfinal definido

        //print de teste..
        printf("processo: %s\tcpu burst: %d\testado: %c\ttempo de inicio: %d\ttempo final: %d\n", 
            prog[i].nome, prog[i].cpuBurst, prog[i].estado, prog[i].tinicio, prog[i].tfinal);
    }

    int tipo;
    printf("Escolha o tipo de escalonamento: ");
    print("1 - FCFS \t 2 - RR (q=5)\n");
    scanf("%d", &tipo);

    while(tipo!=1 && tipo!=2){
        print("Tipo não encontrado!\n");
        printf("Escolha o tipo de escalonamento: ");
        print("1 - FCFS \t 2 - RR (q=5)\n");
        scanf("%d", &tipo);
    }

    if(tipo == 1){
        //TO DO: executar FCFS
    }
    else {
        //TO DO: executar RR (q=5)
    }

    return 0;
}