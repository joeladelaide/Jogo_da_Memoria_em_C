//                            CENTRO UNIVERSITÁRIO DE JOÃO PESSOA - UNIPÊ
//                                       CIÊNCIAS DA COMPUTAÇÃO
//                             TÉCNICAS DE DESENVOLVIMENTO DE ALGORITMOS 
//                            LABORATÓRIO DE DESENVOLVIMENTO DE ALGORITMOS 

//                                   PROJETO FINAL - JOGO DA MEMÓRIA 

// EQUIPE:
// Joel Adelaide Medeiros - RGM: 29799384
// Marcos Barbosa Vieira Filho - RGM: 30174503
// Maria Helena de Medeiros Silva - RGM: 30227151
// Sidnei Marcos- RGM: 29818591

//Inclusão de bibliotecas utilizadas no desenvolvimento do jogo
#include<stdio.h> 
#include<windows.h> 
#include<stdlib.h> 
#include <locale.h> 

//Declaração de matriz 'tabuleiro'
int j1[4][4]=
{
    1,2,3,4,
    6,7,8,9,
    1,2,3,4,
    6,7,8,9
};

//Declaração de matriz secundária
int j2[4][4]=
{
    0,0,0,0,
    0,0,0,0,
    0,0,0,0,
    0,0,0,0
};

//Definição de Struct para marcação do placar 
struct placar{
	int vez;
	int placarJogador1;
	int placarJogador2;
	char nomeJogador1[20];
	char nomeJogador2[20];
};

// Método que define alguns prints iniciais do jogo
void printInicial(){
	
	printf("\t\t\tCENTRO UNIVERSITÁRIO DE JOÃO PESSOA - UNIPÊ\n"); 
	Sleep(1500);
	printf("\t\t\tCIÊNCIAS DA COMPUTAÇÃO\n");
	Sleep(1500);
	printf("\t\t\tTÉCNICAS DE DESENVOLVIMENTO DE ALGORITMOS\n");
	Sleep(1500);
	printf("\t\t\tLABORATÓRIO DE DESENVOLVIMENTO DE ALGORITMOS\n\n");
	Sleep(1500);
	printf("\t\t\tPROJETO FINAL - JOGO DA MEMÓRIA\n\n");
	Sleep(1500);
	printf("\t\t\tEQUIPE:\n");
	Sleep(1500);
	printf("\t\t\tJoel Adelaide Medeiros - RGM: 29799384\n");
	Sleep(1500);
	printf("\t\t\tMarcos Barbosa Vieira Filho - RGM: 30174503\n");
	Sleep(1500);
	printf("\t\t\tMaria Helena de Medeiros Silva - RGM: 30227151\n");
	Sleep(1500);
	printf("\t\t\tSidnei Marcos- RGM: 29818591\n\n\n");
	Sleep(1500);
	system("cls");

}
// Método que exibi, o placar do jogo
void printTopo(struct placar _placar){
	
	printf("-*-*-*-*-*-*-*-*-*-*  JOGO DA MEMÓRIA  -*-*-*-*-*-*-*-*-*-*\n");
	
	if(_placar.vez == 1)
		printf("-*-*-*-*-*-*-*-*-*-*-*-  JOGADOR 1  *-*-*-*-*-*-*-*-*-*-*-*\n");
	else if(_placar.vez == 2)
		printf("-*-*-*-*-*-*-*-*-*-*-*-  JOGADOR 2  *-*-*-*-*-*-*-*-*-*-*-*\n");
	
	printf("   JOGADOR 1 - (%s) (%d) X (%d) - (%s) JOGADOR 2   \n\n", _placar.nomeJogador1, _placar.placarJogador1, _placar.placarJogador2, _placar.nomeJogador2);
	
}

// Método que printa o tabuleiro do jogo
void printTabuleiro(){
	
    int linha, coluna;
    printf("  1 2 3 4 \n");
    for(linha=0; linha<4; linha++){
        printf("%d ",linha+1);
        for(coluna=0; coluna<4; coluna++){
            if(j2[linha][coluna]==1)
                printf("%d|",j1[linha][coluna]);
            else if(linha<3) printf("_|");
            else printf(" |");
        }
        printf("\n");
    }
    printf("\n\n");
}

