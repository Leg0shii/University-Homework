#include <stdio.h>
#include <math.h>

void star(int indent , char chr) {
  for(;indent;--indent) putchar(' ');
  printf("%c\n",chr);
}

main () {
  double x;

  for(x=-180.0;x<=180.0;x+=30.0)
  star(10+10*sin(x/180.0*M_PI),'*');
  for(x=-180.0;x<=180.0;x+=30.0)
  star(10+10*cos(x/180.0*M_PI),'+');
}
