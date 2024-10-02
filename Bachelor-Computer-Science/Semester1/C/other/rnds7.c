#include <stdio.h>

unsigned long long int einf_euklid(unsigned long long int a, unsigned long long int b){
  unsigned long long z;
  while (a % b != 0) {
    z = a % b;
    a = b;
    b = z;
  }
  return z;
}

void erw_euklid(unsigned long long int a, unsigned long long int b){
  unsigned long long int x = 1;
  unsigned long long int y = 0;
  unsigned long long int s = 0;
  unsigned long long int t = 1;
  unsigned long long int r, q; /* r: Hilfsvariable */
  unsigned long long int schritte = 1;
  unsigned long long int a1 = a; /* sichern von wert a und b */
  unsigned long long int b1 = b;

  while (b != 0){
    q = a/b; /* Berechnung ggT + bestimmt wann Programm zuende */

    r = a; /* Wert von a auf r umspeichern */
    a = b;
    b = r-q*b;

    r = x; /* Wert von x auf r umspeichern */
    x = s;
    s = r-q*s;

    r = y; /* Wert von y auf r umspeichern */
    y = t;
    t = r-q*t;

    schritte++; /* Zaehlt die Zyklen */
  }

  printf("%18lld  * %17lld  * %11lld  * %16lld  * %16lld  * %5lld  *\n",a1,b1,a,x,y,schritte);
  /* Optik und Ausgabe */

}

int main(){

  unsigned long long int a[] = {120774, 288300744897986560, 28830, 806515533049393,
  806515533049394, 7778742049, 36998852451, 132639, 13131313, 131313131313, 12345678,
  918273645, 78932145}; /* Array der a Werte */

  unsigned long long int b[] = {1232, 28830074489, 274986560, 498454011879264,498454011879264,
  225851433717, 36998852451, 936231, 4242424242, 424242424242,
  87654321, 5647382910, 541236987}; /* Array der b Werte */

    printf("                 A                    B       ggt(A,B)"); /* Optik */
    printf("                  X                   Y   Schritte\n");
    printf("********************************************************");
    printf("**************************************************\n");

  int i;

  for (i = 0; i<12; i++) { /* Ausrechnen aller Werte */
    erw_euklid(a[i],b[i]);
  }
  printf("********************************************************"); /* Optik */
  printf("**************************************************\n");

  return 0;
}
