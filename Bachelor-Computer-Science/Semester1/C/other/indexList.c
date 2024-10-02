#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
#define MAXSTRING 150000
#define MAXFILM 500
#define MAXTITLE 50
#define MAXDATE 10

typedef struct {
//Kompletter Text von Filmabsatz: max 250 Zeichen
  char komplett[MAXFILM];
//Titel des Films - einzeilig (bis Absatz): max 20 Zeichen
  char title[MAXTITLE];
//Kategorie des Films: max 1 Zeichen
  char kategorie;
//Datum des Films: max 10 Zeichen
  char datum[MAXDATE];
} RecFilm, *Film;

typedef struct {
//Liste der Filme: max 100000 Filme
  RecFilm film[MAX];
} RecList, *List;

typedef struct {
  char titleP[MAXTITLE]; //Titel des zu prüfenden Liste
  char titleI[MAXTITLE]; //Titel der Indexliste
  char kategorie; //Kategorie von Indexliste
} RecTreffer, *Treffer;

typedef struct {
//Liste von Treffern: max 100000 Treffer
  RecTreffer treffer[MAX];
} RecTList, *TList;

//allozieren von Speicher fuer Film
Film createFilm() {
  Film film = malloc(sizeof(RecFilm));
  return film;
}

//allozieren von Speicher fuer Liste von Filmen
List createList() {
  List list = malloc(sizeof(RecList));
  return list;
}

//allozieren von Speicher fuer treffer
Treffer createTreffer() {
  Treffer treffer = malloc(sizeof(RecTreffer));
  return treffer;
}

//allozieren von Speicher fuer treffer Liste
TList createTList() {
  TList tlist = malloc(sizeof(RecTList));
  return tlist;
}

//Einlesen der ersten Liste (Erster Teil des Textes)
//Dies sollte die Indexliste sein
int *readFirstString(int *string) {
  int i = 0;
  int a = 0;

//speichert solange Buchstaben auf string bis sie ein
// '|' liest. Am Ende wird ein EOF Zeichen rangehängt.
// EOF = EndOfFile und signalisiert das Liste zuende ist.
  for (i = 0; a != '|'; i++) {
    a = getchar();
    string[i] = a;
  }
  string[i+1] = EOF;
  return string;
}

//Einlesen der zweiten Liste (Zweiter Teil des Textes)
//Dies sollte die zu prüfende Liste sein
int *readSecondString(int *string) {
  int i = 0;
  int a = 0;

//speichert solange Buchstaben auf string bis sie ein
// EOF liest. Am Ende wird ein EOF Zeichen rangehängt.
// EOF = EndOfFile und signalisiert das Liste zuende ist.
  for (i = 0; a != EOF; i++) {
    a = getchar();
    string[i] = a;
  }
  string[i+1] = EOF;
  return string;
}

//Hier wird ein vorher eingelesener String übergeben.
//Dieser wird von '-  ' (Bindestrich gefolgt von zwei Leerzeichen)
//bis zum nächsten auftreten von '-  ' als ein Film.komplett gespeichert
List divideIntoFilm(int *string) {
  int i, k, j;
  i = j = k = 0;
  List l = createList();

//geht String solange durch bis er zum EOF Symbol gelangt
  for (i = 0; string[i] != EOF; i++, j++) {
    if (string[i] == '-' && string[i+1] == ' ' && string[i+2] == ' ') {
      j = 0;
      k = k + 1;
    }
    l->film[k-1].komplett[j] = string[i];
  }
//an jedes komplett wird auch ein EOF Symbol gehängt
  l->film[k].komplett[0] = EOF;
  return l;
}

//speichert den ersten Absatz von Film.komplett auf Film.title
//dies wird dann auf der Liste eingefügt
List findTitle(List l) {
  int i, j, k;
  j = k = 0;
  i = 0;
  for (i = 0; l->film[i].komplett[0] != -1; i++) {
    for (j = 0; j < MAXTITLE; j++) {
      l->film[i].title[j] = l->film[i].komplett[j];
      if (l->film[i].komplett[j] == '\n') {
        j = MAXTITLE;
      }
    }
  }
  return l;
}

