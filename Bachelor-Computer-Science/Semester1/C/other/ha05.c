#include <stdio.h>

int main() {

  /* FILE *fp;
  fp = fopen ("jfhdht.txt","r");
  printf("%d\n",fp);
  fseek(fp, 0, SEEK_END);
  int length = ftell(fp);

  printf("%d\n",length); */

  char datei1[1500000];
  int i, length;

  for (i = 0; i < 1500000; i++) {
    datei1[i] = getchar();
    if (datei1[i] != EOF) {
      length = length + 1;
    }
  }

  char string[length];
  for (i = 0; i < length; i++) {
    if (datei1[i] != EOF) {
      string[i] = datei1[i];
    }
  }




  return 0;
}
