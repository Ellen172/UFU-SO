/*
 Quantos processos serão criados?
*/ 


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int pid = fork();
  sleep(10);
  
  if(pid == 0){
     fork();
     sleep(5);
     fork();
     sleep(5);
  }

  printf("PID = %d\n", getpid());
 
  return 0;
} 
