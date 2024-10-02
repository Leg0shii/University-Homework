#include <stdio.h>

int buchstabe(char a){

  if (a>64 && a<91 || a>96 && a<123){
    if (a>96 && a<123) {
      a = a - 32;
    }
    return a-64;
  }
  else{
    return -1;
  }
}

int main() {
  char b;
  int c;
  printf("Dein Buchstabe?\n");
  scanf("%c",&b);

  c = buchstabe(b);
  printf("%d\n",c);

}
