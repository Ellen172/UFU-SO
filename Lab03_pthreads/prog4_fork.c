#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define NTHREADS 50000


int main(int argc, char *argv[]) {
    
    pid_t pid; 

    pid = fork();
    
    for (int j=0; j<NTHREADS; j++) {
        if(pid==0) pid = fork();
    }

    return 0;

}