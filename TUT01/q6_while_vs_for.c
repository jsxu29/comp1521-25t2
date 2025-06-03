/*
How could we rewrite the above program using a for loop? What subtle difference would there be between the two programs?
*/

#include <stdio.h>

int main(void) {
  int i = 0;
  while (i < 10) {
    printf("%d\n", i);
    i++;
  }
  return 0;
}