// Método de análise do jogo da memoria 
int analizaJogoMemoria(){
    int qt, linha, coluna;
    for(linha=0; linha<4; linha++) for(coluna=0; coluna<4; coluna++) if(j2[linha][coluna]==1) qt++;
    if(qt==16) return 1;
    return 0;
}

// Método marca pontos 
struct placar PontuaPlacar(struct placar _placar){
	
	if(_placar.vez == 1){
		_placar.placarJogador1 += 1;
		_placar.vez = 2;
	}

	else if(_placar.vez == 2){
		_placar.placarJogador2 += 1;
		_placar.vez = 1;
	}

	return _placar;
}

// Método não marca ponto 
struct placar PontuaPlacarErro(struct placar _placar){
	
	if(_placar.vez == 1){
		_placar.placarJogador2 -= 1;
	}

	else if(_placar.vez == 2){
		_placar.placarJogador1 -= 1;
	}

	return _placar;
}

// Método que printa o resultado final
void printFinal(struct placar _placar){
	
	//SALVA os dados do gannhador em um arquivo
	//ponteiro arquivo
	FILE *salvar;
	
	//cria arquivo
	salvar= fopen("rank.txt","a");
	
	
	printf("-*-*-*-*-*-*-*-*-*-*  FINAL DO JOGO  -*-*-*-*-*-*-*-*-*-*\n");
	if(_placar.placarJogador1 > _placar.placarJogador2){
		printf("-*-*-*-*-*-*-*-*-* JOGADOR 1 VENCEU!  -*-*-*-*-*-*-*-*-*\n");
		//dados a salvar caso o ganhador sejá o jogador 1
		fprintf(salvar, "\n %s- %d        \n",_placar.nomeJogador1,_placar.placarJogador1);
		//fecha arquivo
		fclose(salvar);
		printf("Adicionado ao ranking");
	}	
	else if(_placar.placarJogador2 > _placar.placarJogador1){
		printf("-*-*-*-*-*-*-*-*-*  JOGADOR 2 VENCEU!  -*-*-*-*-*-*-*-*-*\n");
		//dados a salvar caso o ganhador sejá o jogador 2
		fprintf(salvar, "\n %s- %d        \n",_placar.nomeJogador2,_placar.placarJogador2);
		//fecha arquivo
		fclose(salvar);
		printf("Adicionado ao ranking");
	}
	else
		printf("-*-*-*-*-*-*-*-*-*-*-*  EMPATE!  -*-*-*-*-*-*-*-*-*-*-*\n");
   
}

void embaralharMatriz(){
	
		int i,j,r,y,temp;
	    
	    for ( i = 0; i < 4; i++ ) {
         for ( j = 0; j < 4; j++ ) {
              r = rand ( ) % 4;
              y = rand ( ) % 4;
              temp = j1 [ i ] [ j ];
              j1 [ i ] [ j ] = j1 [ r ] [ y ];
              j1 [ r ] [ y ] = temp;
         }
     }
     
    for ( i = 0; i < 4; i++ ) {
         for ( j = 0; j < 4; j++ ) {
         	
         	j2[i][j] = 0;}}
}


