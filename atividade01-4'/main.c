#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *origem=NULL, *destino=NULL;
    char buffer[10000];
    int aux;

    printf("Digite o arquivo de origem: ");
    scanf("%s", buffer); // le o arquivo de origem em um buffer
    aux = strlen(buffer)+2; // tamanho do buffer e do caminho_origem
    char *caminho_origem = (char *)malloc(sizeof(char)*aux); // string caminho_origem com tamanho dinamico
    strcpy(caminho_origem, buffer); // copia do buffer para caminho_origem
    origem = fopen(caminho_origem, "r");    
    while(origem == NULL){ // verificar se o caminho especificado existe
        printf("Caminho não encontrado!\n");
        printf("Digite o arquivo de origem: ");
        scanf("%s", buffer); // le o arquivo de origem em um buffer
        aux = strlen(buffer)+2; // tamanho do buffer e do caminho_origem
        char *caminho_origem = (char *)malloc(sizeof(char)*aux); // string caminho_origem com tamanho dinamico
        strcpy(caminho_origem, buffer); // copia do buffer para caminho_origem
        origem = fopen(caminho_origem, "r"); 
    }

    printf("Digite o arquivo de destino: "); 
    scanf("%s", buffer); // le arquivo de destino em um buffer
    aux = strlen(buffer)+2; // define tamanho do buffer e do caminho_destino
    char *caminho_destino = (char *)malloc(sizeof(char)*aux); // cria string caminho_destino com tamanho dinamico
    strcpy(caminho_destino, buffer); // copia do buffer para caminho_destino
    destino = fopen(caminho_destino, "w"); // gera arquivo novo para copiar origem


    fclose(origem);
    fclose(destino);

    return 0;
}