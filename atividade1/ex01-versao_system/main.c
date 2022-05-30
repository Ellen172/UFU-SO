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
    char buffer[10000], command[100];
    int aux;

    // criar strings com caminhos dos arquivos

    // le o caminho_origem em um buffer
    printf("Digite o caminho do arquivo de origem: "); 
    scanf("%s", buffer); 
    // salvar caminho_origem
    aux = strlen(buffer)+2;
    char caminho_origem[aux]; 
    strcpy(caminho_origem, buffer); 

    // le o arquivo de destino em  um buffer
    printf("Digite o caminho do arquivo de destino: "); 
    scanf("%s", buffer); 
    //salvar caminho_destino
    aux = strlen(buffer)+2;
    char caminho_destino[aux];
    strcpy(caminho_destino, buffer); 

    /*
    char caminho_origem[10000], caminho_destino[10000];
    strcpy(caminho_origem, "/home/ellen/Documentos/UFU-SO/atividade01.4-system/arquivo-origem");
    strcpy(caminho_destino, "/home/ellen/Documentos/UFU-SO/atividade01.4-system/arquivo-destino");
    */

    // criar comando
    strcpy(command, "cp ");
    strcat(command, caminho_origem);
    strcat(command, " "); 
    strcat(command, caminho_destino);

    // executar chamada de comando
    system(command);

    return 0;
}