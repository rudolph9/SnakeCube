#include <stdlib.h>
#include "snake_cube.h"

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
  //memcpy( position_, position, sizeof( position_t));
  *position_ = *position;
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
  while ( position_i != NULL) {
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
      break;
    case 2:
      position->y += norm;
      break;
    case 3:
      position->z += norm;
      break;
  }
  position->d = direction;
}
position_t * position_append( const position_t * position, int direction) {
  position_t * position_;
  position_ = position_clone( position);
  position_->prev = (position_t *)position;
  position_direction_change( position_, direction);
  return position_;
}
void print_snake( const position_t * position) {
  while( position != NULL) {
    printf( "[%d,%d,%d,%d]", position->x, position->y, position->z, position->d);
    position = position->prev;
  }
  printf( "\n\n");
}

bool snake_valid( cube_t *cube, position_t *position, char *binary_string) {
  int i;
  position_t * position_;
  bool valid_snake;

  printf( "%s\n", binary_string);
  print_snake( position);
  if( strlen( binary_string) == 1) {
    return true;
  }

  if( binary_string[0] == '0') {
    position_ = position_append( position, position->d);
    if( position_valid( cube, position_)) {
      valid_snake = snake_valid( cube, position_, binary_string + 1);
      free_position( position_);
      return valid_snake;
    } else {
      free_position( position_);
      return false;
    }
  } else {
    for( i = 1; i <= 3; i++) {
      if( abs( position->d ) != abs( i)) {
        position_ = position_append( position, i );
        if( position_valid( cube, position_)){
          valid_snake = snake_valid( cube, position_, binary_string + 1);
          free_position(position_);
          if( valid_snake) return true;
        }
      }
    }
    for( i = -1; i >= -3; i--) {
      if( abs( position->d ) != abs( i)) {
        position_ = position_append( position, i );
        if( position_valid( cube, position_)){
          valid_snake = snake_valid( cube, position_, binary_string + 1);
          free_position(position_);
          if( valid_snake) return true;
        }
      }
    }
    return false;
  }
}

void free_cube( cube_t *cube) {
  free( cube);
  cube = NULL;
}
void free_position( position_t *position) {
  free( position);
  position = NULL;
}
void free_snake( position_t *position){
  //TODO
}



