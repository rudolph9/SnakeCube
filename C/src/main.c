#include <stdlib.h>
#include "snake_cube.h"


void initialize( int argc, char *argv[], cube_t **cube, position_t **position) {
  *cube = (cube_t *)malloc( sizeof( cube_t));
  (*cube)->x = (unsigned int)strtol(argv[1], (char **)NULL, 10);
  (*cube)->y = (unsigned int)strtol(argv[2], (char **)NULL, 10);
  (*cube)->z = (unsigned int)strtol(argv[3], (char **)NULL, 10);
  (*cube)->total_blocks = (*cube)->x * (*cube)->y * (*cube)->z;
  (*cube)->blocks_traveled = 1;
  *position = (position_t *)malloc( sizeof( position_t));
  (*position)->x = 1;
  (*position)->y = 1;
  (*position)->z = 1;
  (*position)->d = 1;
  (*position)->prev = NULL;
}
/* $ snake_cube x y z binary_string */
int main (int argc, char *argv[]) {
  cube_t *cube;
  position_t *position;
  initialize( argc, argv, &cube, &position);

  snake_valid( cube, position, argv[4]);

  
  return 0;
}
