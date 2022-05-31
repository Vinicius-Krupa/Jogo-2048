#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <time.h>

// definindo as setas do teclado, o pause e alguns numeros

#define CIMA 72
#define BAIXO 80
#define ESQUERDA 75
#define DIREITA 77
#define PAUSE 112
#define UM 49
#define DOIS 50
#define TRES 51
#define QUATRO 52
#define CINCO 53
#define NOVE 57

/* Projeto Jogo 2048 */

// Declarando as cores que podem ser usadas

//   Nome da cor da letra   int
enum{BLACK,            //    0
	 BLUE,             //    1
	 GREEN,            //    2
	 CYAN,             //    3
	 RED,              //    4
	 MAGENTA,          //    5
	 BROWN,            //    6
	 LIGHTGRAY,        //    7
	 DARKGRAY,         //    8
	 LIGHTBLUE,        //    9
	 LIGHTGREEN,       //    10
	 LIGHTCYAN,        //    11
	 LIGHTRED,         //    12
	 LIGHTMAGENTA,     //    13
	 YELLOW,           //    14
	 WHITE             //    15
};

//   Nome da cor do fundo   int
enum{_BLACK = 0,        //    0
	 _BLUE = 16,        //    16
	 _GREEN = 32,       //    32
	 _CYAN = 48,        //    48
	 _RED = 64,         //    64
	 _MAGENTA = 80,     //    80
	 _BROWN = 96,       //    96
	 _LIGHTGRAY = 112,  //    112
	 _DARKGRAY = 128,   //    128
	 _LIGHTBLUE = 144,  //    144
	 _LIGHTGREEN = 160, //    160
	 _LIGHTCYAN = 176,  //    176
	 _LIGHTRED = 192,   //    192
	 _LIGHTMAGENTA = 208, //  208
	 _YELLOW = 224,     //    224
	 _WHITE = 240       //    240
};

// Função para adicionar as cores
void textColor(int letras, int fundo){
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
							 letras + fundo);
}

// Variáveis universais
char loginCadastro1[16], senhaCadastro1[16], confirmarSenha1[16], jogador1[16], loginCadastro2[16], senhaCadastro2[16], confirmarSenha2[16], jogador2[16];
char loginLogin[16], senhaLogin[16], jogadorLogado[16];
char jogadorRankingFacil1[16], jogadorRankingFacil2[16], jogadorRankingFacil3[16], jogadorRankingFacil4[16], jogadorRankingFacil5[16];
char jogadorRankingMedio1[16], jogadorRankingMedio2[16], jogadorRankingMedio3[16], jogadorRankingMedio4[16], jogadorRankingMedio5[16];
char jogadorRankingDificil1[16], jogadorRankingDificil2[16], jogadorRankingDificil3[16], jogadorRankingDificil4[16], jogadorRankingDificil5[16];

int matriz[6][6] = {0}, score = 0, rankingFacil[5], rankingMedio[5], rankingDificil[5];

