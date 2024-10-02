#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bZuZahl(int a){ /* Wandelt Buchstaben in eine "Array"-Zahl um. a - 1; b - 2 ... */
  int b = 0;
  if ((a>64 && a<91) || (a>96 && a<123) || a == 32 || a == 44 || a == 46){
    if (a>96 && a<123) {
      b = a - 96;
    }
    if (a == 32) {
      b = 27;
    }
    if (a == 44) {
      b = 28;
    }
    if (a == 46) {
      b = 29;
    }
  }
  else{
    b = 0;
  }
  return b;
}

int pChar(int a){ /* Umkehrung zu bZuZahl. (Zum auf Konsole printen) */
  int b = 0;
  if (a<27) {
    b = a+96;
  }
  else if (a==27) {
    b = 32;
  }
  else if (a==28) {
    b = 44;
  }
  else if (a==29) {
    b = 46;
  }
  return b;
}

/* printet tabelle zum array (falls Werte eine Wahrscheinlichkeit > 0 haben) */
/* Funktion wird in main nicht aufgerufen - benutzt für Testzwecke */
void printName(double arr[][30][30]){
  int i, j, h;
  for (i = 0; i < 30; i++) {
    for (j = 0; j < 30; j++) {
      for (h = 0; h < 30; h++) {
        if (arr[i][j][h] > 0) {
          putchar(pChar(i));
          putchar(pChar(j));
          putchar(pChar(h));

          printf(": %1.11f Prozent\n",arr[i][j][h]);
        }
      }
    }
  }
}

int fillArray(double arr[][30][30]){ /* Gibt Array benötigte Werte */
  int b1, b2, b3, z1, z2, z3, i, j, h, count;

  for (i = 0; i < 30; i++) { /* Initialisierung vom Array */
    for (j = 0; j < 30; j++) {
      for (h = 0; h < 30; h++) {
        arr[i][j][h] = 0;
      }
    }
  }

    b3 = getchar();
    b2 = getchar();
    count = 0;

  while(b1 != EOF){ /* Array wird mit Anzahl der vorkommenden Triple des txts gefüllt. */
    b1 = getchar();

    z1 = bZuZahl(b3);
    z2 = bZuZahl(b2);
    z3 = bZuZahl(b1);

    b3 = b2;
    b2 = b1;

    arr[z1][z2][z3] = arr[z1][z2][z3] + 1;
    count = count + 1; /* Anzahl vorkommenden Triple total ebenfalls gezählt */
  }
  return count;
}
void calcArray(double arr[][30][30], int count){ /* Berechnung der Wahrscheinlichkeit */
  int i, j, h;
  for (i = 0; i < 30; i++) {
    for (j = 0; j < 30; j++) {
      for (h = 0; h < 30; h++) {
        arr[i][j][h] = arr[i][j][h]/(count-186605);
      }
    }
  }
}

double rnd(int lim){ /* Kreiert Random Zahl */
  double k;

  k = (rand()%lim);
  return k;
}

int startGenerator(double arr[][30][30], int *jh, int lim){ /* Sucht Randomzahl */
  int i, j, h;                                              /* in dem Array */
  double r = rnd(lim);
  double sum = 0;

  for (i = 1; i < 30; i++) {
    for (j = 1; j < 30; j++) {
      for (h = 1; h < 30; h++) {
        sum = arr[i][j][h]+sum;
        if ((sum*1257272) > r) {
          putchar(pChar(i));
          putchar(pChar(j));
          putchar(pChar(h));
          jh[0] = j;
          jh[1] = h;
          return 0;
        }
      }
    }
  }
  return 0;
}

int gen(double arr[][30][30], int *jh){ /* Generiert Zahlen in Abhängigkeit */
  int h;                                   /* von Spalte */
  double sum1, sum2, sum3, r;
  sum1 = 0;
  sum2 = 0;
  sum3 = 0;

  for (h = 1; h < 30; h++) {
    sum1 = arr[jh[0]][jh[1]][h] + sum1;
  }

  sum2 = 1000000*sum1;
  r = rnd(sum2);

  for (h = 1; h < 30; h++) {
    sum3 = arr[jh[0]][jh[1]][h] + sum3;
    if ((sum3*1000000) > r) {
      putchar(pChar(h));
      jh[0] = jh[1];
      jh[1] = h;
      return 0;
    }
  }
  return 0;
}

int generator(double arr[][30][30], int *jh, int w){ /* Generiert soviele */
  int i;                                            /* Folgewörter wie angegeben */
  for(i = 0; i < w; i++){
    gen(arr, jh);
  }
  return 0;
}

int main() {
  int jh[] = {0,0};
  int w = 1000;
  double arr[30][30][30];
  int count;

  srand(time(0)); /* Seed für Zufallszahl */

  count = fillArray(arr); /* Array wird initialisiert u. bekommt Werte des Texts */
  calcArray(arr, count); /* Wahrscheinlichkeit berechnen */

  printf("Text wird generiert:\n");
  printf("**************************\n");

  startGenerator(arr, jh, count); /* Erste Wert wird generiert */
  generator(arr, jh, w-1); /* w-1 Buchstaben werden generiert */

  printf("\n");
  printf("**************************\n");
  return 0;
}