// Método de inicialização MAIN()
int main(){
	
	// Configuração de linguagem utilizada (Português)
	setlocale(LC_ALL, "Portuguese");
	
	//Definição de Struct a ser utilizada
	struct placar _placar;
	
	//Declaração de Variáveis
    int linha, coluna, linha2, coluna2;
    int op=1, gameover=0;
    
    //Chama Método de Prints Iniciais 
    printInicial();
    
    //Loop Inicial do Menu
    while(op!=4){
    	system("cls");
	    //ENTRADA do Menu
	    printf("-*-*-*-*-*-*-*-*-*-*  JOGO DA MEMÓRIA  -*-*-*-*-*-*-*-*-*-*\n\n");
	    printf("Escolha uma das opções: \n");
	    printf("\n(1) - Jogar\n");
	    printf("(2) - Ranking\n");
	    printf("(3) - Créditos\n");
	    printf("(4) - Sair\n");
	    printf("\nOpção Desejada: ");
	    scanf("%d", &op);
	    
	    //placar inicial
	    _placar.placarJogador1 = 0;
	    _placar.placarJogador2 = 0;
	    _placar.vez = 1;
	    
		embaralharMatriz();
		

	    	
	    if(op==1){
	    //PROCESSAMENTO
	    
	    gameover=0;
	    	
	    system("cls");
	    	
	    printf("Digite o nome do Jogador 1: ");
	    scanf("%s", _placar.nomeJogador1);
	    printf("Digite o nome do Jogador 2: ");
	    scanf("%s", _placar.nomeJogador2);
	            
	    system("cls");
	    
	    	
	        while(!gameover){
	        	
	            jgd1: system("cls");

	            printTopo(_placar);
	            printTabuleiro();
	            
	            //ENTRADA do Usuário - Linha e Coluna desejada da primeira coordenada
	            printf("Digite a linha e a coluna desejada...\n");
	            printf("Linha: ");
	            scanf("%d", &linha);
	            printf("Coluna: ");
	            scanf("%d", &coluna);
	            
	            linha--;
				coluna--;
				
				//verifica se o local já foi descoberto
				if(j2[linha][coluna]==1){
	                printf("\nTente novamente! Local já descoberto! \n");
	                Sleep(1500);
	                getchar();
	                goto jgd1; 
	            }
	            
	            //se os valores ultrapassam o limite
	            if(linha<0 || linha>3 || coluna<0 || coluna>4){
	                printf("\nTente novamente! Insira valores entre 1 e 4!\n");
	                Sleep(1500);
	                getchar();
	                goto jgd1;
	            }
	            
	            j2[linha][coluna]=1;
	            jgd2: system("cls");
	            
	            printTopo(_placar);
	            printTabuleiro();
	            
	            //ENTRADA do Usuário - Linha e Coluna desejada da segunda coordenada
				printf("Digite a linha e a coluna desejada...\n");
	            printf("Linha: ");
	            scanf("%d", &linha2);
	            printf("Coluna: ");
	            scanf("%d", &coluna2);
	            
	            linha2--;
				coluna2--;
	            
	            //verifica se o local já foi descoberto
	            if(j2[linha2][coluna2]==1){
	                printf("\nTente novamente! Local já descoberto! \n");
	                Sleep(1500);
	                getchar();
	                goto jgd2; 
	            }
	            
	            //se os valores ultrapassam o limite
	            if(linha2<0 || linha2>3 || coluna2<0 || coluna2>4){
	                printf("\nTente novamente! Insira valores entre 1 e 4!\n");
	                Sleep(1500);
	                getchar();
	                goto jgd2; 
	            }
				
	            j2[linha2][coluna2] = 1;
	            _placar = PontuaPlacar(_placar);
	            
	            //verifica se o conteúdo da primeira coordenada e igual o da segunda
	            if(j1[linha][coluna] != j1[linha2][coluna2]){
	            	_placar = PontuaPlacarErro(_placar);
	            	system("cls");
	            	printTopo(_placar);
	            	printTabuleiro();
	                printf("\nERROU!!!\n");
	                Sleep(1500);
	                j2[linha][coluna]=0;
	                j2[linha2][coluna2]=0;
	            }
	            gameover = analizaJogoMemoria();
	        }
	        
	        //SAÍDA POS FINALIZAÇÃO DO JOGO DA MEMÓRIA 
			printFinal(_placar);
	        Sleep(10000);
	        system("cls");
	        getchar();
	    }
	    else if(op==2){
	    	
	    	
	    	//exibir ranking
	    	printf("Ranking\n");
	    	
	    	//ponteiro arquivo
	    	FILE *salvar;
	    	
	    	//conteúdo a ser lido
	    	char rank_str[50];
	    	
	    	//abre o arquivo
			salvar= fopen("rank.txt","r");
			
			//exibe o contéudo do arquivo
			while(fgets(rank_str, 50, salvar) !=NULL){
				printf("%s", rank_str);
				}
				
			//fecha o arquivo
			fclose(salvar);
			Sleep(1500);
			
			//getch();
	    	
	    
		
		}
		else if(op==3){
			//mostra os créditos
			system("cls");
			printInicial();
		}
	
	}
    
    //acaba o jogo
    getchar();
    exit(2);
}





