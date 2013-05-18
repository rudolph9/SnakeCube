#include <stdio.h>
#include <string.h>


 int main (int argc, char *argv[]) {
  int i;
  printf( "The number of arguments is %d\n", argc);
  printf( "The arguments are as follows:\n");
  for( i = 0; i < argc; i++) { 
    printf( "%s\n", argv[i]);
  }

  
}

