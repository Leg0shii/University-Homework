#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]){

  WIN32_FIND_DATA wfd;
  HANDLE fHandle;

  int i = 0;

  char Datein[10][30];

  fHandle = FindFirstFile("d:\\Desktop\\Test\\*");


  do {

    Dateien[i] = wfd.cFileName[i];
    printf("Datei: %s\n", wfd.cFileName);
    i++;

    } while (FindNextFile(fHandle, &wfd));

    FindClose(fHandle);
    printf("\n");

    system("PAUSE");
    return 0;

}
