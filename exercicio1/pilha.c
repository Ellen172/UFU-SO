/*
 * Corrompendo a pilha de execução.
 */
#include <stdio.h>

void f() {
  int *v[2];
  int i;

  for (i = 0; i < 16; i++){
    v[i] = &i;
    printf("v = %d\n", &v[i]);
  }
}

int main() {
  f();
  return 0;
}

