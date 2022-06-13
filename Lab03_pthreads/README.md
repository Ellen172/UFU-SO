# Threads

## #include<pthread.h> 
Para compilar arquivos com a bilbioteca, é preciso incluir na chamada gcc: <em>gcc -o threadExemplo threadExemplo.c -pthread </em>

## pthread_create( *t, *a, rotina, arg)
- t é um ponteiro para uma variável do tipo pthread_t que conterá o identificador da thread
recém criada;
- a é um ponteiro para os atributos do thread. Os atributos são armazenados em uma
variável do tipo pthread_attr_t. Um valor NULL indica o uso de valores default. 
- rotina é o nome (ponteiro) para a rotina (função) que define o comportamento do thread.
- arg é um void * que é passado como argumento para a rotina. 

## pthread_exit(NULL);
- finaliza a thread

## pthread_join();
- garante a execução da thread