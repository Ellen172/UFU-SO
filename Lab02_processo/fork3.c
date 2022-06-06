#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int value = 20;

int main()
{
   pid_t pid;
   pid = fork();
	
   if (pid == 0) { /*Processo Filho*/
       printf("\n filho: %d \n", (int) getpid()); 
       value += 15;
       printf("value filho: %d\n", value);
       return(0);

    }
    else if (pid > 0) { /* Processo Pai */
      
	wait(NULL);
        printf("\n Pai: %d \n", (int) getpid()); 
	
       	printf("value pai: %d\n", value);
	return(0);
    }
}
