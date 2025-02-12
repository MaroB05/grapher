#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

// [len, x1, y1, x2, y2, ...]
	//^
	//|
	//pairs
	
int power(int base, int p){
  int out = base;
  for (int i = 1; i < p; i++)
    out *= base;
  return out;
}

struct point{
  int x;
  int y;
};

int main(int argc, char* argv[]){
  
  if (argc < 3){
    fputs("not enough args:\n\tgen [num_pairs] [factor] [power]\n", stderr);
    exit(1);
  }
  
  int num_pairs = atoi(argv[1]);
  int n = atoi(argv[2]);
  int p = atoi(argv[3]);

  struct point* pairs;
  pairs = malloc(num_pairs * sizeof(struct point));
  
  for (int i = 0; i < num_pairs; i++){
    pairs[i].x = i;
    pairs[i].y = n*power(i, p);
  }
  
  FILE* file = openFile("test.data", "w", NULL);
  fwrite(&num_pairs, sizeof(int), 1, file);
  fwrite(pairs, sizeof(struct point), num_pairs, file);
  fclose(file);

  return 0;
}
