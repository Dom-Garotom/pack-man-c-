#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

#define ALTURA 20
#define LARGURA 20
static bool isMutante = false;

void MoveEsquerda(int *x);
void MoveDireita(int *x);
void MoveCima(int *y);
void MoveBaixo(int *y);
void ImprimeMapa(int px, int py);
void LimiteTabuleiro(int *px, int *py);

int main() {
    int px, py;
    char ordem;
    int continua = 1;

    srand(time(0));
    px = rand() % 20 + 1;
    py = rand() % 20 + 1;

    ImprimeMapa(px, py);
    while (continua) {
        ordem = getchar();
        // system("cls"); 
        
        switch (ordem) {
            case 'a': case 'A':
                MoveEsquerda(&px);
                LimiteTabuleiro(&px , &py);
                ImprimeMapa(px, py);
                break;
            case 'd': case 'D':
                MoveDireita(&px);
                LimiteTabuleiro(&px , &py);
                ImprimeMapa(px, py);
                break;
            case 'w': case 'W':
                MoveCima(&py);
                LimiteTabuleiro(&px , &py);
                ImprimeMapa(px, py);
                break;
            case 's': case 'S':
                MoveBaixo(&py);
                LimiteTabuleiro(&px , &py);
                ImprimeMapa(px, py);
                break;
            case 'q': case 'Q':
                continua = 0;
                break;
            case 'm': case 'M':
                isMutante = !isMutante;
                ImprimeMapa(px, py);
                break;
            
        }

        cout << ordem << " " << px << " " << py << "\n";
        LimiteTabuleiro(&px, &py);
    }

    return 0;
}

void ImprimeMapa(int px, int py) {

    int x, y;
    for (y = 0; y < ALTURA; y++) {
        for (x = 0; x < LARGURA; x++) {
            if ((px == x) && (py == y)) {
                if (isMutante){
                    cout << " $ ";
                } else {
                    cout << " @ ";
                }


            } else {
                cout << " + ";
            }
        }
        printf("\n");
    }
}

void LimiteTabuleiro(int *px, int *py) {
    if (*px > 19){
        *px -= 1;
        cout << endl << "Ordem invalida" << endl;
        return;
    }
    
    if (*px < 0){
        *px += 1;
        cout << endl << "Ordem invalida" << endl;
        return;
    }

    if (*py > 19){
        *py -= 1;
        cout << endl << "Ordem invalida" << endl;
        return;
    }

    if (*py < 0){
        *py += 1;
        cout << endl << "Ordem invalida" << endl;
        return;
    }


}

void MoveEsquerda(int *x) {
    *x -= 1;
}

void MoveDireita(int *x) {
    *x += 1;
    
}

void MoveCima(int *y) {
    *y -= 1;
}

void MoveBaixo(int *y) {
    *y += 1;
}
