#include <stdio.h>
void proc(int foo) {
printf("proc: foo at begin: %d\n",foo);
foo = foo + 42;
printf("proc: foo at end: %d\n",foo);
}
int main() {
int bar;
bar = 23;
printf("main: bar at begin: %d\n",bar);
proc(bar);
printf("main: bar at end: %d\n",bar); return 0;
}
