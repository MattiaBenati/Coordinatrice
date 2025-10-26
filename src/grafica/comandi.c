#include <stdio.h>
#include <string.h>
#include "grafica/comandi.h"
#include "grafica/grafica.h"

// cancellazione di pixel (con spazi)
extern void CancellazionePixel(int x, int y, int lunghezza) {
    GoToXY(x, y);

    for (int i = 0; i < lunghezza; ++i)
        printf(" ");
}

// conversione in lettere minuscole
extern void MaiuscMinusc(char *parola) {
    for (size_t i = 0; i < strlen(parola); ++i) {
        // da minuscola a MAIUSCOLA
        if ((i == 0 || parola[i - 1] == ' ') && parola[i] <= 122 && parola[i] >= 97)
            parola[i] -= 32;

            // da MAIUSCOLA a minuscola
        else if (i != 0 && parola[i] <= 90 && parola[i] >= 65)
            parola[i] += 32;
    }
}
