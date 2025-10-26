#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database/lettura.h"

// verifica "cognome", "sesso" e "obiettivo mensile" nel database
extern bool VerificaNomeCognome(char *nome, char *cognome, int *sesso, int *obiettivo) {
    char *indirizzo = calloc(300, sizeof(char));
    strcat(indirizzo, "C:\\ProgramData\\coordinatrice\\");
    strcat(indirizzo, nome);
    strcat(indirizzo, " ");
    strcat(indirizzo, cognome);
    strcat(indirizzo, ".txt");

    // apertura file
    FILE *file = fopen(indirizzo, "r");

    if (file == NULL) {
        free(indirizzo);
        return false;
    }

    fscanf(file, "%d\n%d", sesso, obiettivo);
    fclose(file);
    free(indirizzo);

    return true;
}
