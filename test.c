#include "second_cube.h"


int main()
{
  int rgb;
  int r;
  int g;
  int b;

  r = 98;
  g = 165;
  b = 159;

  rgb = r;
  printf("RGB POST R = %d\n", rgb);
  rgb = (rgb << 8) + g;
  printf("RGB POST G = %d\n", rgb);
  rgb = (rgb << 8) + b;
  printf("RGB POST B = %d\n", rgb);
}
