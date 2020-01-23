#include "second_cube.h"


int main()
{
  int rgb;
  int r;
  int g;
  int b;

  r = 212;
  g = 112;
  b = 254;

  rgb = r;
  printf("RGB POST R = %d\n", rgb);
  rgb = (rgb << 8) + g;
  printf("RGB POST G = %d\n", rgb);
  rgb = (rgb << 8) + b;
  printf("RGB POST B = %d\n", rgb);
}
