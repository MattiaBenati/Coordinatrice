#include <stdio.h>
#include "grafica/stampa.h"
#include "grafica/grafica.h"

// stampa il caso da analizzare nella schermata home
extern void StampaCaso() {
    GoToXY(15, 3);
    printf("Quale caso vuoi analizzare?");

    GoToXY(13, Y_HOME - 4);
    printf("- Inserisci '0' se vuoi chiudere il programma");
    GoToXY(13, 5);
    printf("- Inserisci '1' se vuoi aggiungere ore/minuti alla sessione");
    GoToXY(13, 7);
    printf("- Inserisci '2' se vuoi modificare l'obiettivo mensile");
    GoToXY(13, 9);
    printf("- Inserisci '3' se vuoi eliminare dei dati");
}

// stampa numero del professore analizzato
extern void StampaNumeroProfessore(int i) {
    GoToXY(36, 3);
    printf("%d' Professore", i + 1);
}

// stampa titolo della professore da eliminare
extern void StampaTitoloEliminazione() {
    GoToXY(26, 3);
    printf("Quale professore desideri eliminare?");
}

// stampa della pagina analizzata
extern void StampaPaginaAnalizzata(int pagina, int totale) {
    GoToXY(5, Y_ELIMINAZIONE - 5);
    printf("Pagina %d di %d", pagina, totale);
}

// stampa richiesta di nome e cognome all'utente
extern void StampaNomeCognome() {
    GoToXY(5, 7);
    printf("Inserisci il nome:");
    GoToXY(5, 9);
    printf("Inserisci il cognome:");
}

// stampa richiesta del sesso all'utente
extern void StampaSesso() {
    GoToXY(5, 11);
    printf("Inserisci il sesso:");
    GoToXY(5, 12);
    printf("('1' = uomo )");
    GoToXY(5, 13);
    printf("('2' = donna)");
}

// stampa richiesta dell'obiettivo mensile all'utente
extern void StampaObiettivo() {
    GoToXY(5, 15);
    printf("Inserisci l'obiettivo mensile:");
    GoToXY(5, 16);
    printf("(espresso in ore)");
}

// stampa richiesta di ore e minuti all'utente
extern void StampaOreMinuti() {
    GoToXY(X_INPUT / 2 + 4, 7);
    printf("Inserisci le ore:");
    GoToXY(X_INPUT / 2 + 4, 9);
    printf("Inserisci i minuti:");
}

// stampa richiesta di giorno, mese e anno all'utente
extern void StampaGiornoMeseAnno() {
    GoToXY(X_INPUT / 2 + 4, 11);
    printf("Inserisci il giorno:");
    GoToXY(X_INPUT / 2 + 4, 13);
    printf("Inserisci il mese:");
    GoToXY(X_INPUT / 2 + 4, 15);
    printf("Inserisci l'anno:");
}
