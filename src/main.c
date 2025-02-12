#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"


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

