#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 8
void imprimir (int tabuleiro[MAX][MAX]);

int main (){
    int tabuleiro[MAX][MAX], retorno = 0, x, y, aux1, aux2, k, z;
    int i, j;
    //zerando tabuleiro
    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++){
            tabuleiro[i][j] = 0;
        }
    }
    //adicionando peças às posições iniciais do jogo (peças brancas)
    for (i=0; i<MAX; i++){
        for (j=0; j<3; j++){
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)){
                tabuleiro[i][j] = 1;
            }
        }
    }
    //adicionando peças às posições iniciais do jogo (peças pretas)
    for (i=0; i<MAX; i++){
        for (j=5; j<MAX; j++){
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)){
                tabuleiro[i][j] = 2;
            }
        }
    }
    //iniciando o jogo
    printf ("Jogo iniciado! Jogador 1 com pecas 1, jogador 2 com pecas 2\n");
    imprimir(tabuleiro);
    //laço da continuidade no jogo até que alguém vença e retorno receba "1"
    while (retorno == 0){

        //laço garante que a peça a ser mexida seja válida
        aux1 = 0;
        while (aux1 == 0){
            printf ("Jogador 1, informe a posicao x e y da peca a ser mexida (peca[x][y])\n");
            scanf ("%d %d", &x, &y);
            x--;
            y--;
            if (tabuleiro[x+1][y+1] != 0 && (tabuleiro[x+2][y+2] != 0 || (tabuleiro[x+2][y+2] == 0 && tabuleiro[x+1][y+1] != 2)) && tabuleiro[x-1][y+1] != 0 && (tabuleiro[x-2][y+2] != 0 || (tabuleiro[x-2][y+2] == 0 && tabuleiro[x-1][y+1] != 2)) ){
                printf ("Essa peca nao pode se mover!\n");
            }

            else if (tabuleiro[x][y] != 1){
                printf ("opcao invalida\n");
            }
            else {
                aux1 = 1;
            }
        }

        //laço garante que o destino da peça seja valido
        aux2 = 0;
        while (aux2 == 0){
            printf ("Jogador 1, informe a posicao x e y do destino da peca a ser movida\n");
            scanf ("%d %d", &k, &z);
            k--;
            z--;
            if ((k!=x+1 && z!=y+1) && (k!=x-1 && z!=y+1) && (k!=x+2 && z!=y+2) && (k!=x-2 && z!=y+2) && (k!=x+4 && z!=y+4) && (k!=x-4 && z!=y+4)){
                printf ("opcao invalida\n");
            }
            else if (tabuleiro[k][z] != 0){
                printf ("opcao invalida\n");
            }
            else if (k==x+4 && z==y+4){
                if (tabuleiro[x+2][y+2] != 0 || tabuleiro[x+1][y+1] != 2 || tabuleiro[x+3][y+3] != 2) {
                    printf ("opcao invalida\n");
                }
                else{
                    tabuleiro[x][y] = 0;
                    tabuleiro[x+1][y+1] = 0;
                    tabuleiro[x+3][y+3] = 0;
                    tabuleiro[k][z] = 1;
                    aux2 = 1;
                }
            }
            else if (k==x-4 && z==y+4){
                if (tabuleiro[x-2][y+2] != 0 || tabuleiro[x-1][y+1] != 2 || tabuleiro[x-3][y+3] != 2) {
                    printf ("opcao invalida\n");
                }
                else{
                    tabuleiro[x][y] = 0;
                    tabuleiro[x-1][y+1] = 0;
                    tabuleiro[x-3][y+3] = 0;
                    tabuleiro[k][z] = 1;
                    aux2 = 1;
                }
            }
            else if (z<y){
                    printf ("opcao invalida\n");
                }
            else if (k==x+1 && z==y+1) {

               tabuleiro[x][y] = 0;
                tabuleiro[k][z] = 1;
                aux2 = 1;

            }
            else if (k==x-1 && z==y+1) {

                tabuleiro[x][y] = 0;
                tabuleiro[k][z] = 1;
                aux2 = 1;

            }
            else if (k==x+2 && z==y+2){
                if (tabuleiro[x+1][y+1] != 2){
                    printf ("opcao invalida\n");
                }
                else {
                    tabuleiro[x][y] = 0;
                    tabuleiro[k][z] = 1;
                    tabuleiro[x+1][y+1] = 0;
                    aux2 = 1;
                }
            }
            else if (k==x-2 && z==y+2){
                if (tabuleiro[x-1][y+1] != 2){
                    printf ("opcao invalida\n");
                }
                else{
                    tabuleiro[x][y] = 0;
                    tabuleiro[k][z] = 1;
                    tabuleiro[x-1][y+1] = 0;
                    aux2 = 1;
                }
            }
        }
        imprimir(tabuleiro);
        for (i=0; i<MAX; i++){
            if (tabuleiro[i][7] == 1){
                retorno = 1;
                printf ("Fim de jogo, jogador 1 venceu.\n");
            }
        }
        //garante que o jogo ainda nao acabou
        if (retorno == 0){
            //laço garante que a peça a ser mexida seja válida
            aux1 = 0;
            printf ("Computador esta jogando...\n");
            srand(time(NULL));
            while (aux1 == 0){

                x = rand()%7;

                y = rand()%7;
                if (tabuleiro[x-1][y-1] != 0 && (tabuleiro[x-2][y-2] != 0 || (tabuleiro[x-2][y-2] == 0 && tabuleiro[x-1][y-1] != 1)) && tabuleiro[x+1][y-1] != 0 && (tabuleiro[x+2][y-2] != 0 || (tabuleiro[x+2][y+2] == 0 && tabuleiro[x+1][y+1] != 1))){

                }

                else if (tabuleiro[x][y] != 2){

                }
                else {
                    aux1 = 1;
                }
            }

            //laço garante que o destino da peça seja valido
            aux2 = 0;
            srand(time(NULL));
            while (aux2 == 0){

                k = rand()%7;

                z = rand() %7;

                if ((k!=x-1 && z!=y-1) && (k!=x+1 && z!=y-1) && (k!=x-2 && z!=y-2) && (k!=x+2 && z!=y-2) && (k!=x-4 && z!= y-4) && (k!=x+4 && z!=y-4)){

                }
                else if (tabuleiro[k][z] != 0){

                }
                else if (k==x+4 && z==y-4){
                    if (tabuleiro[x+2][y-2] != 0 || tabuleiro[x+1][y-1] != 1 || tabuleiro[x+3][y-3] != 1) {

                    }
                    else{
                        tabuleiro[x][y] = 0;
                        tabuleiro[x+1][y-1] = 0;
                        tabuleiro[x+3][y-3] = 0;
                        tabuleiro[k][z] = 2;
                        aux2 = 1;
                    }
                }
                else if (k==x-4 && z==y-4){
                    if (tabuleiro[x-2][y-2] != 0 || tabuleiro[x-1][y-1] != 1 || tabuleiro[x-3][y-3] != 1) {

                    }
                    else{
                        tabuleiro[x][y] = 0;
                        tabuleiro[x-1][y-1] = 0;
                        tabuleiro[x-3][y-3] = 0;
                        tabuleiro[k][z] = 2;
                        aux2 = 1;
                    }
                }
                else if (z>y){

                }
                else if (k==x-1 && z==y-1) {
                    tabuleiro[x][y] = 0;
                    tabuleiro[k][z] = 2;
                    aux2 = 1;

                }
                else if (k==x+1 && z==y-1) {
                    tabuleiro[x][y] = 0;
                    tabuleiro[k][z] = 2;
                    aux2 = 1;

                }
                else if (k==x-2 && z==y-2){
                    if (tabuleiro[x-1][y-1] != 1){

                    }
                    else {
                        tabuleiro[x][y] = 0;
                        tabuleiro[k][z] = 2;
                        tabuleiro[x-1][y-1] = 0;
                        aux2 = 1;
                    }
                }
                else if (k==x+2 && z==y-2){
                    if (tabuleiro[x+1][y-1] != 1){

                    }
                    else{
                        tabuleiro[x][y] = 0;
                        tabuleiro[k][z] = 2;
                        tabuleiro[x+1][y-1] = 0;
                        aux2 = 1;
                    }
                }
            }
            imprimir(tabuleiro);
            for (i=0; i<MAX; i++){
                if (tabuleiro[i][0] == 2){
                    retorno = 1;
                    printf ("Fim de jogo, CPU venceu.\n");
                }
            }
        }

    }


return 0;




}

void imprimir(int tabuleiro[MAX][MAX]){
    int i, j;
    for (i=0; i<MAX; i++){
        for (j=0; j<MAX; j++){
            printf (" %d ", tabuleiro[i][j]);
        }
        printf ("\n");
    }
}

