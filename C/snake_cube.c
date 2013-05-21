/* TODO:
 * refractor block_g out as a global
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct position_t {
  unsigned int x;
  unsigned int y;
  unsigned int z;
  int d;
  struct position_t *prev;
}position_t;

typedef struct {
  unsigned int x;
  unsigned int y;
  unsigned int z;
  unsigned int total_blocks;
  unsigned int blocks_traveled;
} cube_t;

/*
bool positions_equal( position_t * position_a , position_t * position_b) { 
  return true;
}
*/  
/*
bool position_valid( position_t **positions, posisition_t *position) {
  
  return false/*
  int i;
  for( i = 0; i < cube_g->blocks_traveled; i++) {
    if( positions_equal( positions[i], positionl)) {
      return false;
    } }
  return true;*/
//}

bool snake_valid( cube_t *cube, position_t *position, char *binary_string);
bool snake_valid( cube_t *cube, position_t *position, char *binary_string) {
  if( strlen( binary_string) == 1) {
    printf( "%c!\n", binary_string[0] );
    return true;
  }

  if( binary_string[0] == '0') {
    printf( "%c", binary_string[0] );
    snake_valid( cube, position, binary_string + 1);
  }
  else {
    printf( "%c", binary_string[0] );
    snake_valid( cube, position, binary_string + 1);
  }
    
}

void initialize( int argc, char *argv[], cube_t *cube, position_t * position) {
  cube = (cube_t *)malloc( sizeof( cube_t));
  cube->x = (unsigned int)strtol(argv[1], (char **)NULL, 10);
  cube->y = (unsigned int)strtol(argv[2], (char **)NULL, 10);
  cube->z = (unsigned int)strtol(argv[3], (char **)NULL, 10);
  cube->total_blocks = cube->x * cube->y * cube->z;
  cube->blocks_traveled = 1;
  position = (position_t *)malloc( sizeof( position_t));
  position->x = 1;
  position->y = 1;
  position->z = 1;
  position->d = 1;
  position->prev = NULL;
}

void free_positions( position_t ** positions) {
  free( (positions)[0]); (positions)[0] = NULL;
  free( positions); positions = NULL;
}

/* $ snake_cube x y z binary_string */
int main (int argc, char *argv[]) {
  cube_t *cube;
  position_t * position;
  initialize( argc, argv, cube, position);

  snake_valid( cube, position, argv[4]);

  
  return 0;
}

