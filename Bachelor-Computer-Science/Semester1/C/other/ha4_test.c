#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double rnd(){
  double k;
  time_t t;

  k = 1 + (rand()%1257272);
  return (1/k);

}

int main(){
  srand(time(0));
  int i;

  for (i = 0; i < 10000; i++) {
    printf("%f\n",rnd());
  }


return 0;
}
