#include <stdio.h>
#include <math.h>

int contained(double x, double a, double b){
  if ((x <= a && x >= b) || (x >= a && x <= b)) {
    return 1;
  }
  else {
    return 0;
  }
}

int line(double x, double y, double px, double py, double qx, double qy){

  double a, b, d, c;
  double t1;

  if (px > qx) {
    t1 = px;
    px = qx;
    qx = t1;

    t1 = py;
    py = qy;
    qy = t1;
  }
 if((qx - px)){
    a = -(qy - py) / (qx - px);
 }
  else {
    a = -(qy - py) / 0.001;
  }
  b = 1;
  if((qx - px)){
     c = -qy + qx * ((qy - py) / (qx - px));
  }
   else {
     c = -qy + qx * ((qy - py) / 0.001);
   }

  d = (a * x + b * y + c) / (sqrt(a * a + b * b));


  if (d < 0) {
    d = -d;
  }

  if (d < 0.5) {
    if (contained(x , (px - 0.5) , (qx + 0.5)) && contained(y , (py - 0.5) , (qy + 0.5))) {
      return 1;
    }
  }
  return 0;
}

int rectangle(double x, double y, double lx, double uy, double rx, double oy){

  if (line(x,y,lx,uy,lx,oy) || line(x,y,lx,uy,rx,uy) || line(x,y,rx,uy,rx,oy) || line(x,y,lx,oy,rx,oy)) {
    return 1;
  }
  else {
    return 0;
  }

}

int main() {
  double x, y;

 for (y = 1; y <= 26; y++) {
    for (x = 1; x <= 32; x++) {
      if (rectangle(x,y,1,25,31,10) || rectangle(x,y,4,20,10,13) || rectangle(x,y,22,20,28,13) ||
          rectangle(x,y,13,25,19,15) || rectangle(x,y,10,5,14,1) || line(x,y,6,5,26,5) ||
          line(x,y,1,10,6,5) || line(x,y,26,5,31,10)) {
        printf("*");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }

  return 1;
}
