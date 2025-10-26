#ifndef GRAFICA_H
#define GRAFICA_H
#define X_INDIRIZZO 86
#define Y_INDIRIZZO 13
#define X_HOME 86
#define Y_HOME 19
#define X_NUMERO 86
#define Y_NUMERO 10
#define X_INPUT 86
#define Y_INPUT 20
#define X_ELIMINAZIONE 86
#define Y_ELIMINAZIONE 25

extern void GoToXY(int x, int y);

extern void BordiPannelloIndirizzo();

extern void BordiPannelloHome();

extern void BordiPannelloNumeroProfessori();

extern void BordiPannelloInput();

extern void BordiPannelloEliminazione();

extern void SuggerimentiIndirizzo();

extern void SuggerimentiEliminazione();

#endif //GRAFICA_H
