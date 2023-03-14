# Algoritmo-guloso

<p align="justify">
	O algoritmo tem como objetivo percorrer uma matriz quadrada lida de um arquivo que gerada aleatoriamente, afim de chegar na posição NxN da matriz passando pelas posições de maior valor. Antes de começar o algotimo, o programa armazena a matriz do arquivo em uma outra matriz declarada no escopo e alocada dinamicamente para poder ler. Durante o caminho só é permitiddo caminhar para baixo, para esquerda ou direita e para as diagonais inferiores, ou seja, é proibido caminhar para alguma posição na linha a cima da posição atual. Alem disso durante o caminho o programa armazena o valor de cada posição em um vetor e no final soma todos esses valores.  
</p>

<p align="justify">
	Importante lembrar que esse código lê 4 matrizes de uma vez, porem ele armazena apenas uma na matriz alocada. Após realizar o processo em uma matriz, ele zera a outra e recomeça tudo de novo.
</p>

# Compilação e Execução

O código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |
