#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct valores {
    int qtd;
    int *vet;
};

void *media(void * argumentos) {
    struct valores *val = argumentos;

    double media = 0;
    for(int j=0; j<val->qtd; j++){
        media += val->vet[j];
    }
    media = media/val->qtd;

    printf("O valor medio e de %lf\n", media);
    pthread_exit(NULL);
}

void *maximo (void * argumentos){
    struct valores *val = argumentos;
    
    int max = 0;
    for(int j=0; j<val->qtd; j++){
        if(val->vet[j] > max) 
            max = val->vet[j];
    }

    printf("O valor maximo e %d\n", max);
    pthread_exit(NULL);
}

void *minimo (void * argumentos){
    struct valores *val = argumentos;
    
    int min=100000;
    for(int j=0; j<val->qtd; j++){
        if(val->vet[j] < min) 
            min = val->vet[j];
    }

    printf("O valor minimo e %d\n", min);
    pthread_exit(NULL);
}

int main(){
    //TODO : entrada sem qtd de valores
    struct valores val;
    int rc;

    printf("Informe a quantidade de valores: "); 
    scanf("%d",&val.qtd);

    val.vet = (int *) malloc(val.qtd*sizeof(int)); 

    for(int i = 0; i < val.qtd; i++){
        scanf("%d", &val.vet[i]);
    }

    pthread_t thread1, thread2, thread3;

    pthread_create(&thread1, NULL, media, &val);
    rc = pthread_join(thread1, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_join() is %d\n", rc);
        exit(-1);
    }

    pthread_create(&thread2, NULL, maximo, &val);
    rc = pthread_join(thread2, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_join() is %d\n", rc);
        exit(-1);
    }

    pthread_create(&thread3, NULL, minimo, &val);
    rc = pthread_join(thread3, NULL);
    if (rc) {
        printf("ERROR; return code from pthread_join() is %d\n", rc);
        exit(-1);
    }

    return 0;
}