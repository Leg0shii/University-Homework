#include <stdio.h>

void clear(){
  int i;
  for (i = 0; i<10; i++) {
    printf("\n");
  }
}

void drawField(){
  int i, j;
  for (i = 0; i < 21; i++) {
    for (j = 0; j < 51; j++) {
      if (i == 0 || j == 0 || i == 20 || j == 50) {
        printf("*");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int getPos(char i, int *pos){
  switch (i) {
    case 'a': pos[1] = pos[1] - 1;
    break;
    case 'w': pos[0] = pos[0] - 1;
    break;
    case 's': pos[0] = pos[0] + 1;
    break;
    case 'd': pos[1] = pos[1] + 1;
    break;
    default:
    break;
  }
  return *pos;
}

int collisionCheck(int *pos){
  if (pos[0] > 19) {
    pos[0] = pos[0] - 1; /*unten */
  }
  else if (pos[0] < 1) {
    pos[0] = pos[0] + 1; /* oben */
  }
  else if (pos[1] < 1) {
    pos[1] = pos[1] + 1; /* links */
  }
  else if (pos[1] > 49) {
    pos[1] = pos[1] - 1; /* rechts */
  }

  return *pos;
}

void printPos(int x, int y){
  int i, j;
  clear();

  for (i = 0; i < 21; i++) {
    for (j = 0; j < 51; j++) {
      if (x == i && y == j) {
        if (x < 21 && y < 51 && x > 0 && y > 0) {
          printf("o");
        }
      }
      else if (i == 0 || j == 0 || i == 20 || j == 50) {
        printf("*");
      }
      else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int main(){
  int pos[] = {5,5};
  char i = 'a';
  drawField();

  while (i != 'p'){
    scanf("%c",&i);
    getPos(i, pos);
    collisionCheck(pos);
    printPos(pos[0],pos[1]);
  }

  return 0;
}
