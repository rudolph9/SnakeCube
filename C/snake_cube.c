#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct {
  unsigned int x;
  unsigned int y;
  unsigned int z;
  int d;
} position_t;

typedef struct {
  unsigned int x;
  unsigned int y;
  unsigned int z;
} cube_t;

cube_t *cube_g;



bool position_valid( position_t **positions) {
  return true;
}

bool snake_valid( position_t **positions, char *binary_string);
bool snake_valid( position_t **positions, char *binary_string) {
  if( strlen( binary_string) == 1){
    printf( "%c!\n", binary_string[0] );
    return true;
  }
  
  if( binary_string[0] == '0'){
    printf( "%c", binary_string[0] );
    snake_valid( positions, binary_string + 1);
  }
  else {
    printf( "%c", binary_string[0] );
    snake_valid( positions, binary_string + 1);
  }
    
}

void initialize( int argc, char *argv[]) {
  cube_g = (cube_t *)malloc( sizeof( cube_t));
  cube_g->x = (unsigned int)strtol(argv[1], (char **)NULL, 10);
  cube_g->y = (unsigned int)strtol(argv[2], (char **)NULL, 10);
  cube_g->z = (unsigned int)strtol(argv[3], (char **)NULL, 10);
}

void free_positions( position_t ** positions) {
  free( (positions)[0]); (positions)[0] = NULL;
  free( positions); positions = NULL;
}

/* $ snake_cube x y z binary_string */
int main (int argc, char *argv[]) {
  initialize( argc, argv);
  position_t **positions;
  positions = (position_t **)malloc( sizeof( position_t*));
  positions[0] = (position_t *)malloc( sizeof( position_t));
  positions[0]->x = 1;
  positions[0]->y = 1;
  positions[0]->z = 1;
  positions[0]->d = 1;

snake_valid( positions, argv[4]);

  
  return 0;
}

