/* 4- Nas aulas foram demonstrados alguns exemplos de chamadas de sistema em ambiente
Linux, então, escreva um programa em linguagem C que permita copiar o conteúdo de um
arquivo e gerar um novo arquivo. Este programa deve primeiramente solicitar ao usuário o nome
dos arquivos de origem e destino. Certifique-se de incluir todos os erros necessários verificação,
incluindo a garantia de que o arquivo fonte exista. Uma vez que você tenha projetado e testado
corretamente o programa, se você usou um SO que o suporta, execute o programa usando um
utilitário que monitore o sistema e mostre as chamadas de sistema. Os sistemas Linux fornecem
o utilitário strace. Exemplo em Linux: strace ./CopiaArquivo – CopiaArquivo é o nome do
executável. Como os sistemas Windows não fornecem tal ferramenta, você terá que rastrear
através da versão Windows deste programa usando um debug. */

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

    // ler origem
    char *result;
    int i=0; 
    while(!feof(origem)) {
        // feof - end of file 
        result = fgets(buffer, 100, origem); 
        if(result){
            // se foi possivel ler
            fprintf(destino, "%s", buffer); // printa o que foi lido para o arquivo de destino
            i++;
        }
    }

    fclose(origem);
    fclose(destino);

    return 0;
}