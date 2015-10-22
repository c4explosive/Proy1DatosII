#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "queue.h"
int main(void)
{
  struct queue *cola;
  int elem;

  create(&cola);
  if (vacia(cola)) printf("\nCola vacia!");
  encolar(&cola, 3);
  //desencolar(&cola, &elem);
  displayq(cola);
  return 0;
}
