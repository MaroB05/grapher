#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

struct point {
  int x;
  int y;
};

FILE* init_image(size_t width, size_t height);
int parse_vals(char* filename, struct point** pairs);

//Parse a CSV file (x,y) and then generate a PPM image
//with those points
int main(int argc, char* argv[]){
  size_t buff_size = 4 * 1024;
  size_t width = atoi(argv[2]);
  size_t height = atoi(argv[3]);
  size_t x_scale = atoi(argv[4]);
  size_t y_scale = atoi(argv[5]);
  const size_t number_of_pixels = width * height;
  char pixels[number_of_pixels];
  struct point* vals = NULL;
  memset(pixels, '0', number_of_pixels);

  //FILE* data_file = openFile(argv[1], "r", NULL);
  FILE* img = init_image(width, height);

  size_t p = 0;
  char* s = NULL;
  
  int length = parse_vals(argv[1], &vals);
  int position;
  //printf("%p\n%p\n", &vals, vals);
  for (int i = 0; i < length; i++){
    vals[i].x *= x_scale;
    vals[i].y *= y_scale;
    position = vals[i].x + vals[i].y * width + width/2 + height/2 * width;
    //printf("%d, %d\n", vals[i].x, vals[i].y);
    if (abs(vals[i].x) < width/2 && abs(vals[i].y) < height/2)
      pixels[position] = '1';
  }
  fwrite(pixels, 1, number_of_pixels, img);

  return 0;
}

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
