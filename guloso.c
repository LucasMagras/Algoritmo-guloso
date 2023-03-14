#include "guloso.h"

int SomaTotal[4], x=0, somatotal=0;

void LerMatriz(){

	struct stat sb;
    stat("dataset/input.data", &sb);

    FILE *f;
	int **mat, i=0, j=0, tam=0, cont=0;
    char *linha = malloc(sb.st_size);
    char *tok;
	int Somas[4];

    if ((f = fopen("dataset/input.data", "r")) == NULL){
        printf("file could not be opened");
        exit(-1);
    }

    while (fscanf(f, "%[^\n] ", linha) != EOF) {
		if(cont==0){
			tok = strtok(linha, "\n");
			while (tok != NULL){
				tam=atoi(tok);
				tok = strtok (NULL," ");
    		}
		
			mat = malloc(tam*sizeof(int*));

			for(int k=0;k<tam;k++)
				mat[k]=malloc(sizeof(int)*tam);
			cont++;

		}else{
			tok = strtok(linha, " ");

			while (tok != NULL)
   			{
				mat[i][j]=atoi(tok);
				j++;
				tok = strtok (NULL," ");
    		}
			
			j=0;
			i++;

			if(i==tam)
			{
				printf("\nMATRIZ : \n\n");
				for(int i=0; i<tam; i++){
					for(int j=0; j<tam; j++){
						printf("%d ", mat[i][j]);
					}
						printf("\n");
				}
				printf("\n");

				Caminho(mat,tam);
			
				i=0;
				printf("\n================================================================================\n");
				//voltando o i para 0 para ele pegar as outras matrizes
			}
		}
    }

	fclose(f);
}


void Caminho(int **mat, int tam)
{
	int linha=0, coluna=0, soma=0, j=0, k=0, size=0, i=0;
	size=tam*tam;
	int caminho[size];

	for(int i=0; i<size; i++){
		caminho[i]=0;
	}
	

	while(1){
		//verificando se a posicao atual esta proxima da posicao NxN da matriz
		//se a posicao atual for alguma posicao da ultima linha (ja que eh proibido subir)
		if(linha==tam-1){
			while(mat[linha][coluna]!=mat[tam-1][tam-1]){
				caminho[k]=mat[linha][coluna];
				mat[linha][coluna]=-11;
				coluna++; 
				k++;
				caminho[k]=mat[linha][coluna];
				printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
			}
			break;
		}

		//na diagonal superior esquerda
		else if(mat[linha][coluna]==mat[tam-2][tam-2]){
			caminho[k]=mat[linha][coluna];
			mat[linha][coluna]=-11;
			coluna++;
			linha++;
			k++;
			caminho[k]=mat[linha][coluna];
			printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
			break;
		}

		//em cima 
		else if(mat[linha][coluna]==mat[tam-2][tam-1]){
			caminho[k]=mat[linha][coluna];
			mat[linha][coluna]=-11;
			linha++;
			k++;
			caminho[k]=mat[linha][coluna];
			printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
			break;
		}

		//caminhando
		//direita
		else if(mat[linha][coluna+1]>mat[linha+1][coluna] && mat[linha][coluna+1]>mat[linha+1][coluna+1] && mat[linha][coluna+1]>mat[linha][coluna-1] && mat[linha][coluna+1]>mat[linha+1][coluna-1]){
			caminho[k]=mat[linha][coluna];
			mat[linha][coluna]=-11;
			coluna++; 
			k++;
			caminho[k]=mat[linha][coluna];
			printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
		}
		
		//baixo
		else if(mat[linha+1][coluna]>mat[linha][coluna+1] && mat[linha+1][coluna]>mat[linha][coluna-1] && mat[linha+1][coluna]>mat[linha+1][coluna+1] && mat[linha+1][coluna]>mat[linha+1][coluna-1]){
			caminho[k]=mat[linha][coluna];
			mat[linha][coluna]=-11;
			linha++;
			k++;
			caminho[k]=mat[linha][coluna];
			printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
		}

		//esquerda
		else if(mat[linha][coluna-1]>mat[linha+1][coluna] && mat[linha][coluna-1]>mat[linha+1][coluna+1] && mat[linha][coluna-1]>mat[linha][coluna+1] && mat[linha][coluna-1]>mat[linha+1][coluna-1]){
			caminho[k]=mat[linha][coluna];
			mat[linha][coluna]=-11;
			coluna--;
			k++;
			caminho[k]=mat[linha][coluna];
			printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
		}

		//diagonal direita
		else if(mat[linha+1][coluna+1]>mat[linha+1][coluna-1] && mat[linha+1][coluna+1]>mat[linha+1][coluna] && mat[linha+1][coluna+1]>mat[linha][coluna+1] && mat[linha+1][coluna+1]>mat[linha][coluna-1]){
			caminho[k]=mat[linha][coluna];
			mat[linha][coluna]=-11;
			coluna++;
			linha++;
			k++;
			caminho[k]=mat[linha][coluna];
			printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
		}

		//diagonal esquerda
		else if(mat[linha+1][coluna-1]>mat[linha+1][coluna+1] && mat[linha+1][coluna-1]>mat[linha+1][coluna] && mat[linha+1][coluna-1]>mat[linha][coluna+1] && mat[linha+1][coluna-1]>mat[linha][coluna-1]){
			caminho[k]=mat[linha][coluna];
			mat[linha][coluna]=-11;
			coluna--;
			linha++;
			k++;
			caminho[k]=mat[linha][coluna];
			printf("ANDANDO PARA [%d][%d] = %d\n",linha+1,coluna+1,mat[linha][coluna]);
		}

		else{
			break;
		}

	}

	printf("\n\nPRINTANDO O CAMINHO | (-11=caminho feito)\n\n");
	for(int i=0; i<tam; i++){
			for(int j=0; j<tam; j++){
				printf("%d ", mat[i][j]);
			}
			printf("\n");
		}

	printf("\nVETOR DAS POSICOES DO CAMINHO : ");
	for(int i=0; i<size; i++){
		printf("[%d]", caminho[i]);
		if(caminho[i+1]==0)
			break;
	}

	printf("\n");

	//SOMA DO VETOR DAS POSI
	while(j!=size){
		soma+=caminho[j];
		j++;
	}

	printf("\nSOMA DO CAMINHO = %d\n", soma);

	Somas(soma);

}

void Somas(int soma)
{	
	int i=0;
	SomaTotal[x]=soma;
	x++;

	printf("\nVETOR DAS SOMAS : ");
	for(int i=0; i<4; i++){
		printf("[%d]", SomaTotal[i]);
		if(SomaTotal[i+1]==0)
			break;
	}

	while(i!=4){
		somatotal+=SomaTotal[i];
		i++;
	}

	if(SomaTotal[3]!=0){
		printf("\n\nSOMA TOTAL DAS MATRIZES = %d\n\n", somatotal);
	}
}

void invet()
{
	for(int i=0; i<4; i++){
        SomaTotal[i]=0;
    }
}