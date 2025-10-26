#include <stdlib.h>
#include "indirizzo.h"
#include "dirent.h"

// lettura indirizzo dati
extern char **LetturaIndirizzoDati(const char *cartella, int *n) {
    char **dati = NULL;

    // directory (cartella)
    DIR *directory = opendir(cartella);

    // ERRORE directory = NULL
    if (directory == NULL)
        return NULL;

    struct dirent *file;
    file = readdir(directory);

    while (file != NULL) {
        if (file->d_name[0] != '.' && strcmp(file->d_name, "desktop.ini") != 0) {
            dati = realloc(dati, (*n + 1) * sizeof(char *));
            dati[*n] = calloc(strlen(cartella) + strlen(file->d_name) + 2, sizeof(char));

            size_t pos = 0;

            // copia indirizzo
            for (size_t i = 0; i < strlen(cartella); ++i) {
                dati[*n][pos] = cartella[i];
                pos += 1;
            }

            // aggiunta separatore
            dati[*n][pos] = '\\';
            pos += 1;

            // copia nome del file
            for (size_t i = 0; i < strlen(file->d_name); ++i) {
                dati[*n][pos] = file->d_name[i];
                pos += 1;
            }

            // aggiunta terminatore
            dati[*n][pos] = 0;
            *n += 1;
        }

        file = readdir(directory);
    }

    closedir(directory);
    return dati;
}

// lettura nome professori dai dati
extern char **LetturaNomeDati(const char *cartella, int n, int dim) {
    char **dati = calloc(dim, sizeof(char *));

    // directory (cartella)
    DIR *directory = opendir(cartella);

    struct dirent *file;
    file = readdir(directory);

    while (file != NULL) {
        if (file->d_name[0] != '.' && strcmp(file->d_name, "desktop.ini") != 0) {
            dati[n] = calloc(strlen(file->d_name) + 1, sizeof(char));

            size_t pos = 0;

            // copia nome del file
            for (size_t i = 0; i < strlen(file->d_name); ++i) {
                if (file->d_name[i] == '.')
                    break;

                if (i == 0 || file->d_name[i - 1] == ' ')
                    dati[n][pos] = file->d_name[i] - 32;
                else
                    dati[n][pos] = file->d_name[i];

                pos += 1;
            }

            // aggiunta terminatore
            dati[n][pos] = 0;
            n += 1;
        }

        file = readdir(directory);
    }

    closedir(directory);
    return dati;
}
