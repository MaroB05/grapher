#include "fileio.h"
struct point {
  int x;
  int y;
};

FILE* init_image(size_t width, size_t height);
int parse_vals(char* filename, struct point** pairs);

FILE* init_image(size_t width, size_t height){
  FILE* img = openFile("output.pbm", "w", NULL);
  fprintf(img, "P1\n%lu %lu\n", width, height);
  return img;
}

int parse_vals(char filename[], struct point** pairs){
  FILE* source = openFile(filename, "r", "couldn't opent the file");
  int length;
  fread(&length, sizeof(int), 1, source);
  printf("%d\n", length);
  *pairs = malloc(sizeof(int) * length * 2);
  fread(*pairs, sizeof(int), length*2, source);
  return length;
}
