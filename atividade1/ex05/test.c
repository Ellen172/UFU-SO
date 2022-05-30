#include <stdio.h>
#include <string.h>

int main() {
    char frutas[] = "banana,laranja,morango";
    int tamanho = strlen(frutas); //isto funciona só para delimitador de 1 caractere
    char *token = strtok(frutas, ",");
    
    for (int i = 0; i < tamanho; i++) 
        printf(token[i] == 0 ? "\\n" : "%c", token[i]);
    /*
    while(token != NULL) {
        printf("\n%s", token);
        token = strtok(NULL, ",");
    }
    */
    return 0;
}