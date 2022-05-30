/* 5- Um interpretador de comandos também é conhecido com Shell em sistema operacional Unix
(Linux). Ele é um programa responsável por interpretar as instruções enviadas pelo usuário para
o kernel. Desenvolva um programa em linguagem C, o qual atue como um shell do sistema
Linux. Quando invocar o programa, o programa irá mostrar um prompt para receber o comando
que você quer executar. O comando "system” não deve ser usado na implementação de
nenhum outro comando que não seja o comando ls */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // ler comando 
    char comando[10000];
    scanf("%s", comando);

    // executar comando
    if(strcmp(comando, "mv"))
}