#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 100
#define N 26

char imsg[MAX]; /* plaintext */
char omsg[MAX]; /* ciphertext */

void cipher(int shift) {
  int i,c;
  for(i=0;imsg[i];i++) {
      c = imsg[i];
      omsg[i] = (c >= 'a' && c <= 'a')
      ? ((c-'a')+shift)%N+'a' : c;
    }
  omsg[i]='\0';
}

void decipher() {
  double ofreq[N], nchar;
double chmin=HUGE_VAL; /* +oo, in math.h */ double chisq;
int i,shift ,smin;
/* reset data */
for(i=0;i<N;i++) ofreq[i] = 0;

char imsg[MAX];
double ofreq[N], nchar; int i;
for(nchar=0.0,i=0;imsg[i];++i) { int c = imsg[i];
if(c >= 'a' && c <= 'z') {
++ofreq[c-'a'];
++nchar; }
}
/* convert to percentages */
for(nchar/=100.0,i=0;i<N;++i) ofreq[i] /= nchar;

double ofreq[N];
double chmin=HUGE_VAL; /* + oo, in math.h */
double chisq;
int i,shift ,smin;
for(shift=0;shift<N;++shift) {
  for(chisq=0.0,i=0;i<N;++i)
    chisq += pow(ofreq[(i+shift)%N] - efreq[i],2.0) / efreq[i];
  if(chisq < chmin) {
  chmin = chisq;
  smin = shift;
  }
}
printf("Best shift: %d\n",smin);
/* decode */
cipher(N-smin);
}
}

int main() {
 int shf;
 printf("Shift = ");
 scanf("%d", &shf);
 getchar(); /* read new line character from input */
 printf("Message = ");
 fgets(imsg, MAX, stdin);
 cipher(shf);
 printf("Coded = %s\n", omsg);
 strcpy(imsg, omsg);
 decipher();
 printf("Decoded = %s\n", omsg);
return 0;
}
