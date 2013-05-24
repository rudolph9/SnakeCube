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

void test_positions_equal() {
  cube_t *cube_0;
  cube_t *cube_1;
  position_t *position_0;
  position_t *position_1;
  int coords[3] = {3, 3, 3};
  initialize( coords, &cube_0, &position_0);
  initialize( coords, &cube_1, &position_1);
  printf( "hello world\n");
  assert( positions_equal( position_0, position_1) == true);

}
void test_position_clone() {
  cube_t *cube_0;
  position_t *position_0;
  position_t *position_1;
  int coords[3] = {3, 3, 3};
  initialize( coords, &cube_0, &position_0);
  position_1 = position_clone( position_0);
  assert( positions_equal( position_0, position_1) == true);
  assert( position_0 != position_1);
}
void test_position_valid() {
  cube_t *cube_0;
  position_t *position_0;
  int coords[3] = {3, 3, 3};
  initialize( coords, &cube_0, &position_0);
  assert( position_valid( cube_0, position_0) == true);
  position_0->x = 0;
  assert( position_valid( cube_0, position_0) == false);
  position_0->x = cube_0->x + 1;
  assert( position_valid( cube_0, position_0) == false);

  position_t *position_1;
  initialize( coords, &cube_0, &position_1);
  position_0->x = 1;
  position_1->prev = position_0;
  assert( position_valid( cube_0, position_1) == false);
  position_1->x = 2;
  assert( position_valid( cube_0, position_1) == true);
}

void test_position_direction_change() {
  cube_t *cube_0;
  position_t *position_0;
  int coords[3] = {3, 3, 3};
  initialize( coords, &cube_0, &position_0);
  position_direction_change( position_0, 1);
  assert( position_0->x == 2);
}
  
void test_position_append( ) {
  cube_t *cube_0;
  position_t *position_0;
  int coords[3] = {3, 3, 3};
  initialize( coords, &cube_0, &position_0);
  position_t *position_1;
  position_1 = position_append( position_0, 1);
  assert( position_1->prev == position_0);
  assert( position_1->x == 2);
}

void test_snake_valid( ) {
  cube_t *cube_0;
  position_t *position_0;
  int coords[3] = {3, 3, 3};
  initialize( coords, &cube_0, &position_0);
  char * binary_string = "001110110111010111101010100";
  assert( snake_valid( cube_0, position_0, binary_string) == true);

  position_t *position_1;
  initialize( coords, &cube_0, &position_1);
  binary_string = "000010110111010111101010100";
  assert( snake_valid( cube_0, position_1, binary_string) == false);
}


int main( int argc, char *argv[]) {
  test_positions_equal();
  test_position_clone();
  test_position_valid();
  test_position_direction_change();
  test_position_append();
  test_snake_valid();
  return 0;
}



