#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database/scrittura.h"

extern void ScritturaDatabase(char* nome, char* cognome, int sesso, int obiettivo,
    int ore, int minuti, int giorno, int mese, int anno)
{
    char* indirizzo = calloc(300, sizeof(char));
    strcat(indirizzo, "C:\\ProgramData\\coordinatrice\\");
    strcat(indirizzo, nome);
    strcat(indirizzo, " ");
    strcat(indirizzo, cognome);
    strcat(indirizzo, ".txt");

    // apertura file
    FILE* file = fopen(indirizzo, "w");

    fprintf(file, "%d\n%d\n%d\n%d\n%d\n%d\n%d", sesso, obiettivo, ore, minuti,
        giorno, mese, anno);

    fclose(file);
    free(indirizzo);
}