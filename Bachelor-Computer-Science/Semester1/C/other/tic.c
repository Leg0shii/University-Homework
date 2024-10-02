#include <stdio.h>
#include <stdlib.h>

typedef enum {False, True} Bool;

typedef struct {
  char value[3][3];
} rectic, *tic;


void clear(){
  int i;
  for(i=0;i<8;i++,printf("\n"));
}

tic createFeld(){
  int i, j;
  tic b;
  b = malloc(sizeof(rectic));
  for (i = 0; i <= 2; i++) {
    for (j = 0; j <= 2; j++) {
      b->value[i][j] = ' ';
    }
  }
  return b;
}

void printFeld(tic b){
  int i;
  for (i = 0; i <= 2; i++) {
    printf("| %c | %c | %c |\n",b->value[i][0],b->value[i][1],b->value[i][2]);
    printf("\n");
  }
}

Bool line(tic b){
  if (b->value[0][0]==b->value[0][1] && b->value[0][1] == b->value[0][2] && b->value[0][1]!=' ') {
    return True;
  }
  if (b->value[1][0]==b->value[1][1] && b->value[1][1] == b->value[1][2] && b->value[1][1] !=' ') {
    return True;
  }
  if (b->value[2][0]==b->value[2][1]&&b->value[2][1]==b->value[2][2]&&b->value[2][1]!=' ') {
    return True;
  }
  if (b->value[0][0]==b->value[1][0]&&b->value[1][0]==b->value[2][0]&&b->value[1][0]!=' ') {
    return True;
  }
  if (b->value[0][1]==b->value[1][1]&&b->value[1][1]==b->value[2][1]&&b->value[1][1]!=' ') {
    return True;
  }
  if (b->value[0][2]==b->value[1][2]&&b->value[1][2]==b->value[2][2]&&b->value[1][2]!=' ') {
    return True;
  }
  if (b->value[0][0]==b->value[1][1]&&b->value[1][1]==b->value[2][2]&&b->value[1][1]!=' ') {
    return True;
  }
  if (b->value[0][2]==b->value[1][1]&&b->value[1][1]==b->value[2][0]&&b->value[1][1]!=' ') {
    return True;
  }
  return False;
}

int main(){
  tic b = createFeld();
  int i;
  Bool c;
  c = False;
  clear();
  clear();
  clear();
  printFeld(b);
  clear();
  for(i=0;line(b)==False&&i!=9;i++){
    int z,s;
    if (i % 2 == 0){
      printf("Player 1 bitte Zeile,Spalte Eingabe\n");
      scanf("%d,%d",&z,&s);
      z--;
      s--;
      if(b->value[z][s]==' '){
        b->value[z][s]='x';
      } else {
        c = True;
        --i;
      }
    } else {
      printf("Player 2 bitte Zeile,Spalte Eingabe\n");
      scanf("%d,%d",&z,&s);
      z--;
      s--;
      if(b->value[z][s]==' '){
        b->value[z][s]='o';
      } else {
        c = True;
        --i;
      }
    }
    clear();
    printFeld(b);
    clear();
    if(c){
      printf("Feld schon besetzt\n");
      c = False;
    }
  }
  if (i % 2 == 0 && line(b) == True){
    printf("Player 2 hat gewonnen!\n");
  } else if (i % 2 == 1 && line(b) == True) {
    printf("Player 1 hat gewonnen!\n");
  }
  if(i == 9 && line(b) == False) {
    printf("Unentschieden, ihr Dullis\n");
  }
  return 0;
}