//speichert das Datum von Film.komplett auf Film.datum
//dies wird dann auf der Liste eingefügt
List findDatumKategorie(List l) {
  int i, j, k;
  i = 0;
  for (i = 0; l->film[i].komplett[0] != -1; i++) {
    for (j = 10; j < (MAXFILM - 3); j++) {
//sucht nach 4 stelliger Zahl zwischen 1960 und 2025
      int sum =
        ((l->film[i].komplett[j]-48)*1000
         + (l->film[i].komplett[j+1]-48)*100
         + (l->film[i].komplett[j+2]-48)*10
         + (l->film[i].komplett[j+3]))-48;
//falls gefunden: nimmt er Zeichen k-6 bis k+4
      if (sum > 1960 && sum < 2025 && l->film[i].komplett[j-1] == '.') {
        for (k = 0; k < MAXDATE; k++) {
          l->film[i].datum[k] = l->film[i].komplett[j-6];
          j++;
          sum = 0;
        }
        if (l->film[i].komplett[j-5] == 'a' || l->film[i].komplett[j-5] == 'b') {
          l->film[i].kategorie = l->film[i].komplett[j-5];
        }
      }
    }
  }
  return l;
}

//gibt Länge der Liste zurück
int lengthList(List l) {
  int i;
  for (i = 0; l->film[i].komplett[0] != EOF; i++);
  return i;
}

//vergleicht Titel beider Listen miteinander
//Vergleiche die ausgeführt werden: Länge von l1 * Länge von l2
TList compareList(List l1, List l2) {
  int i, j, k, h, l, unterschied;
  h = unterschied = 0;
  TList tl = createTList();

  for (i = 0; l1->film[i].komplett[0] != -1; i++) {
    for (l = 0; l2->film[l].komplett[0] != -1; l++) {
      for (j = 0; j < MAXTITLE && unterschied < 5; j++) {
        if (l1->film[i].title[j] != l2->film[l].title[j]) {
          unterschied++;
        }
      }
      if (unterschied < 3) {
        for (k = 0; k < MAXTITLE; k++) {
          tl->treffer[h].titleP[k] = l2->film[i].title[k];
          tl->treffer[h].titleI[k] = l1->film[i].title[k];
        }
        tl->treffer[h].kategorie = l1->film[i].kategorie;
        h++;
      }
      unterschied = 0;
    }
  }
  tl->treffer[h].kategorie = 'z';
  return tl;
}

int main() {
  int string1[1000000];
  int string2[1000000];

  int i, k;
  List l1, l2;
  TList tl;

  readFirstString(string1);

  l1 = divideIntoFilm(string1);
  l1 = findTitle(l1);
  l1 = findDatumKategorie(l1);

  for (i = 0; l1->film[i].komplett[0] != -1; i++) {
    printf("%s",l1->film[i].title);
    for (k = 0; k < 10; k++) {
      printf("%c",l1->film[i].datum[k]);
    }
    printf("\nKategorie: %c\n",l1->film[i].kategorie);
    printf("\n");
  }

  /* for (i = 0; tl->treffer[i].kategorie != 'z'; i++) {
    for (k = 3; k < MAXTITLE; k++) {
      if (tl->treffer[i].titleI[k] != '\n') {
        printf("%c", tl->treffer[i].titleI[k]);
      }
    }
    printf(" - ");
    for (k = 3; k < MAXTITLE; k++) {
      if (tl->treffer[i].titleI[k] != '\n') {
        printf("%c", tl->treffer[i].titleI[k]);
      }
    }
    printf("\n");
    printf("Kategorie: %c\n", tl->treffer[i].kategorie);
    printf("\n");
  }*/

  return 0;
}
