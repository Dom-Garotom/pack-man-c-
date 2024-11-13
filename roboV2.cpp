#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

#define ALTURA 20
#define LARGURA 20
static bool isMutante = false;

void MoveEsquerda(int *x);
void MoveDireita(int *x);
void MoveCima(int *y);
void MoveBaixo(int *y);
void ImprimeMapa(int px, int py , int cx , int cy);
void LimiteTabuleiro(int *px, int *py);
void comer(int *px , int *py , int *cx , int *cy , int *pontos);
void embaralhador(int *px , int *py , int *cx , int *cy);
void embaralhadorComida(int *cx , int *cy);

int main() {
    int px, py , cx  , cy;
    char ordem;
    int continua = 1;
    int pontos = 0;

    srand(time(0));
    embaralhador(&px, &py , &cx , &cy);

    ImprimeMapa(px, py , cx , cy) ;
    cout << endl;
    do{
        
        comer(&px, &py , &cx , &cy , &pontos);
        ImprimeMapa(px, py , cx , cy) ;
        cout << endl;
        cout << "Pontos : " << pontos << endl;
        sleep(1);


    } while (pontos < 1) ;

    return 0;
}

void comer(int *px , int *py , int *cx , int *cy , int *pontos){
    if (*px == *cx && *py == *cy){
        *pontos = *pontos + 1;
        embaralhadorComida(cx , cy);
    }


    if (*px > *cx ){
        MoveEsquerda(px);
    } 
    
    else if (*px < *cx ){
        MoveDireita(px);
    } 
    
    else if (*py > *cy ){
        MoveCima(py);
    }
    
    else if (*py < *cy ){
        MoveBaixo(py);
    }
}


void embaralhador(int *px , int *py , int *cx , int *cy){
    *px = rand() % 20 ;
    *py = rand() % 20 ;

    *cx = rand() % 20 ;
    *cy = rand() % 20 + 1;
}

void embaralhadorComida(int *cx , int *cy){
    *cx = rand() % 20 + 1;
    *cy = rand() % 20 + 1;
}


void ImprimeMapa(int px, int py , int cx , int cy) {

    int x, y;
    for (y = 0; y < ALTURA; y++) {
        for (x = 0; x < LARGURA; x++) {
            if ((px == x) && (py == y)) {
                if (isMutante){
                    cout << " $ ";
                } else {
                    cout << " @ ";
                }
            } 
            else if((cx == x) && (cy == y)) {
                cout << " # ";
            }
            
            else {
                cout << " + ";
            }
        }
        cout << endl;
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
