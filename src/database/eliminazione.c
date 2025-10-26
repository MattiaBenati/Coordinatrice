#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>
#include "database/eliminazione.h"

// eliminazione professore dal database
extern void EliminazioneDatabase(char *file) {
    remove(file);
}

// eliminazione file .txt "Orario Sessioni"
static void EliminazioneOrarioSessioni(char *indirizzo, char *nome) {
    char *path = calloc(300, sizeof(char));
    strcat(path, indirizzo);
    strcat(path, "\\");
    strcat(path, nome);
    strcat(path, "\\Orario sessioni.txt");

    remove(path);
    free(path);
}

// eliminazione file .txt "Orario Totale"
static void EliminazioneOrarioTotale(char *indirizzo, char *nome) {
    char *path = calloc(300, sizeof(char));
    strcat(path, indirizzo);
    strcat(path, "\\");
    strcat(path, nome);
    strcat(path, "\\Orario totale.txt");

    remove(path);
    free(path);
}

// eliminazione professore dalla cartella fornita dall'utente
extern void EliminazioneCartella(char *indirizzo, char *nome) {
    EliminazioneOrarioSessioni(indirizzo, nome); // eliminazione file .txt "Orario sessioni"
    EliminazioneOrarioTotale(indirizzo, nome); // eliminazione file .txt "Orario totale"

    char *path = calloc(300, sizeof(char));
    strcat(path, indirizzo);
    strcat(path, "\\");
    strcat(path, nome);

    _rmdir(path);
    free(path);
}
