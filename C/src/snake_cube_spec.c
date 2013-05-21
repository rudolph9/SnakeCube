#include <stdlib.h>
#include <assert.h>
#include "snake_cube.h"

void initialize( int coords[], cube_t **cube, position_t **position) {
  *cube = (cube_t *)malloc( sizeof( cube_t));
  (*cube)->x = coords[0];
  (*cube)->y = coords[1];
  (*cube)->z = coords[2];
  (*cube)->total_blocks = (*cube)->x * (*cube)->y * (*cube)->z;
  (*cube)->blocks_traveled = 1;
  *position = (position_t *)malloc( sizeof( position_t));
  (*position)->x = 1;
  (*position)->y = 1;
  (*position)->z = 1;
  (*position)->d = 1;
  (*position)->prev = NULL;
}

int main (int argc, char *argv[]) {
  cube_t *cube;
  position_t *position;
  int coords[3] = {3, 3, 3};
  initialize( coords, &cube, &position);
  char * binary_string = "010101010101010";
  assert( snake_valid( cube, position, "010101010101010") == false);
  
  return 0;
}

