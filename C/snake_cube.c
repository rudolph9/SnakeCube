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

bool positions_equal( const position_t * position_a , const position_t * position_b) { 
  if( position_a->x == position_b->x &&
      position_a->y == position_b->y &&
      position_a->z == position_b->z)
    return true;

  return false;
}
position_t * position_clone( const position_t * position) {
  position_t *position_;
  position_ = (position_t *)malloc( sizeof( position_t));
  memcpy( position_, position, sizeof( position_t));
  return position_;
}

bool position_valid( cube_t * cube, const position_t *position) {
  if( position->x < 1       || 
      position->x > cube->x || 
      position->y < 1       || 
      position->y > cube->y || 
      position->z < 1       || 
      position->z > cube->z)
    return false;
  position_t *position_i;
  position_i = position->prev;
  while ( position_i->prev != NULL) {
    if( positions_equal( position_i, position)) {
      return false;
    }
    position_i = position_i->prev;
  }
  return true;
}

void position_direction_change( position_t * position, int direction){
  int norm = direction / abs( direction);
  switch( abs( direction)) {
    case 1:
      position->x += norm;
    case 2:
      position->y += norm;
    case 3:
      position->z += norm;
  }
}
position_t * position_append( const position_t * position, int direction) {
  position_t * position_;
  position_ = position_clone( position);
  position_->prev = position;
  position_direction_change( position_, direction);
  return position_;
}

bool snake_valid( cube_t *cube, position_t *position, char *binary_string) {
  if( strlen( binary_string) == 1) {
    printf( "%c!\n", binary_string[0] );
    return true;
  }

  if( binary_string[0] == '0') {
    position_t * position_;
    position_ = position_append( position, position->d);
    if( position_valid( cube, position_)) {
      printf( "%c", binary_string[0] );
      return snake_valid( cube, position_, binary_string + 1);
    }
    else {
    position_t * position_;
    int i;
    for( i = 1; i <= 3; i++){
      position_ = position_append( position, i );
      if( position_valid( cube, position_)) {
        printf( "%c", binary_string[0] );
        if ( snake_valid( cube, position, binary_string + 1)) return true;
      }
    }
    for( i = -1; i >= -3; i--) {
      position_ = position_append( position, i );
      if( position_valid( cube, position_)) {
        printf( "%c", binary_string[0] );
        if (snake_valid( cube, position, binary_string + 1)) return true;
      }
    }
      return false;
    }
  }
  else {
    printf( "%c", binary_string[0] );
    return snake_valid( cube, position, binary_string + 1);
  }
    
}

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

void free_positions( position_t ** positions) {
  free( (positions)[0]); (positions)[0] = NULL;
  free( positions); positions = NULL;
}

/* $ snake_cube x y z binary_string */
int main (int argc, char *argv[]) {
  cube_t *cube;
  position_t *position;
  initialize( argc, argv, &cube, &position);

  snake_valid( cube, position, argv[4]);

  
  return 0;
}

