/*
 * O que ser� que vai acontecer quando a mem�ria acabar? 
 */

#include <stdlib.h>
#include <stdio.h>

int main() {
  int *s1;

  do {
    s1 = (int *) malloc (sizeof(int) * 100000);
    printf ("%p\n", (void*) s1);
  } while (s1 != 0);

  return 0;
}