// Função para mudar a cor do fundo dependendo do número
void coresDosNumeros(int i, int j){
	if(matriz[i][j] == 0){
					printf("      ");
				} else if(matriz[i][j] == 2) {
					printf(" ");
					textColor(BLACK, _LIGHTGRAY);
					printf("  %d  ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 4) {
					printf(" ");
					textColor(BLACK, _DARKGRAY);
					printf("  %d  ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 8) {
					printf(" ");
					textColor(BLACK, _LIGHTRED);
					printf("  %d  ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 16) {
					printf(" ");
					textColor(BLACK, _RED);
					printf(" %d  ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 32) {
					printf(" ");
					textColor(BLACK, _LIGHTMAGENTA);
					printf(" %d  ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 64) {
					printf(" ");
					textColor(BLACK, _MAGENTA);
					printf(" %d  ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 128) {
					printf(" ");
					textColor(BLACK, _BROWN);
					printf(" %d ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 256) {
					printf(" ");
					textColor(BLACK, _LIGHTBLUE);
					printf(" %d ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 512) {
					printf(" ");
					textColor(BLACK, _BLUE);
					printf(" %d ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else if(matriz[i][j] == 1024) {
					printf(" ");
					textColor(BLACK, _LIGHTGREEN);
					printf("%d ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				} else {
					printf(" ");
					textColor(BLACK, _GREEN);
					printf("%d ", matriz[i][j]);
					textColor(BLACK, _WHITE);
				}
}

// Função que mostra o tabuleiro
void mostrarMatriz(int tamanhoTabuleiro){
	system("cls");
	
	textColor(BLACK, _WHITE);
	
	int i, j;
	
	
	
	if(tamanhoTabuleiro == 4){
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\tMelhor Pontuação: %d                 Jogando: %s\n\n\n\n", rankingDificil[0], jogadorLogado);
	
		printf("\t\t\t\t\t\t\t\t    Pontuação: %d\n", score);
		
		printf("\t\t\t\t\t\t\t\t _______________________\n");
		for(i = 0; i < tamanhoTabuleiro; i++) {
			printf("\t\t\t\t\t\t\t\t|     |     |     |     |\n");
			printf("\t\t\t\t\t\t\t\t");
			for(j = 0; j < tamanhoTabuleiro; j++){
				coresDosNumeros(i, j);
			}
			printf("\n");
			printf("\t\t\t\t\t\t\t\t|     |     |     |     |\n");
			printf("\t\t\t\t\t\t\t\t-------------------------\n");
		}	
	}
	
	if(tamanhoTabuleiro == 5){
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\tMelhor Pontuação: %d                 Jogando: %s\n\n\n\n", rankingMedio[0], jogadorLogado);
	
		printf("\t\t\t\t\t\t\t\t    Pontuação: %d\n", score);
	
		printf("\t\t\t\t\t\t\t\t _____________________________\n");
		for(i = 0; i < tamanhoTabuleiro; i++) {
			printf("\t\t\t\t\t\t\t\t|     |     |     |     |     |\n");
			printf("\t\t\t\t\t\t\t\t");
			for(j = 0; j < tamanhoTabuleiro; j++){
				coresDosNumeros(i, j);
			}
			printf("\n");
			printf("\t\t\t\t\t\t\t\t|     |     |     |     |     |\n");
			printf("\t\t\t\t\t\t\t\t-------------------------------\n");
		}
	}
	
	if(tamanhoTabuleiro == 6){
		printf("\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\tMelhor Pontuação: %d                 Jogando: %s\n\n\n\n", rankingFacil[0], jogadorLogado);
	
		printf("\t\t\t\t\t\t\t\t    Pontuação: %d\n", score);
		
		printf("\t\t\t\t\t\t\t\t ___________________________________\n");
		for(i = 0; i < tamanhoTabuleiro; i++) {
			printf("\t\t\t\t\t\t\t\t|     |     |     |     |     |     |\n");
			printf("\t\t\t\t\t\t\t\t");
			for(j = 0; j < tamanhoTabuleiro; j++){
				coresDosNumeros(i, j);
			}
			printf("\n");
			printf("\t\t\t\t\t\t\t\t|     |     |     |     |     |     |\n");
			printf("\t\t\t\t\t\t\t\t-------------------------------------\n");
		}
	}
	printf("\n\n\t\t\t\t\t\tUtilize as setas do teclado para movimentar os numeros.\n\n");
	printf("\t\t\t\t\t\t\t\t\t[P] - Pausar\n\n");
}

// Função que zera a matriz para iniciar um novo jogo
void zerarMatriz(){
	int i, j;
	
	for(i = 0; i < 6; i++){
		for(j = 0; j < 6; j++){
			matriz[i][j] = 0;
		}
	}
}

//Função para gerar um 2 ou 4 aleatóriamente com 90% de chance de ser 2
int geraValor() {
	int valor = 0;
	
	srand(time(NULL));
	valor = rand() % 11;
	
	if(valor <= 9) {
		valor = 2;
	} else {
		valor = 4;
	}
	return valor;
}

// Função que preenche uma casa do tabuleiro com 2 ou 4
void preencherTabuleiro(int tamanhoTabuleiro){
	int linha, coluna;
	
	srand(time(NULL));

    do{
        linha = rand()%tamanhoTabuleiro;
        coluna = rand()%tamanhoTabuleiro;

    }while(matriz[linha][coluna] != 0);
    
    matriz[linha][coluna] = geraValor();
}

// Função que somente verifica se pode movimentar para a esquerda
int permitidoIrParaEsquerda(int tamanhoTabuleiro){
	int i, j;
	int mover = 0;
	
	for(i = 0; i < tamanhoTabuleiro; i++){
		for(j = tamanhoTabuleiro - 1; j > 0; j--){
			if(matriz[i][j] != 0){
				if((matriz[i][j-1] == 0 || matriz[i][j] == matriz[i][j-1])){
					mover = 1;
				}
			}
		}
	}
	return mover;
}

// Movimentando para esquerda
void movimentaEsquerda(int tamanhoTabuleiro){
	int i, j;
	int moverColuna = 0;
	int moverColunaSoma = 0;
	
	for(i = 0; i < tamanhoTabuleiro; i++){
		moverColuna = 0;
		for(j = 0; j < tamanhoTabuleiro; j++){
			if(matriz[i][j] != 0){
			    matriz[i][moverColuna] = matriz[i][j];
			    moverColuna++;
			}
		}
		for(j = moverColuna; j < tamanhoTabuleiro; j++){			
			matriz[i][j] = 0;
		}
	}
	i = 0;
	// While pra ver se os valores sao iguais, caso for soma os valores
	while(i < tamanhoTabuleiro){
		moverColunaSoma = 0;
		for(j = 0; j < tamanhoTabuleiro; j++){
			if(matriz[i][j] != 0){
				if(matriz[i][j] == matriz[i][j+1]){
					matriz[i][moverColunaSoma] = 2*matriz[i][j];
					score += matriz[i][moverColunaSoma];	
					matriz[i][moverColunaSoma+1] = 0;
					moverColunaSoma++;
				}else{
				   	matriz[i][moverColunaSoma] = matriz[i][j];
				   	moverColunaSoma++;
				}
			}
		}
		j = moverColunaSoma;
		while(j < tamanhoTabuleiro){
			matriz[i][j] = 0;		
			j++;
		}
		i++;			
	}
}

// Função que somente verifica se pode movimentar para a direita
int permitidoIrParaDireita(int tamanhoTabuleiro){
	int i, j;
	int mover = 0;
	
	for(i = 0; i < tamanhoTabuleiro; i++){
		for(j = 0; j < tamanhoTabuleiro - 1; j++){
			if(matriz[i][j] != 0){
				if((matriz[i][j+1] == 0 || matriz[i][j] == matriz[i][j+1])){
					mover = 1;
				}
			}
		}
	}
	return mover;
}


// Movimentando para direita
void movimentaDireita(int tamanhoTabuleiro){
	int i, j;
	int moverColuna = 0;
	int moverColunaSoma = 0;
	
	for(i = 0; i < tamanhoTabuleiro; i++){
		moverColuna = tamanhoTabuleiro - 1;
		for(j = tamanhoTabuleiro - 1; j >= 0; j--){
			if(matriz[i][j] != 0){
				matriz[i][moverColuna] = matriz[i][j];
				moverColuna--;
			}
		}
		for(j = moverColuna; j >= 0; j--){
			matriz[i][j] = 0;
		}
	}
	i = 0;
	// While pra ver se os valores sao iguais, caso for soma os valores
	while(i < tamanhoTabuleiro){
		moverColunaSoma = tamanhoTabuleiro - 1;
		for(j = tamanhoTabuleiro - 1; j >= 0; j--){
			if(matriz[i][j] != 0){
				if(matriz[i][j] == matriz[i][j-1]){
					matriz[i][moverColunaSoma] = 2*matriz[i][j];
					score += matriz[i][moverColunaSoma];
					j--;
					moverColunaSoma--;
				}else{
					matriz[i][moverColunaSoma] = matriz[i][j];
					moverColunaSoma--;
				}
			}
		}
		for(j = moverColunaSoma; j >= 0; j--){
			matriz[i][j] = 0;
		}
		i++;
	}
}


// Função que somente verifica se pode movimentar para cima
int permitidoIrParaCima(int tamanhoTabuleiro){
	int i, j;
	int mover = 0;
	
	for (i = tamanhoTabuleiro - 1; i > 0; i--){
		for(j = 0; j < tamanhoTabuleiro; j++){
			if(matriz[i][j] != 0){
				if((matriz[i-1][j] == 0 || matriz[i][j] == matriz[i-1][j])){
					mover = 1;
				}
			}
		}
	}
	return mover;
}

// Movimentando para cima
void movimentaCima(int tamanhoTabuleiro){
	int i, j;
	int moverLinha = 0;
	int moverLinhaSoma = 0;
	
	for(j = 0; j < tamanhoTabuleiro; j++){
		moverLinha = 0;
		for(i = 0; i < tamanhoTabuleiro; i++){
			if(matriz[i][j] != 0){
			    matriz[moverLinha][j] = matriz[i][j];
			    moverLinha++;
			}
		}
		for(i = moverLinha; i < tamanhoTabuleiro; i++){			
			matriz[i][j] = 0;
		}
	}
	j = 0;
	// While pra ver se os valores sao iguais, caso for soma os valores
	while(j < tamanhoTabuleiro){
		moverLinhaSoma = 0;
		for(i = 0; i < tamanhoTabuleiro; i++){
			if(matriz[i][j] != 0){
				if(matriz[i][j] == matriz[i+1][j]){
					matriz[moverLinhaSoma][j] = 2*matriz[i][j];
					score += matriz[moverLinhaSoma][j];	
					matriz[moverLinhaSoma+1][j] = 0;
					moverLinhaSoma++;
				}else{
				   	matriz[moverLinhaSoma][j] = matriz[i][j];
				   	moverLinhaSoma++;
				}
			}
		}
		i = moverLinhaSoma;
		while(i < tamanhoTabuleiro){
			matriz[i][j] = 0;		
			i++;
		}
		j++;			
	}
}

// Função que somente verifica se pode movimentar para baixo
int permitidoIrParaBaixo(int tamanhoTabuleiro){
	int i, j;
	int mover = 0;
	
	for(i = 0; i < tamanhoTabuleiro - 1; i++){
		for(j = 0; j < tamanhoTabuleiro; j++){
			if(matriz[i][j] != 0){
				if((matriz[i+1][j] == 0 || matriz[i][j] == matriz[i+1][j])){
					mover = 1;
				}
			}
		}
	}
	return mover;
}

//Movimentando para baixo
void movimentaBaixo(int tamanhoTabuleiro){
	int i, j;
	int moverLinha = 0;
	int moverLinhaSoma = 0;
	
	for(j = 0; j < tamanhoTabuleiro; j++){
		moverLinha = tamanhoTabuleiro - 1;
		for(i = tamanhoTabuleiro - 1; i >= 0; i--){
			if(matriz[i][j] != 0){
				matriz[moverLinha][j] = matriz[i][j];
				moverLinha--;
			}
		}
		for(i = moverLinha; i >= 0; i--){
			matriz[i][j] = 0;
		}
	}
	j = 0;
	//While pra ver se os valores sao iguais, caso for soma os valores
	while(j < tamanhoTabuleiro){
		moverLinhaSoma = tamanhoTabuleiro - 1;
		for(i = tamanhoTabuleiro - 1; i >= 0; i--){
			if(matriz[i][j] != 0){
				if(matriz[i][j] == matriz[i-1][j]){
					matriz[moverLinhaSoma][j] = 2*matriz[i][j];
					score += matriz[moverLinhaSoma][j];
					i--;
					moverLinhaSoma--;
				}else{
					matriz[moverLinhaSoma][j] = matriz[i][j];
					moverLinhaSoma--;
				}
			}
		}
		for(i = moverLinhaSoma; i >= 0;i--){
			matriz[i][j] = 0;
		}
		j++;
	}
}

void animacaoDeLoading(){
	int i, j;
					
	for (i = 0; i < 5; i++) {
    	printf("\t\t\t\t\t\t\t\t      Loading");
      	for (j = 0; j < 3; j++) {
            printf(".");
            Sleep(200);
        }
        printf("\r");
        for (j = 0; j < 150; j++) {
            printf(" ");
        }
        printf("\r");
    }
}

// Função que alimenta o ranking no final de cada jogo
void inserirDadosNoRanking(int tamanhoTabuleiro){
	int i;
	
	switch(tamanhoTabuleiro){
		case 4:
			if(score > rankingDificil[0]){
				for(i = 4; i > 0; i--){
					rankingDificil[i] = rankingDificil[i-1];
				}
				strcpy(jogadorRankingDificil5, jogadorRankingDificil4);
				strcpy(jogadorRankingDificil4, jogadorRankingDificil3);
				strcpy(jogadorRankingDificil3, jogadorRankingDificil2);
				strcpy(jogadorRankingDificil2, jogadorRankingDificil1);
				
				rankingDificil[0] = score;
				strcpy(jogadorRankingDificil1, jogadorLogado);
				
			} else if(score > rankingDificil[1]){
				for(i = 4; i > 1; i--){
					rankingDificil[i] = rankingDificil[i-1];
				}
				strcpy(jogadorRankingDificil5, jogadorRankingDificil4);
				strcpy(jogadorRankingDificil4, jogadorRankingDificil3);
				strcpy(jogadorRankingDificil3, jogadorRankingDificil2);
				
				rankingDificil[1] = score;
				strcpy(jogadorRankingDificil2, jogadorLogado);
				
			} else if(score > rankingDificil[2]){
				for(i = 4; i > 2; i--){
					rankingDificil[i] = rankingDificil[i-1];
				}
				strcpy(jogadorRankingDificil5, jogadorRankingDificil4);
				strcpy(jogadorRankingDificil4, jogadorRankingDificil3);
				
				rankingDificil[2] = score;
				strcpy(jogadorRankingDificil3, jogadorLogado);
				
			} else if(score > rankingDificil[3]){
				for(i = 4; i > 3; i--){
					rankingDificil[i] = rankingDificil[i-1];
				}
				strcpy(jogadorRankingDificil5, jogadorRankingDificil4);
				
				rankingDificil[3] = score;
				strcpy(jogadorRankingDificil4, jogadorLogado);
				
			} else if(score > rankingDificil[4]){
				rankingDificil[4] = score;
				strcpy(jogadorRankingDificil5, jogadorLogado);
			}
				break;
		case 5:
			if(score > rankingMedio[0]){
				for(i = 4; i > 0; i--){
					rankingMedio[i] = rankingMedio[i-1];
				}
				strcpy(jogadorRankingMedio5, jogadorRankingMedio4);
				strcpy(jogadorRankingMedio4, jogadorRankingMedio3);
				strcpy(jogadorRankingMedio3, jogadorRankingMedio2);
				strcpy(jogadorRankingMedio2, jogadorRankingMedio1);
				
				rankingMedio[0] = score;
				strcpy(jogadorRankingMedio1, jogadorLogado);
				
			} else if(score > rankingMedio[1]){
				for(i = 4; i > 1; i--){
					rankingMedio[i] = rankingMedio[i-1];
				}
				strcpy(jogadorRankingMedio5, jogadorRankingMedio4);
				strcpy(jogadorRankingMedio4, jogadorRankingMedio3);
				strcpy(jogadorRankingMedio3, jogadorRankingMedio2);
				
				rankingMedio[1] = score;
				strcpy(jogadorRankingMedio2, jogadorLogado);
				
			} else if(score > rankingMedio[2]){
				for(i = 4; i > 2; i--){
					rankingMedio[i] = rankingMedio[i-1];
				}
				strcpy(jogadorRankingMedio5, jogadorRankingMedio4);
				strcpy(jogadorRankingMedio4, jogadorRankingMedio3);
				
				rankingMedio[2] = score;
				strcpy(jogadorRankingMedio3, jogadorLogado);
				
			} else if(score > rankingMedio[3]){
				for(i = 4; i > 3; i--){
					rankingMedio[i] = rankingMedio[i-1];
				}
				strcpy(jogadorRankingMedio5, jogadorRankingMedio4);
				
				rankingMedio[3] = score;
				strcpy(jogadorRankingMedio4, jogadorLogado);
				
			} else if(score > rankingMedio[4]){
				rankingMedio[4] = score;
				strcpy(jogadorRankingMedio5, jogadorLogado);
			}
				break;
		case 6:
			if(score > rankingFacil[0]){
				for(i = 4; i > 0; i--){
					rankingFacil[i] = rankingFacil[i-1];
				}
				strcpy(jogadorRankingFacil5, jogadorRankingFacil4);
				strcpy(jogadorRankingFacil4, jogadorRankingFacil3);
				strcpy(jogadorRankingFacil3, jogadorRankingFacil2);
				strcpy(jogadorRankingFacil2, jogadorRankingFacil1);
				
				rankingFacil[0] = score;
				strcpy(jogadorRankingFacil1, jogadorLogado);
				
			} else if(score > rankingFacil[1]){
				for(i = 4; i > 1; i--){
					rankingFacil[i] = rankingFacil[i-1];
				}
				strcpy(jogadorRankingFacil5, jogadorRankingFacil4);
				strcpy(jogadorRankingFacil4, jogadorRankingFacil3);
				strcpy(jogadorRankingFacil3, jogadorRankingFacil2);
				
				rankingFacil[1] = score;
				strcpy(jogadorRankingFacil2, jogadorLogado);
				
			} else if(score > rankingFacil[2]){
				for(i = 4; i > 2; i--){
					rankingFacil[i] = rankingFacil[i-1];
				}
				strcpy(jogadorRankingFacil5, jogadorRankingFacil4);
				strcpy(jogadorRankingFacil4, jogadorRankingFacil3);
				
				rankingFacil[2] = score;
				strcpy(jogadorRankingFacil3, jogadorLogado);
				
			} else if(score > rankingFacil[3]){
				for(i = 4; i > 3; i--){
					rankingFacil[i] = rankingFacil[i-1];
				}
				strcpy(jogadorRankingFacil5, jogadorRankingFacil4);
				
				rankingFacil[3] = score;
				strcpy(jogadorRankingFacil4, jogadorLogado);
				
			} else if(score > rankingFacil[4]){
				rankingFacil[4] = score;
				strcpy(jogadorRankingFacil5, jogadorLogado);
			}
			break;
	}
	
}

void telaCarregamento(){
	system("cls");
	
	textColor(LIGHTGREEN, _BLACK);
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                            IIII                                                                                                       \n");
	printf("                                            IIII                                                                                                       \n");
	printf("                                                                                                                                                       \n");
	printf("         UUUU      UUUU  NNNNNN        NNN  IIII  FFFFFFFFFFFFFF      AA          CCCCCCCCCCC  EEEEEEEEEEEEEE         AA         RRRRRRRRRRR      @@   \n");
	printf("         UUUU      UUUU  NNNNNNN       NNN  IIII  FFFFFFFFFFFFFF     AAAA        CCCCCCCCCCCC  EEEEEEEEEEEEEE        AAAA        RRRRRRRRRRRR    @A @  \n");
	printf("         UUUU      UUUU  NNN  NNN      NNN  IIII  FFFF              AAAAAA       CCCC          EEEE                 AAAAAA       RRRR      RRR    @@   \n");
	printf("         UUUU      UUUU  NNN   NNN     NNN  IIII  FFFF             AAAAAAAA      CCCC          EEEE                AAAAAAAA      RRRR     RRR          \n");
	printf("         UUUU      UUUU  NNN    NNN    NNN  IIII  FFFFFFFFFF      AAA    AAA     CCCC          EEEEEEEEEE         AAA    AAA     RRRRRRRRRRR           \n");
	printf("         UUUU      UUUU  NNN     NNN   NNN  IIII  FFFFFFFFFF     AAAA    AAAA    CCCC          EEEE              AAAA    AAAA    RRRR  RRRR            \n");
	printf("         UUUU      UUUU  NNN      NNN  NNN  IIII  FFFF          AAAAAAAAAAAAAA   CCCC          EEEE             AAAAAAAAAAAAAA   RRRR   RRRR           \n");
	printf("          UUUUUUUUUUUU   NNN       NNNNNNN  IIII  FFFF         AAAA        AAAA  CCCCCCCCCCCC  EEEEEEEEEEEEEE  AAAA        AAAA  RRRR    RRRR          \n");
	printf("           UUUUUUUUUU    NNN        NNNNNN  IIII  FFFF        AAAAA        AAAAA  CCCCCCCCCCC  EEEEEEEEEEEEEE AAAAA        AAAAA RRRR     RRRR         \n"); textColor(WHITE, _BLACK);
	printf("                                                                                                                                                       \n");			
	printf("                                                  GGGGG      A     MMM    MMM EEEEEE      SSSSSSS TTTTTT UU   UU DDDDDD   II   OOOOOO   SSSSSSS        \n");
	printf("                                                  GG        A A    MM M  M MM EE          SS        TT   UU   UU DD   DD  II  OO    OO  SS             \n");
	printf("                                                  GG  GG   AAAAA   MM  MM  MM EEEEE         SSS     TT   UU   UU DD    DD II OO      OO   SSS          \n");
	printf("                                                  GG   G  AA   AA  MM      MM EE               SS   TT   UU   UU DD   DD  II  OO    OO       SS        \n");			
	printf("                                                  GGGGGG AA     AA MM      MM EEEEEE      SSSSSSS   TT    UUUUU  DDDDDD   II   OOOOOO   SSSSSSS        \n\n\n\n\n\n\n\n\n");
	printf("               by: Vinicius Krupa de Oliveira");
	
	Sleep(10000);
}

void telaMenu(){
	system("cls");
	
	int opcao = 0;
	
	printf("\n\n\n\n\n");
	printf("                           222222222222222           000000000              444444444         888888888     \n"); Sleep(50);
    printf("                          2:::::::::::::::22       00:::::::::00           4::::::::4       88:::::::::88   \n"); Sleep(50);
    printf("                          2::::::222222:::::2    00:::::::::::::00        4:::::::::4     88:::::::::::::88 \n"); Sleep(50);
    printf("                          2222222     2:::::2   0:::::::000:::::::0      4::::44::::4    8::::::88888::::::8\n"); Sleep(50);
    printf("                                      2:::::2   0::::::0   0::::::0     4::::4 4::::4    8:::::8     8:::::8\n"); Sleep(50);
    printf("                                      2:::::2   0:::::0     0:::::0    4::::4  4::::4    8:::::8     8:::::8\n"); Sleep(50);
    printf("                                   2222::::2    0:::::0     0:::::0   4::::4   4::::4     8:::::88888:::::8 \n"); Sleep(50);
    printf("                              22222::::::22     0:::::0 000 0:::::0  4::::444444::::444    8:::::::::::::8  \n"); Sleep(50);
    printf("                            22::::::::222       0:::::0 000 0:::::0  4::::::::::::::::4   8:::::88888:::::8 \n"); Sleep(50);
    printf("                           2:::::22222          0:::::0     0:::::0  4444444444:::::444  8:::::8     8:::::8\n"); Sleep(50);
    printf("                          2:::::2               0:::::0     0:::::0            4::::4    8:::::8     8:::::8\n"); Sleep(50);
    printf("                          2:::::2               0::::::0   0::::::0            4::::4    8:::::8     8:::::8\n"); Sleep(50);
    printf("                          2:::::2       222222  0:::::::000:::::::0            4::::4    8::::::88888::::::8\n"); Sleep(50);
    printf("                          2::::::2222222:::::2   00:::::::::::::00           44::::::44   88:::::::::::::88 \n"); Sleep(50);
    printf("                          2::::::::::::::::::2     00:::::::::00             4::::::::4     88:::::::::88   \n"); Sleep(50);
    printf("                          22222222222222222222       000000000               4444444444       888888888     \n"); Sleep(50);

    printf("\n\n\n"); Sleep(1000); 
	printf("                               | 1: Cadastrar |       | 2: Entrar     |       | 3: Jogar sem cadastro | \n\n\n");
	textColor(BROWN, BLACK);
	printf("                                                   YYYYYYYYYYYYYYYY                          \n"); 
	printf("                                                YYYY:::::::::::::::YYYY                      \n"); 
	printf("                                               Y    Y:::::::::::::Y    Y                     \n"); 
	printf("                                              Y     Y:::::::::::::Y     Y                    \n"); 
	printf("                                              YYYYYYYY:::::::::::YYYYYYYY                    \n"); 
	printf("                                                      Y:::::::::Y                            \n"); 
	printf("                                                        YY:::YY                              \n"); 
	printf("                                                          Y:Y                                \n"); 
	printf("                                                          Y:Y                                \n"); 
	printf("                                                     YYYYYYYYYYYYY                           \n"); 
	printf("                                                     Y:::::::::::Y                           \n"); 
	printf("                                                     YYYYYYYYYYYYY                           \n\n"); 
	
	printf("                                                     | 4: Ranking |                        \n\n");
	textColor(WHITE, _BLACK);
	printf("                                                   | 5: Instruções  |\n");
	
	opcao = getch();
	
	switch(opcao){
		case UM:
			system("cls");
			
			telaCadastro();
			break;
			
		case DOIS:
			system("cls");
			telaLogin();
			break;
				
		case TRES:
			system("cls");
			telaModos();
			break;	
	
		case QUATRO:
			ranking:
			system("cls");
			telaRanking(); 
			break;
		
		case CINCO:
			telaInstrucoes();
			break;
		default:
			printf("\n\t\t\t\t\t\t Opção inválida! Aguarde para tentar novamente...\n\n");
			animacaoDeLoading();
			system("cls");
			telaMenu();
			break;
	}	
}

void telaCadastro(){
	system("cls");
	
	int quantidadeUsuarios = 0;
	
	printf("................................................................................................................................................\n");
	printf("................................................................................................................................................\n");
	printf("................................................................................................................................................\n");
	printf(".......                                                                                                                                  .......\n");
	printf(".......   CCCCCCCCCCC         AA         DDDDDDDDD            AA          SSSSSSSSSSSS  TTTTTTTTTTTTTT  RRRRRRRRRR      OOOOOOOOOOO      .......\n");
	printf(".......  CCCCCCCCCCCC        AAAA        DDDDDDDDDDD         AAAA        SSSSSSSSSSSSS  TTTTTTTTTTTTTT  RRRRRRRRRRR    OOOOOOOOOOOOO     .......\n");
	printf(".......  CCCC               AAAAAA       DDD      DDD       AAAAAA        SSSSS              TTTT       RRR       RR  OOO         OOO    .......\n");
	printf(".......  CCCC              AAAAAAAA      DDD       DDD     AAAAAAAA          SSS             TTTT       RRR      RR  OOO           OOO   .......\n");
	printf(".......  CCCC             AAA    AAA     DDD       DDD    AAA    AAA           SSSSSS        TTTT       RRRRRRRRRR   OOO           OOO   .......\n");
	printf(".......  CCCC            AAAA    AAAA    DDD       DDD   AAAA    AAAA              SSS       TTTT       RRR   RRR    OOO           OOO   .......\n");
	printf(".......  CCCC           AAAAAAAAAAAAAA   DDD      DDD   AAAAAAAAAAAAAA            SSSSS      TTTT       RRR    RRR    OOO         OOO    .......\n");
	printf(".......  CCCCCCCCCCCC  AAAA        AAAA  DDDDDDDDDDD   AAAA        AAAA   SSSSSSSSSSSSS      TTTT       RRR     RRR    OOOOOOOOOOOOO     .......\n");
	printf(".......   CCCCCCCCCCC AAAAA        AAAAA DDDDDDDDD    AAAAA        AAAAA  SSSSSSSSSSSS       TTTT       RRR      RRR    OOOOOOOOOOO      .......\n");
	printf(".......                                                                                                                                  .......\n");					
	printf("................................................................................................................................................\n");
	printf("................................................................................................................................................\n");
	printf("................................................................................................................................................\n");

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 9: Voltar |");
	printf("\n");		

	printf("Informe quantos usuários deseja cadastrar (max 2)\n");
	
	quantidadeUsuarios = getch();
	
	switch(quantidadeUsuarios){
		int i, c;
		
		case UM:
			printf("\n\t\t\t\t\t\tPARA EVITAR QUALQUER TIPO DE ERRO NÃO USE ESPAÇOS\n");
			printf("\n\t\t\t\t\t\tPressione 2 vezes ENTER após digitar as senhas para confirmar\n\n");
			printf("                                                              ---------------------------\n");	
			printf("                                                               Nickname: ");
			scanf("%s", &jogador1);
			fflush(stdin);
			
			if(strcmp(jogador1, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			printf("                                                              ---------------------------\n");
			printf("                                                               Login: ");
			scanf("%s", loginCadastro1);
			fflush(stdin);
			
			if(strcmp(loginCadastro1, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			printf("                                                              ---------------------------\n");		
			printf("                                                               Senha: ");
			
			// Código para aparecer " * " nos caracteres de senha
			for(i = 0; c != 13; i++){
				c = getch();
				if(isprint(c)){                //Analisa se o valor da variável c é imprimivel
					senhaCadastro1[i] = c;     //Se for, armazena o caractere
					printf("*"); 
				} else if(c == 8 && i){     
           			senhaCadastro1[i] = '\0';  //8 é o caractere BackSpace na tabela ASCII, && a analisa se a é diferente de 0
           			i--;
           			printf("\b \b");            //Apagando o caractere digitado 
         		}
   			}
   			scanf("%c", &c); // limpando o ENTER do buffer do teclado
			fflush(stdin);
			
			if(strcmp(senhaCadastro1, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			printf("\n                                                              ---------------------------\n");		
			printf("                                                               Confirmar Senha: ");
			for(i = 0; c != 13; i++){
				c = getch();
				if(isprint(c)){
					confirmarSenha1[i] = c;
					printf("*"); 
				} else if(c == 8 && i){     
           			confirmarSenha1[i] = '\0';
           			i--;
           			printf("\b \b");       
         		}
   			}
			fflush(stdin);
			printf("\n                                                              ---------------------------\n");
			
			if(strcmp(confirmarSenha1, "9") == 0) {
				system("cls");
				telaMenu();
			}
				
			if(strcmp(senhaCadastro1, confirmarSenha1) == 0){
				printf("\n\t\t\t\t\t\t\t   Cadastro realizado com sucesso!\n\n");
					
				animacaoDeLoading();
				telaLogin();
					
			}else{
				printf("\n\t\t\t\t\t\t\t   As senhas não são iguais! \n\n");
				
				animacaoDeLoading();
				telaCadastro();
			}
		break;
				
		case DOIS:
			printf("\n\t\t\t\t\t\tPARA EVITAR QUALQUER TIPO DE ERRO NÃO USE ESPAÇOS\n");
			printf("\n\t\t\t\t\t\tPressione 2 vezes ENTER após digitar as senhas para confirmar\n\n");
			printf("\n                                                                       Jogador 1\n\n");
			printf("                                                              ---------------------------\n");	
			printf("                                                               Nickname: ");
			scanf("%s", jogador1);
			fflush(stdin);
			
			if(strcmp(jogador1, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			printf("                                                              ---------------------------\n");
			printf("                                                               Login: ");
			scanf("%s", loginCadastro1);
			fflush(stdin);
			
			if(strcmp(loginCadastro1, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			printf("                                                              ---------------------------\n");		
			printf("                                                               Senha: ");
			for(i = 0; c != 13; i++){
				c = getch();
				if(isprint(c)){
					senhaCadastro1[i] = c;
					printf("*"); 
				} else if(c == 8 && i){     
           			senhaCadastro1[i] = '\0';
           			i--;
           			printf("\b \b");       
         		}
   			}
   			scanf("%c", &c); // limpando o ENTER do buffer do teclado
			fflush(stdin);
			
			if(strcmp(senhaCadastro1, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			printf("\n                                                              ---------------------------\n");		
			printf("                                                               Confirmar Senha: ");
			for(i = 0; c != 13; i++){
				c = getch();
				if(isprint(c)){
					confirmarSenha1[i] = c;
					printf("*"); 
				} else if(c == 8 && i){     
           			confirmarSenha1[i] = '\0';
           			i--;
           			printf("\b \b");       
         		}
   			}
   			scanf("%c", &c); // limpando o ENTER do buffer do teclado
			fflush(stdin);
			printf("\n                                                              ---------------------------\n");
			
			if(strcmp(confirmarSenha1, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			if(strcmp(senhaCadastro1, confirmarSenha1) == 0){
				printf("\n\t\t\t\t\t\t\t   Cadastro realizado com sucesso!\n  ");
					
			}else{
				printf("\n\t\t\t\t\t\t\t   As senhas não são iguais!\n\n");
				animacaoDeLoading();
				telaCadastro();
			}
			
			cadastro2:
						
			printf("\n                                                                       Jogador 2\n\n");
			printf("                                                              ---------------------------\n");	
			printf("                                                               Nickname: ");
			scanf("%s", jogador2);
			
			if(strcmp(jogador1, jogador2) == 0){
				printf("\n\t\t\t\t\t\t\t   Nickname já existe! Tente novamente.\n\n");
				goto cadastro2;
			}
			
			if(strcmp(jogador2, "9") == 0) {
				system("cls");
				telaMenu();
			}
					
			printf("                                                              ---------------------------\n");
			printf("                                                               Login: ");
			scanf("%s", loginCadastro2);
			fflush(stdin);
			
			if(strcmp(loginCadastro2, loginCadastro1) == 0){
				printf("\n\t\t\t\t\t\t\t   Login já existe! Tente novamente.\n\n");
				goto cadastro2;
			}
			
			if(strcmp(loginCadastro2, "9") == 0) {
				goto cadastro2;
			}
					
			printf("                                                              ---------------------------\n");		
			printf("                                                               Senha: ");
			for(i = 0; c != 13; i++){
				c = getch();
				if(isprint(c)){
					senhaCadastro2[i] = c;
					printf("*"); 
				} else if(c == 8 && i){     
           			senhaCadastro2[i] = '\0';
           			i--;
           			printf("\b \b");       
         		}
   			}
   			scanf("%c", &c); // limpando o ENTER do buffer do teclado
			fflush(stdin);
			
			if(strcmp(senhaCadastro2, "9") == 0) {
				goto cadastro2;
			}
					
			printf("\n                                                              ---------------------------\n");		
			printf("                                                               Confirmar Senha: ");
			for(i = 0; c != 13; i++){
				c = getch();
				if(isprint(c)){
					confirmarSenha2[i] = c;
					printf("*"); 
				} else if(c == 8 && i){     
           			confirmarSenha2[i] = '\0';
           			i--;
           			printf("\b \b");       
         		}
   			}
			fflush(stdin);
			printf("\n                                                              ---------------------------\n");
			
			if(strcmp(confirmarSenha2, "9") == 0) {
				goto cadastro2;
			}
					
			if(strcmp(senhaCadastro2, confirmarSenha2) == 0){
				printf("\n\t\t\t\t\t\t\t   Cadastro realizado com sucesso!\n\n");
				animacaoDeLoading();
				telaLogin();
					
			}else{
				printf("\n\t\t\t\t\t\t As senhas não são iguais :/ Tente novamente.\n\n");
				animacaoDeLoading();
				goto cadastro2;	
			}
		break;
				
		case NOVE:
			system("cls");
			telaMenu();;
		break;
			
		default:
			printf("\n\t\t\t\t\t\t Opção inválida!\n\n");
			animacaoDeLoading();
			telaCadastro();
		break;
	}
	
}

void telaLogin(){
	system("cls");
	
	int i, c;
	
	printf(".............................................................................          .........................................................\n");
	printf(".............................................................................   IIII   .........................................................\n");
	printf(".............................................................................   IIII   .........................................................\n");
	printf("..............................                                                                             .....................................\n");
	printf("..............................  LLLL            OOOOOOOOOOO       GGGGGGGGGGG   IIII   NNNNNN        NNN   .....................................\n");
	printf("..............................  LLLL           OOOOOOOOOOOOO     GGGGGGGGGGGG   IIII   NNNNNNN       NNN   .....................................\n");
	printf("..............................  LLLL          OOO         OOO    GGG            IIII   NNN  NNN      NNN   .....................................\n");
	printf("..............................  LLLL         OOO           OOO   GGG            IIII   NNN   NNN     NNN   .....................................\n");
	printf("..............................  LLLL         OOO           OOO   GGG   GGGGGG   IIII   NNN    NNN    NNN   .....................................\n");
	printf("..............................  LLLL         OOO           OOO   GGG   GGGGGG   IIII   NNN     NNN   NNN   .....................................\n");
	printf("..............................  LLLL          OOO         OOO    GGG      GGG   IIII   NNN      NNN  NNN   .....................................\n");
	printf("..............................  LLLLLLLLLLLL   OOOOOOOOOOOOO     GGGGGGGGGGGG   IIII   NNN       NNNNNNN   .....................................\n");
	printf("..............................  LLLLLLLLLLLL    OOOOOOOOOOO       GGGGGGGGGG    IIII   NNN        NNNNNN   .....................................\n");
	printf("..............................                                                                             .....................................\n");			
	printf("................................................................................................................................................\n");
	printf("................................................................................................................................................\n");
	printf("................................................................................................................................................\n");	

	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 9: Voltar |");	
	printf("\n");	
	
	printf("                                                              ---------------------------\n");
	printf("                                                               Login: ");
	scanf("%s", &loginLogin);
	fflush(stdin);
	
	if(strcmp(loginLogin, "9") == 0) {
		system("cls");
		telaMenu();;
	}
		
	printf("                                                              ---------------------------\n");
	printf("                                                               Senha: ");
	for(i = 0; c != 13; i++){
		c = getch();
		if(isprint(c)){              
			senhaLogin[i] = c;
			printf("*"); 
		} else if(c == 8 && i){     
           senhaLogin[i] = '\0';
           i--;
           printf("\b \b");       
           }
   	}
   	
	fflush(stdin);
	printf("\n                                                              ---------------------------\n");
	
	if(strcmp(senhaLogin, "9") == 0) {
		system("cls");
		telaMenu();;
	}
	
	if(strcmp(loginLogin, loginCadastro1) == 0 && strcmp(senhaLogin, senhaCadastro1) == 0){
		strcpy(jogadorLogado, jogador1);
		
	} else if(strcmp(loginLogin, loginCadastro2) == 0 && strcmp(senhaLogin, senhaCadastro2) == 0){
		strcpy(jogadorLogado, jogador2);
	} else {
		printf("\n\t\t\t\t\t\t Login e/ou senha incorretas! Aguarde para tentar novamente.\n\n");
		animacaoDeLoading();
		telaLogin();
	}
	
	printf("\n\t\t\t\t\t\t\t   Login realizado! Bem Vindo %s\n\n", jogadorLogado);
		animacaoDeLoading();
		telaModos();
}

void telaModos(){
	system("cls");
	
	int modo = 0;
	int tamanhoTabuleiro;
	
	printf("................................................................................................................................................\n"); Sleep(50);
	printf("................................................................................................................................................\n"); Sleep(50);
	printf("................................................................................................................................................\n"); Sleep(50);
	printf(".....................                                                                                                     ......................\n"); Sleep(50);
	printf(".....................   MMMMMM           MMMMMM      OOOOOOOOOOO      DDDDDDDDDD         OOOOOOOOOOO       SSSSSSSSSSSS   ......................\n"); Sleep(50);
	printf(".....................   MMMMMMM         MMMMMMM     OOOOOOOOOOOOO     DDDDDDDDDDD       OOOOOOOOOOOOO     SSSSSSSSSSSSS   ......................\n"); Sleep(50);
	printf(".....................   MMMM MMM       MMM MMMM    OOO         OOO    DDD      DDD     OOO         OOO     SSSSS          ......................\n"); Sleep(50);
	printf(".....................   MMMM  MMM     MMM  MMMM   OOO           OOO   DDD       DDD   OOO           OOO       SSS         ......................\n"); Sleep(50);
	printf(".....................   MMMM   MMM   MMM   MMMM   OOO           OOO   DDD       DDD   OOO           OOO         SSSSSS    ......................\n"); Sleep(50);
	printf(".....................   MMMM    MMM MMM    MMMM   OOO           OOO   DDD       DDD   OOO           OOO             SSS   ......................\n"); Sleep(50);
	printf(".....................   MMMM     MMMMMM    MMMM    OOO         OOO    DDD      DDD     OOO         OOO             SSSSS  ......................\n"); Sleep(50);
	printf(".....................   MMMM       MM      MMMM     OOOOOOOOOOOOO     DDDDDDDDDDD       OOOOOOOOOOOOO     SSSSSSSSSSSSSS  ......................\n"); Sleep(50);
	printf(".....................   MMMM               MMMM      OOOOOOOOOOO      DDDDDDDDDD         OOOOOOOOOOO      SSSSSSSSSSSSS   ......................\n"); Sleep(50);
	printf(".....................                                                                                                     ......................\n"); Sleep(50);
	printf("................................................................................................................................................\n"); Sleep(50);
	printf("................................................................................................................................................\n"); Sleep(50);
	printf("................................................................................................................................................\n"); Sleep(50);

	Sleep(1000);
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 9: Voltar |\n"); Sleep(50);

	printf("\t _______________________           _____________________________           ___________________________________ \n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t|  2  |  4  |  16 |     |         |  32 |  4  |  4  |     |  16 |         | 2048| 1024|  32 |  8  |  32 |  64 |\n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t-------------------------         -------------------------------         -------------------------------------\n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t|  2  |  8  |     |     |         | 128 |  16 |  8  |  32 |  2  |         | 128 | 512 |  64 |  8  |  32 |  4  |\n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t-------------------------         -------------------------------         -------------------------------------\n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t|  32 |     |     |     |         |  16 |  32 |  8  |  2  |     |         |  16 |  8  |  4  |     |     |  2  |\n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t-------------------------         -------------------------------         -------------------------------------\n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t|     |     |  2  |     |         |     |     |     |  8  |     |         |  64 |  2  |     |     |     |     |\n"); Sleep(50);
	printf("\t|     |     |     |     |         |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t-------------------------         -------------------------------         -------------------------------------\n"); Sleep(50);
	printf("\t                                  |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t| 1: Clássico 4x4 (Difícil) |     |     |     |  2  |     |     |         | 1024|     |     |     |     |     |\n"); Sleep(50);
	printf("\t                                  |     |     |     |     |     |         |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t                                  -------------------------------         -------------------------------------\n"); Sleep(50);
	printf("\t                                                                          |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t                                     | 2: Amplo 5x5 (Médio) |             | 128 |     |     |  8  |     |  2  |\n"); Sleep(50);
	printf("\t                                                                          |     |     |     |     |     |     |\n"); Sleep(50);
	printf("\t                                                                          -------------------------------------\n"); Sleep(50);

	printf("\n\t                                                                                | 3: Grande 6x6 (Fácil) |"); 

	Sleep(1000);
	printf("\n\n\t\t\t\t\t\tEscolha um modo de jogo\n");
	
	modo = getch();
	
	switch(modo){
		case UM:
			tamanhoTabuleiro = 4;
			zerarMatriz();
			preencherTabuleiro(tamanhoTabuleiro);
			preencherTabuleiro(tamanhoTabuleiro);
			jogar(tamanhoTabuleiro);
		break;
		
		case DOIS:
			tamanhoTabuleiro = 5;
			zerarMatriz();
			preencherTabuleiro(tamanhoTabuleiro);
			preencherTabuleiro(tamanhoTabuleiro);
			jogar(tamanhoTabuleiro);
		break;
			
		case TRES:
			tamanhoTabuleiro = 6;
			zerarMatriz();
			preencherTabuleiro(tamanhoTabuleiro);
			preencherTabuleiro(tamanhoTabuleiro);
			jogar(tamanhoTabuleiro);
		break;
		
		case NOVE:
			telaMenu();
		break;
		
		default:
			printf("\nOpção inválida. Tente novamente.\n\n");
			animacaoDeLoading();
			telaModos();
	}
}

void desenhoRanking(){
	printf(".................................................................................        .....................................................\n");
	printf(".................................................................................  IIII  .....................................................\n");
	printf(".................................................................................  IIII  .....................................................\n");
	printf("...........                                                                                                                        ...........\n");
	printf("...........  RRRRRRRRRRR            AA          NNNNNN        NNN  KKKK      KKKK  IIII  NNNNNN        NNN   GGGGGGGGGG      !!!!  ...........\n");
	printf("...........  RRRRRRRRRRRR          AAAA         NNNNNNN       NNN  KKKK     KKKK   IIII  NNNNNNN       NNN  GGGGGGGGGGGG     !!!!  ...........\n");
	printf("...........  RRRR      RRR        AAAAAA        NNN  NNN      NNN  KKKK    KKKK    IIII  NNN  NNN      NNN  GGG              !!!!  ...........\n");
	printf("...........  RRRR     RRR        AAAAAAAA       NNN   NNN     NNN  KKKK  KKKK      IIII  NNN   NNN     NNN  GGG              !!!!  ...........\n");
	printf("...........  RRRRRRRRRRR        AAA    AAA      NNN    NNN    NNN  KKKKKKKKK       IIII  NNN    NNN    NNN  GGG   GGGGGG     !!!!  ...........\n");
	printf("...........  RRRR  RRRR        AAAA    AAAA     NNN     NNN   NNN  KKKK  KKKK      IIII  NNN     NNN   NNN  GGG   GGGGGG     !!!!  ...........\n");
	printf("...........  RRRR   RRRR      AAAAAAAAAAAAAA    NNN      NNN  NNN  KKKK    KKKK    IIII  NNN      NNN  NNN  GGG      GGG           ...........\n");
	printf("...........  RRRR    RRRR    AAAA        AAAA   NNN       NNNNNNN  KKKK     KKKK   IIII  NNN       NNNNNNN  GGGGGGGGGGGG     !!!!  ...........\n");
	printf("...........  RRRR     RRRR  AAAAA        AAAAA  NNN        NNNNNN  KKKK      KKKK  IIII  NNN        NNNNNN   GGGGGGGGGG      !!!!  ...........\n");
	printf("...........                                                                                                                        ...........\n");			
	printf("..............................................................................................................................................\n");
	printf("..............................................................................................................................................\n");
	printf("..............................................................................................................................................\n");
	printf("\n");
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t| 9: Voltar |\n\n");
}

// Função que mostra o ranking
void telaRanking(){
	system("cls");
	
	int opcao = 0;
	
	desenhoRanking();
	
	printf("\t\t\t\tESCOLHA DE QUAL MODO DESEJA VER O RANKING\n\n");
	printf("\t| 1: Clássico 4x4 (Difícil) |    | 2: Amplo 5x5 (Médio)    |    | 3: Grande 6x6 (Fácil) |\n");
	
	do{
		opcao = getch();
	}while(opcao != UM && opcao != DOIS && opcao != TRES && opcao != NOVE);
	
	switch(opcao){
		case UM:
			system("cls");
			desenhoRanking();
			printf("\n\n\t   | Clássico 4x4 (Difícil) |\n\n");
			textColor(BROWN, BLACK);
			
			printf("              YYYYYYYYYYYYYYYY                          \n");
			printf("           YYYY:::::::::::::::YYYY          1º %s | %d      \n", jogadorRankingDificil1, rankingDificil[0]);
			printf("          Y    Y:::::::::::::Y    Y         2º %s | %d      \n", jogadorRankingDificil2, rankingDificil[1]);
			printf("         Y     Y:::::::::::::Y     Y        3º %s | %d      \n", jogadorRankingDificil3, rankingDificil[2]);
			printf("         YYYYYYYY:::::::::::YYYYYYYY        4º %s | %d      \n", jogadorRankingDificil4, rankingDificil[3]);
			printf("                 Y:::::::::Y                5º %s | %d      \n", jogadorRankingDificil5, rankingDificil[4]);
			printf("                   YY:::YY                              \n");
			printf("                     Y:Y                                \n");
			printf("                     Y:Y                                \n");
			printf("                YYYYYYYYYYYYY                           \n");
			printf("                Y:::::::::::Y                           \n");
			printf("                YYYYYYYYYYYYY                           \n");
			textColor(WHITE, BLACK);
			printf("\n\t\t| 1: Jogar | \n");
			do{
				opcao = getch();
				switch(opcao){
					case UM:
						telaModos();
						break;
					case NOVE:
						telaRanking();
						break;		
				}
			}while(opcao != NOVE && opcao != UM);
			break;
		case DOIS:
			system("cls");
			desenhoRanking();
			printf("\n\n\t   | Amplo 5x5 (Médio)    |\n\n");
			textColor(BROWN, BLACK);
			printf("              YYYYYYYYYYYYYYYY                          \n");
			printf("           YYYY:::::::::::::::YYYY          1º %s | %d      \n", jogadorRankingMedio1, rankingMedio[0]);
			printf("          Y    Y:::::::::::::Y    Y         2º %s | %d      \n", jogadorRankingMedio2, rankingMedio[1]);
			printf("         Y     Y:::::::::::::Y     Y        3º %s | %d      \n", jogadorRankingMedio3, rankingMedio[2]);
			printf("         YYYYYYYY:::::::::::YYYYYYYY        4º %s | %d      \n", jogadorRankingMedio4, rankingMedio[3]);
			printf("                 Y:::::::::Y                5º %s | %d      \n", jogadorRankingMedio5, rankingMedio[4]);
			printf("                   YY:::YY                              \n");
			printf("                     Y:Y                                \n");
			printf("                     Y:Y                                \n");
			printf("                YYYYYYYYYYYYY                           \n");
			printf("                Y:::::::::::Y                           \n");
			printf("                YYYYYYYYYYYYY                           \n");
			textColor(WHITE, BLACK);
			printf("\n\t\t| 1: Jogar | \n");
			do{
				opcao = getch();
				switch(opcao){
					case UM:
						telaModos();
						break;
					case NOVE:
						telaRanking();
						break;	
				}
			} while(opcao != NOVE && opcao != UM);
			break;
		case TRES:
			system("cls");
			desenhoRanking();
			printf("\n\n\t   | Grande 6x6 (Fácil) |\n\n");
			textColor(BROWN, BLACK);
			printf("              YYYYYYYYYYYYYYYY                          \n");
			printf("           YYYY:::::::::::::::YYYY          1º %s | %d      \n", jogadorRankingFacil1, rankingFacil[0]);
			printf("          Y    Y:::::::::::::Y    Y         2º %s | %d      \n", jogadorRankingFacil2, rankingFacil[1]);
			printf("         Y     Y:::::::::::::Y     Y        3º %s | %d      \n", jogadorRankingFacil3, rankingFacil[2]);
			printf("         YYYYYYYY:::::::::::YYYYYYYY        4º %s | %d      \n", jogadorRankingFacil4, rankingFacil[3]);
			printf("                 Y:::::::::Y                5º %s | %d      \n", jogadorRankingFacil5, rankingFacil[4]);
			printf("                   YY:::YY                              \n");
			printf("                     Y:Y                                \n");
			printf("                     Y:Y                                \n");
			printf("                YYYYYYYYYYYYY                           \n");
			printf("                Y:::::::::::Y                           \n");
			printf("                YYYYYYYYYYYYY                           \n");
			textColor(WHITE, BLACK);
			printf("\n\t\t| 1: Jogar | \n");
			do{
				opcao = getch();
				switch(opcao){
					case UM:
						telaModos();
						break;
					case NOVE:
						telaRanking();
						break;	
				}
			} while(opcao != NOVE && opcao != UM);
			break;
		case NOVE:
			telaMenu();
			break;
	}
}

void telaInstrucoes(){
	system("cls");
	
	int opcao = 0;
	
	printf(".......        ..................................................................................................              ........................................\n");
	printf(".......  IIII  .................................................................................................    OOO   OOO  ........................................\n");
	printf(".......  IIII  ...............................................................................................   OOO   OOO   ..........................................\n");
	printf(".......                                                                                                                                                         .......\n");
	printf(".......  IIII  NNNNNN        NNN   SSSSSSSSSSSS  TTTTTTTTTTTTTT  RRRRRRRRRRR    UUUU      UUUU   CCCCCCCCCCC     OOOOOOOOOOO     EEEEEEEEEEEEEE   SSSSSSSSSSSS  .......\n");
	printf(".......  IIII  NNNNNNN       NNN  SSSSSSSSSSSSS  TTTTTTTTTTTTTT  RRRRRRRRRRRR   UUUU      UUUU  CCCCCCCCCCCC    OOOOOOOOOOOOO    EEEEEEEEEEEEEE  SSSSSSSSSSSSS  .......\n");
	printf(".......  IIII  NNN  NNN      NNN   SSSSS              TTTT       RRRR      RRR  UUUU      UUUU  CCCC           OOO         OOO   EEEE             SSSSS         .......\n");
	printf(".......  IIII  NNN   NNN     NNN      SSS             TTTT       RRRR     RRR   UUUU      UUUU  CCCC          OOO           OOO  EEEE                SSS        .......\n");
	printf(".......  IIII  NNN    NNN    NNN        SSSSSS        TTTT       RRRRRRRRRRR    UUUU      UUUU  CCCC          OOO           OOO  EEEEEEEEEEE           SSSSSS   .......\n");
	printf(".......  IIII  NNN     NNN   NNN            SSS       TTTT       RRRR  RRRR     UUUU      UUUU  CCCC          OOO           OOO  EEEE                      SSS  .......\n");
	printf(".......  IIII  NNN      NNN  NNN           SSSSS      TTTT       RRRR   RRRR    UUUU      UUUU  CCCC           OOO         OOO   EEEE                     SSSSS .......\n");
	printf(".......  IIII  NNN       NNNNNNN   SSSSSSSSSSSSS      TTTT       RRRR    RRRR    UUUUUUUUUUUU   CCCCCCCCCCCC    OOOOOOOOOOOOO    EEEEEEEEEEEEEE   SSSSSSSSSSSSS .......\n");
	printf(".......  IIII  NNN        NNNNNN   SSSSSSSSSSSS       TTTT       RRRR     RRRR    UUUUUUUUUU     CCCCCCCCCCC     OOOOOOOOOOO     EEEEEEEEEEEEEE   SSSSSSSSSSSS  .......\n");
	printf(".......                                                                                             CC                                                          .......\n");			
	printf(".................................................................................................   CC  ...............................................................\n");
	printf("................................................................................................  CCCC  ...............................................................\n");
	printf("................................................................................................        ...............................................................\n");
	printf("\n\t**** COMO JOGAR ****\n\n");
	printf("\t* Utilize as setas do teclado para movimentar os numeros.\n");
	printf("\t* Caso os numeros na direcao movimentada sejam iguais, eles serao somados.\n");
	printf("\t* O jogo termina quando todas as colunas estejam preenchidas e não tenha mais possibilidades de movimento.\n");
	printf("\t* O objetivo é somar os números até chegar no 2048.\n");
	
	printf("\n\t**** OBSERVAÇÃO ****\n\n");
	printf("\t* Continue jogando depois de concluir o objetivo para aumentar a sua pontuação.\n");
	printf("\t* Procure sempre fazer o cadastro e login antes de jogar para que apareça seu nickname no ranking.\n");
	printf("\t* Tenha um otimo jogo! :D\n\n\n");
	
	printf("\t| 1: Jogar  |    | 9: Voltar  |\n");
	
	do{
		opcao = getch();
		
		if(opcao == UM){
			telaModos();
		} else if(opcao == NOVE){
			telaMenu();
		}
	} while(opcao != UM && opcao != NOVE);
}

void telaPause(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t");
	printf("   -----------------JOGO PAUSADO-------------\n");
	printf("\t\t\t\t\t\t");
	printf("   |                                        |\n");
	printf("\t\t\t\t\t\t");
    printf("   |\t  Escolha uma opcao:                |\n"); 
    printf("\t\t\t\t\t\t");
    printf("   |\t  [1] -  Continuar o Jogo           |\n");
    printf("\t\t\t\t\t\t");
    printf("   |\t  [2] -  Reiniciar o Jogo           |\n");
    printf("\t\t\t\t\t\t");
    printf("   |\t  [3] -  Mudar o Modo de Jogo       |\n");
    printf("\t\t\t\t\t\t");
    printf("   |\t  [4] -  Sair Para o Menu Inicial   |\n");
    printf("\t\t\t\t\t\t");
    printf("   |                                        |\n"); 
	printf("\t\t\t\t\t\t");   
    printf("   ------------------------------------------\n");
    printf("\t\t\t\t\t\t");
    printf("   Digite a opcao desejada.\n");
    printf("\t\t\t\t\t\t");
    printf("   Tecle ENTER para confirmar > ");
}

// Tela que aparece quando o jogo acaba
void menuPerdeu(){
	printf("\n\t\t\t\t\t\t");
	printf("   -----------------VOCÊ PERDEU--------------\n");
	printf("\t\t\t\t\t\t");
	printf("   |                                        |\n"); 
	printf("\t\t\t\t\t\t");
    printf("   |\t  Escolha uma opcao:                |\n"); 
    printf("\t\t\t\t\t\t");
    printf("   |\t  [1] -  Jogar Novamente            |\n");
    printf("\t\t\t\t\t\t");
    printf("   |\t  [2] -  Mudar o Modo de Jogo       |\n");
    printf("\t\t\t\t\t\t");
    printf("   |\t  [3] -  Ver Ranking                |\n");
    printf("\t\t\t\t\t\t");
    printf("   |\t  [4] -  Sair Para o Menu Inicial   |\n");
    printf("\t\t\t\t\t\t");
    printf("   |                                        |\n");   
	printf("\t\t\t\t\t\t"); 
    printf("   ------------------------------------------\n");
    printf("\t\t\t\t\t\t");
    printf("   Digite a opcao desejada.\n");
    printf("\t\t\t\t\t\t");
    printf("   Tecle ENTER para confirmar > ");
}

// Função para verificar se há movimentos disponíveis
int verificaSePerdeu(int tamanhoTabuleiro){
	int count = 0;
	
	count += permitidoIrParaEsquerda(tamanhoTabuleiro);
	count += permitidoIrParaDireita(tamanhoTabuleiro);
	count += permitidoIrParaCima(tamanhoTabuleiro);
	count += permitidoIrParaBaixo(tamanhoTabuleiro);
	
	if(count == 0){
		return 1;
	} else {
		return 0;
	}
}

// Função que roda o jogo
void jogar(int tamanhoTabuleiro){
	int tecla = 0;
	int perdeu = 0;
	
	score = 0;
	textColor(BLACK, _WHITE);
	jogar:
	mostrarMatriz(tamanhoTabuleiro);
	
	while(perdeu == 0){
		tecla = getch();
		
		if(tecla == ESQUERDA){
			if(permitidoIrParaEsquerda(tamanhoTabuleiro) == 1){
				system("cls");
				movimentaEsquerda(tamanhoTabuleiro);
				preencherTabuleiro(tamanhoTabuleiro);
				mostrarMatriz(tamanhoTabuleiro);
				perdeu = verificaSePerdeu(tamanhoTabuleiro);
			} else {
				printf("\n JOGADA INVÁLIDA!");
			}
		}
		
		if(tecla == DIREITA){
			if(permitidoIrParaDireita(tamanhoTabuleiro) == 1){
				system("cls");
				movimentaDireita(tamanhoTabuleiro);
				preencherTabuleiro(tamanhoTabuleiro);
				mostrarMatriz(tamanhoTabuleiro);
				perdeu = verificaSePerdeu(tamanhoTabuleiro);
			} else {
				printf("\n JOGADA INVÁLIDA!");
			}
		}
		
		if(tecla == CIMA){
			if(permitidoIrParaCima(tamanhoTabuleiro) == 1){
				system("cls");
				movimentaCima(tamanhoTabuleiro);
				preencherTabuleiro(tamanhoTabuleiro);
				mostrarMatriz(tamanhoTabuleiro);
				perdeu = verificaSePerdeu(tamanhoTabuleiro);
			} else {
				printf("\n JOGADA INVÁLIDA!");
			}
		}
		
		if(tecla == BAIXO){
			if(permitidoIrParaBaixo(tamanhoTabuleiro) == 1){
				system("cls");
				movimentaBaixo(tamanhoTabuleiro);
				preencherTabuleiro(tamanhoTabuleiro);
				mostrarMatriz(tamanhoTabuleiro);
				perdeu = verificaSePerdeu(tamanhoTabuleiro);
			} else {
				printf("\n JOGADA INVÁLIDA!");
			}
		}
		
		if(tecla == PAUSE){
			do{
				system("cls");
				telaPause();
				
				pause:
				scanf("%d", &tecla);
				
				switch(tecla){
					case 1:
					goto jogar;
						break;
					case 2:
						inserirDadosNoRanking(tamanhoTabuleiro);
						zerarMatriz();
						preencherTabuleiro(tamanhoTabuleiro);
						preencherTabuleiro(tamanhoTabuleiro);
						jogar(tamanhoTabuleiro);
						break;
					case 3:
						printf("\n\t\t\t\t\t\t");
						printf("Você perderá o progresso do jogo atual, mas a pontuação será considerada para o ranking.\n");
						printf("\t\t\t\t\t\t");
						printf("Tem certeza que deseja mudar de modo?\n");
						printf("\t\t\t\t\t\t");
						printf("[1] - Sim\n");
						printf("\t\t\t\t\t\t");
						printf("[2] - Não\n");
						printf("\t\t\t\t\t\t> ");
						scanf("%d", &tecla);
						do{
							if(tecla == 1){
								inserirDadosNoRanking(tamanhoTabuleiro);
								textColor(WHITE, _BLACK);
								telaModos();
							} else if(tecla == 2){
								system("cls");
								telaPause();
								goto pause;
							}
						}while(tecla != 1 && tecla != 2);
						break;
					case 4:
						printf("\n\t\t\t\t\t\t");
						printf("Você perderá o progresso do jogo atual, mas a pontuação será considerada para o ranking.\n");
						printf("\t\t\t\t\t\t");
						printf("Tem certeza que deseja sair?\n");
						printf("\t\t\t\t\t\t");
						printf("[1] - Sim\n");
						printf("\t\t\t\t\t\t");
						printf("[2] - Não\n");
						printf("\t\t\t\t\t\t> ");
						scanf("%d", &tecla);
						do{
							if(tecla == 1){
								inserirDadosNoRanking(tamanhoTabuleiro);
								textColor(WHITE, _BLACK);
								telaMenu();
							} else if(tecla == 2){
								system("cls");
								telaPause();
								goto pause;
							}
						}while(tecla != 1 && tecla != 2);
						
						break;
				}
			}while(tecla != 1 && tecla != 2 && tecla != 3 && tecla != 4);
		}
	}
	
	inserirDadosNoRanking(tamanhoTabuleiro);
	
	menuPerdeu();
	do{
		scanf("%d", &tecla);
		
		switch(tecla){
			case 1:
				zerarMatriz();
				preencherTabuleiro(tamanhoTabuleiro);
				preencherTabuleiro(tamanhoTabuleiro);
				jogar(tamanhoTabuleiro);
				break;
			case 2:
				textColor(WHITE, _BLACK);
				telaModos();
				break;
			case 3:
				textColor(WHITE, _BLACK);
				telaRanking();
				break;
			case 4:
				textColor(WHITE, _BLACK);
				telaMenu();
		}
	}while(tecla != 1 && tecla != 2 && tecla != 3 && tecla != 4);
	
} 


int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");
	
	telaCarregamento();
	telaMenu();
	
	return 0;
}
