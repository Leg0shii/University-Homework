#include <stdio.h>
#define n 3
int main() {
int i, a[n], b[n], ab;
for(i=0;i<n;++i) {
printf("a[%d] = ",i); scanf("%d",&a[i]);
}
for(i=0;i<n;++i) {
printf("b[%d] = ",i); scanf("%d",&b[i]); }
for(i=0,ab=0; i<n; ++i) ab += a[i]*b[i];
printf("a.b = %d\n",ab);
return 0; }
