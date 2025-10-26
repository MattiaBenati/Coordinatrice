#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "database/database.h"
#include "database/lettura.h"
#include "database/scrittura.h"
#include "database/aggiornamento.h"
#include "database/eliminazione.h"
#include "grafica/grafica.h"
#include "grafica/stampa.h"
#include "grafica/comandi.h"
#include "input.h"
#include "file.h"
#include "indirizzo.h"

int main(void) {
    // dimensione pannello FISSA
    HWND consoleWindow = GetConsoleWindow();
    SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);

    CartellaDatabase(); // creazione cartella "database"

errore1:
    system("MODE 86, 13");
    BordiPannelloIndirizzo();

    SuggerimentiIndirizzo(); // stampa suggerimenti

    // input indirizzo della cartella
    char *indirizzo = IndirizzoCartella();

    if (indirizzo[0] == '0') // chiusura programma
    {
        free(indirizzo);
        return 0;
    } else if (indirizzo[0] == '1') // errore (rinizio programma)
    {
        free(indirizzo);
        goto errore1;
    }

    // inizio analisi delle opzioni offerte all'utente
    while (true) {
        system("MODE 86, 19");
        BordiPannelloHome();

        int caso;

        StampaCaso(); // stampa casi analizzabili

        // input caso da analizzare
    errore2:
        caso = InputCaso();

        if (caso == 0) // chiusura programma
        {
            free(indirizzo);
            break;
        } else if (caso == -1) // errore (reimmissione)
        {
            CancellazionePixel(36, 11, 48);
            goto errore2;
        }

        // inizio caso analizzato
        struct professore *professori = malloc(sizeof(struct professore));

        char **directory = NULL; // indirizzo directory nel database
        char **nomi = NULL; // nomi all'interno della directory

        int n, k = 0; // k = numero professori salvati nel database
        int pagina = 0; // indice pagina analizzata

        switch (caso) {
            case 1:
            errore3:
                system("MODE 86, 10");
                BordiPannelloNumeroProfessori();

                n = InputNumeroProfessori(); // numero professori

                if (n == -1) // errore (reimmissione)
                    goto errore3;

                for (int i = 0; i < n; ++i) {
                    system("MODE 86, 20");
                    BordiPannelloInput();

                    struct professore *sessione = malloc(sizeof(struct professore));
                    bool check = false;

                    StampaNumeroProfessore(i); // stampa titolo della pagina
                    StampaNomeCognome(); // stampa input nome e cognome

                    // input nome
                errore4:
                    professori->nome = InputNome();

                    if (professori->nome[0] == '0') {
                        CancellazionePixel(24, 7, 18);
                        goto errore4;
                    }

                    // input cognome
                errore5:
                    professori->cognome = InputCognome();

                    if (professori->cognome[0] == '0') {
                        CancellazionePixel(27, 9, 15);
                        goto errore5;
                    }

                    check = VerificaNomeCognome(professori->nome, professori->cognome,
                                                &professori->sesso, &professori->obiettivo);

                    // se presente nel database
                    if (check == true) {
                        StampaOreMinuti(); // stampa input ore e minuti
                        StampaGiornoMeseAnno(); // stampa input giorno, mese e anno

                        // input ore
                    errore6:
                        professori->ore = InputOre();

                        if (professori->ore == -1) {
                            CancellazionePixel(65, 7, 19);
                            goto errore6;
                        }

                        // input minuti
                    errore7:
                        professori->minuti = InputMinuti();

                        if (professori->minuti == -1) {
                            CancellazionePixel(67, 9, 17);
                            goto errore7;
                        }

                        // input giorno
                    errore8:
                        professori->giorno = InputGiorno();

                        if (professori->giorno == -1) {
                            CancellazionePixel(68, 11, 16);
                            goto errore8;
                        }

                        // input mese
                    errore9:
                        professori->mese = InputMese();

                        if (professori->mese == -1) {
                            CancellazionePixel(66, 13, 18);
                            goto errore9;
                        }

                        // input anno
                    errore10:
                        professori->anno = InputAnno();

                        if (professori->anno == -1) {
                            CancellazionePixel(65, 15, 19);
                            goto errore10;
                        }

                        // salvataggio orario di tale sessione
                        sessione->ore = professori->ore;
                        sessione->minuti = professori->minuti;
                        sessione->giorno = professori->giorno;
                        sessione->mese = professori->mese;
                        sessione->anno = professori->anno;

                        AggiornamentoDatabase(professori->nome, professori->cognome, professori->obiettivo,
                                              &professori->ore, &professori->minuti, &professori->giorno,
                                              &professori->mese, &professori->anno);
                    }

                    // se NON presente nel database
                    else {
                        StampaSesso(); // stampa input sesso
                        StampaObiettivo(); // stampa input obiettivo mensile
                        StampaOreMinuti(); // stampa input ore e minuti
                        StampaGiornoMeseAnno(); // stampa input giorno, mese e anno

                        // input sesso
                    errore11:
                        professori->sesso = InputSesso();

                        if (professori->sesso == -1) {
                            CancellazionePixel(25, 11, 17);
                            goto errore11;
                        }

                        // input obiettivo
                    errore12:
                        professori->obiettivo = InputObiettivo();

                        if (professori->obiettivo == -1) {
                            CancellazionePixel(36, 15, 6);
                            goto errore12;
                        }

                        // input ore
                    errore13:
                        professori->ore = InputOre();

                        if (professori->ore == -1) {
                            CancellazionePixel(65, 7, 19);
                            goto errore13;
                        }

                        // input minuti
                    errore14:
                        professori->minuti = InputMinuti();

                        if (professori->minuti == -1) {
                            CancellazionePixel(67, 9, 17);
                            goto errore14;
                        }

                        // input giorno
                    errore15:
                        professori->giorno = InputGiorno();

                        if (professori->giorno == -1) {
                            CancellazionePixel(68, 11, 16);
                            goto errore15;
                        }

                        // input mese
                    errore16:
                        professori->mese = InputMese();

                        if (professori->mese == -1) {
                            CancellazionePixel(66, 13, 18);
                            goto errore16;
                        }

                        // input anno
                    errore17:
                        professori->anno = InputAnno();

                        if (professori->anno == -1) {
                            CancellazionePixel(65, 15, 19);
                            goto errore17;
                        }

                        // salvataggio orario di tale sessione
                        sessione->ore = professori->ore;
                        sessione->minuti = professori->minuti;
                        sessione->giorno = professori->giorno;
                        sessione->mese = professori->mese;
                        sessione->anno = professori->anno;

                        ScritturaDatabase(professori->nome, professori->cognome, professori->sesso,
                                          professori->obiettivo,
                                          professori->ore, professori->minuti, professori->giorno, professori->mese,
                                          professori->anno);
                    }

                    MaiuscMinusc(professori->nome); // conversione formato del nome
                    MaiuscMinusc(professori->cognome); // conversione formato del cognome

                    // scrittura/creazione cartella e file utente del rispettivo professore
                    CartellaProfessore(professori->nome, professori->cognome, indirizzo);
                    FileOrarioSessioni(professori->nome, professori->cognome, indirizzo);
                    FileOrarioTotale(professori->nome, professori->cognome, indirizzo);

                    ScritturaOrarioSessioni(professori->nome, professori->cognome, indirizzo, professori->sesso,
                                            sessione->ore, sessione->minuti, sessione->giorno, sessione->mese,
                                            sessione->anno, check);
                    ScritturaOrarioTotale(professori->nome, professori->cognome, indirizzo, professori->sesso,
                                          professori->obiettivo,
                                          professori->ore, professori->minuti, professori->giorno, professori->mese,
                                          professori->anno);

                    free(sessione);
                    free(professori->nome);
                    free(professori->cognome);
                }
                break;

            case 2:
            errore18:
                system("MODE 86, 10");
                BordiPannelloNumeroProfessori();

                n = InputNumeroProfessori(); // numero professori

                if (n == -1) // errore (reimmissione)
                    goto errore18;

                // data attuale
                time_t data_attuale;
                time(&data_attuale);
                struct tm *data = localtime(&data_attuale);

                for (size_t i = 0; i < n; ++i) {
                    system("MODE 86, 20");
                    BordiPannelloInput();

                    struct professore *sessione = malloc(sizeof(struct professore));
                    bool check = false;

                    StampaNumeroProfessore(i); // stampa titolo della pagina
                    StampaNomeCognome(); // stampa input nome e cognome

                    // input nome
                errore19:
                    professori->nome = InputNome();

                    if (professori->nome[0] == '0') {
                        CancellazionePixel(24, 7, 18);
                        goto errore19;
                    }

                    // input cognome
                errore20:
                    professori->cognome = InputCognome();

                    if (professori->cognome[0] == '0') {
                        CancellazionePixel(26, 9, 16);
                        goto errore20;
                    }

                    check = VerificaNomeCognome(professori->nome, professori->cognome,
                                                &professori->sesso, &professori->obiettivo);

                    // se presente nel database
                    if (check == true) {
                        StampaObiettivo(); // stampa input obiettivo mensile

                        // input obiettivo
                    errore21:
                        professori->obiettivo = InputObiettivo();

                        if (professori->obiettivo == -1) {
                            CancellazionePixel(36, 15, 6);
                            goto errore21;
                        }

                        // input ore, minuti, giorno, mese e anno
                        professori->ore = 0;
                        professori->minuti = 0;
                        professori->giorno = (int) data->tm_mday;
                        professori->mese = (int) data->tm_mon + 1;
                        professori->anno = (int) data->tm_year + 1900;

                        // salvataggio orario di tale sessione
                        sessione->ore = professori->ore;
                        sessione->minuti = professori->minuti;
                        sessione->giorno = professori->giorno;
                        sessione->mese = professori->mese;
                        sessione->anno = professori->anno;

                        AggiornamentoDatabase(professori->nome, professori->cognome, professori->obiettivo,
                                              &professori->ore, &professori->minuti, &professori->giorno,
                                              &professori->mese, &professori->anno);
                    }

                    // se NON presente nel database
                    else {
                        StampaSesso(); // stampa input sesso
                        StampaObiettivo(); // stampa input obiettivo mensile

                        // input sesso
                    errore22:
                        professori->sesso = InputSesso();

                        if (professori->sesso == -1) {
                            CancellazionePixel(25, 11, 17);
                            goto errore22;
                        }

                        // input obiettivo
                    errore23:
                        professori->obiettivo = InputObiettivo();

                        if (professori->obiettivo == -1) {
                            CancellazionePixel(36, 15, 6);
                            goto errore23;
                        }

                        // input ore, minuti, giorno, mese e anno
                        professori->ore = 0;
                        professori->minuti = 0;
                        professori->giorno = (int) data->tm_mday;
                        professori->mese = (int) data->tm_mon + 1;
                        professori->anno = (int) data->tm_year + 1900;

                        // salvataggio orario di tale sessione
                        sessione->ore = professori->ore;
                        sessione->minuti = professori->minuti;
                        sessione->giorno = professori->giorno;
                        sessione->mese = professori->mese;
                        sessione->anno = professori->anno;

                        ScritturaDatabase(professori->nome, professori->cognome, professori->sesso,
                                          professori->obiettivo,
                                          professori->ore, professori->minuti, professori->giorno, professori->mese,
                                          professori->anno);
                    }

                    MaiuscMinusc(professori->nome); // conversione formato del nome
                    MaiuscMinusc(professori->cognome); // conversione formato del cognome

                    // scrittura/creazione cartella e file utente del rispettivo professore
                    CartellaProfessore(professori->nome, professori->cognome, indirizzo);
                    FileOrarioSessioni(professori->nome, professori->cognome, indirizzo);
                    FileOrarioTotale(professori->nome, professori->cognome, indirizzo);

                    ScritturaOrarioSessioni(professori->nome, professori->cognome, indirizzo, professori->sesso,
                                            sessione->ore, sessione->minuti, sessione->giorno, sessione->mese,
                                            sessione->anno, check);
                    ScritturaOrarioTotale(professori->nome, professori->cognome, indirizzo, professori->sesso,
                                          professori->obiettivo,
                                          professori->ore, professori->minuti, professori->giorno, professori->mese,
                                          professori->anno);

                    free(sessione);
                    free(professori->nome);
                    free(professori->cognome);
                }
                break;

            case 3:

                while (true) {
                    // '0' = uscita programma
                    // '-1' = errore
                    // '-2' = '+'
                    // '-3' = '-'

                    directory = LetturaIndirizzoDati("C:\\ProgramData\\coordinatrice", &k);
                    // lettura indirizzi dal database
                    nomi = LetturaNomeDati("C:\\ProgramData\\coordinatrice", 0, k);
                    // lettura nomi e cognomi dal database

                    if (pagina != 0 && k % 7 != pagina)
                        pagina -= 1;

                pagine:
                    system("MODE 86, 25");
                    BordiPannelloEliminazione();

                    StampaTitoloEliminazione(); // stampa titolo della pagina
                    StampaPaginaAnalizzata(pagina + 1,
                                           (k % 6 == 0 && k != 0) ? (k / 6) : (k / 6 + 1)); // stampa pagina analizzata
                    SuggerimentiEliminazione(); // stampa suggerimenti

                errore24:
                    // stampa dei professori
                    for (int i = pagina * 6, j = 7; i < k && i < (pagina + 1) * 6; ++i, j += 2) {
                        GoToXY(5, j);
                        printf("%d] %s", i + 1, nomi[i]);
                    }

                    n = InputEliminazione(k, pagina); // input azione da eseguire

                    if (n == 0) // chiusura
                        break;

                    else if (n == -2 && k < (pagina + 2) * 6 - 5)
                    // errore (passato il massimo di professori stampabile)
                    {
                        CancellazionePixel(66, 20, 18);
                        goto errore24;
                    } else if (n == -3 && pagina == 0) // errore (si sta già analizzando la prima pagina)
                    {
                        CancellazionePixel(66, 20, 18);
                        goto errore24;
                    } else if (n == -1) {
                        CancellazionePixel(66, 20, 18);
                        goto errore24;
                    }

                    // analisi pagina successiva
                    if (n == -2) {
                        pagina += 1;
                        goto pagine;
                    }

                    // analisi pagina precedente
                    if (n == -3) {
                        pagina -= 1;
                        goto pagine;
                    }

                    // eliminazione database e cartella del professore
                    EliminazioneDatabase(directory[n - 1]);
                    EliminazioneCartella(indirizzo, nomi[n - 1]);

                    // liberazione spazio di memoria
                    for (int i = 0; i < k; ++i) {
                        free(directory[i]);
                        free(nomi[i]);
                    }

                    k = 0; // reset
                    free(directory);
                    free(nomi);
                }
                break;
        }

        free(professori);
    }

    return 0;
}
