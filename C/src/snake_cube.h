#ifndef __SNAKE_CUBE__
#define __SNAKE_CUBE__

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

bool positions_equal( const position_t * position_a , const position_t * position_b);
position_t * position_clone( const position_t * position);
bool position_valid( cube_t * cube, const position_t *position);
void position_direction_change( position_t * position, int direction);
position_t * position_append( const position_t * position, int direction);
bool snake_valid( cube_t *cube, position_t *position, char *binary_string);
void free_cube( cube_t *cube);
void free_snake( position_t * head);

#endif //__SNAKE_CUBE__