//
//  main.cpp
//  CacaPalavras
//
//  Created by Gabriel A. Dragoni on 3/15/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include <iostream>                                     /*biblioteca cout cin*/
#include <cstring>                                      /*biblioteca para string*/
#include <cstdlib>                                      /*<stdlib>*/
#include <stdio.h>                                      /* printf, NULL */
#include <stdlib.h>                                     /* srand, rand */
#include <time.h>                                       /* time */

// Tabela e palavras ajustaveis //
#define TAMANHO_TABELA 15                               /* recomendado 15~20 */
#define QTD_PALAVRAS 20                                 /* maximo 20 */
#define MODO_TESTE 1                                    /* modo teste, 1 para ativado e 0 desativado*/

using namespace std;

int palavrasUsadas[QTD_PALAVRAS];                       /* vetor com indice de palavras usadas */
int camposUsados[QTD_PALAVRAS][15];                     /* matriz com campos da tabela usados */

char matrizTabela[TAMANHO_TABELA+1][TAMANHO_TABELA+1];  /* matriz tabela */
char matrizArrayDePalavras[QTD_PALAVRAS+1][16];         /* matriz para armazenar palavras usadas na tabela */

string PalavraAleatoria();                              /* gera uma palavra aleatoria */
string palavraMaiuscula(string palavra);                /* transforma a palavra em maiuscula */
string palavraNoIndiceDaMatriz(int indice);             /* recupera palavra do indice na matrizArrayDePalavras */
void carregarMatrizTabela();                            /* carrega a tabela com as palavaras e letras aleatorias */
void carregarMatrizComPalavras();                       /* carrega matriz com as palavras da tabela */
void tirarPalavraDaTabela(int indice);                  /* remove palavra encontrada da tabela*/
void mostrarTabela();                                   /* mostra a tabela em seu formato */
void adicionaCampoUsado(int indice, int palavraNumero); /* adiciona campo usado ao vetor, sem substituir os demais */
char letraAleatoria();                                  /* gera uma letra aleatoria */
int qtdpalavrasFaltandoAchar();                         /* retorna qt de palavras faltam encontrar */
bool testePalavraEncontrada(string palavraDigitada);    /* testa se palavra digitada esta na tabela */
bool testePalavraUsada(int indice);                     /* testa se palavra ja foi sorteada */
bool testePossivelCampoParaPalavra(int indices, string palavra, bool vertical); /* testa se o campo e possivel colocar a palavra */
bool indiceRepeteEmOutraPalavra(int indice);            /* testa se o indice de uma palavra repete em outra */

int main(int argc, const char * argv[]) {

    string palavraDigitada;

    srand((unsigned)time(NULL));            /* atribui o relogio para que o rand nao sorteie sempre o mesmo numero */

    cout << "Pode-se digitar 'TABELA'para mostrar a tabela a qualquer momento.\n\n";

    carregarMatrizTabela();

    mostrarTabela();

    do {

        cout << "Digite a palavra encontrada : \n\n";

        cin >> palavraDigitada;

        palavraDigitada = palavraMaiuscula(palavraDigitada);

        if (palavraDigitada == "TABELA") {

            mostrarTabela();
        }else if (testePalavraEncontrada(palavraDigitada)){

            cout << "\nPalavra correta! \n\n";
            if (qtdpalavrasFaltandoAchar() != 0) {

                cout << "Faltam " << qtdpalavrasFaltandoAchar() << " palavras para encontrar!\n\n";
                
                mostrarTabela();
            }else{
                
                mostrarTabela();
                
                cout << "\n\n\tParabens! Voce encontrou todas as palavras!\n\n";
            }
        }else{

            cout << "\nPalavra invalida, tente outra.\n\n";
        }
        
    } while (qtdpalavrasFaltandoAchar() != 0);

    return 0;
}

void mostrarTabela(){

    for (int i = 0; i < TAMANHO_TABELA*2-1; i++) {
        
        cout << "=";
    }
    for (int i = 0; i <= TAMANHO_TABELA-1; i++) {
        
        cout << "\n";
        for (int j = 0; j <= TAMANHO_TABELA; j++) {

            cout << matrizTabela[i][j] << " ";
        }
    }
    cout << "\n";
    for (int i = 0; i < TAMANHO_TABELA*2-1; i++) {
        
        cout << "=";
    }
    cout << "\n";
}

void carregarMatrizTabela(){

    carregarMatrizComPalavras();

    string palavra;

    for (int i = 0; i < QTD_PALAVRAS; i++) {

        palavra = palavraNoIndiceDaMatriz(i);
        
        bool vertical;
        int indice;
        do{

            vertical = (rand() % 2)-1;
            indice = rand() % (TAMANHO_TABELA*TAMANHO_TABELA)+1;

        }while (testePossivelCampoParaPalavra(indice, palavra, vertical));

        for (int j = 0; j < palavra.length(); j ++) {

            if (vertical) {

                int positionY = ((indice -1)/TAMANHO_TABELA);
                int positionX = (indice%TAMANHO_TABELA);

                adicionaCampoUsado(indice + TAMANHO_TABELA*j, i);

                matrizTabela[positionY+j][positionX] = palavra[j];
            }else{

                adicionaCampoUsado(indice + j, i);
                
                int positionY = ((indice -1)/TAMANHO_TABELA);
                int positionX = (indice%TAMANHO_TABELA);

                matrizTabela[positionY][positionX+j] = palavra[j];
            }
        }
    }

    for (int i = 0; i < TAMANHO_TABELA; i++) {

        for (int j = 0; j < TAMANHO_TABELA; j++) {

            if (matrizTabela[i][j] == '\0') {
                
                if (MODO_TESTE) {
                    
                    matrizTabela[i][j] = '#';
                }else{
                    
                    matrizTabela[i][j] = letraAleatoria();
                }
            }
        }
    }
}

void carregarMatrizComPalavras(){
    
    string palavra;
    
    for (int i = 0; i < QTD_PALAVRAS; i++) {
        
        palavra = PalavraAleatoria();
        
        for (int j = 0; j <= palavra.length(); j++) {
            
            matrizArrayDePalavras[i][j] = palavra[j];
        }
    }
}

string palavraNoIndiceDaMatriz(int indice){
    
    string palavraNoIndice;
    
    for (int i = 0; i < 15; i++) {
        
        if (matrizArrayDePalavras[indice][i] != '\0') {
            
            palavraNoIndice += matrizArrayDePalavras[indice][i];
        }else{
            
            break;
        }
    }
    
    return palavraNoIndice;
}

int qtdpalavrasFaltandoAchar(){

    int qtd = QTD_PALAVRAS;

    for (int i = 0; i < QTD_PALAVRAS; i++) {
        
        if (matrizArrayDePalavras[i][0] == '\0') {
            
            qtd--;
        }
    }
    
    return qtd;
}

string palavraMaiuscula(string palavra){

    string palavraMaiuscula;

    for (int i = 0; i < palavra.length(); i ++) {

        palavraMaiuscula += toupper(palavra[i]);
    }

    return palavraMaiuscula;
}

bool testePalavraEncontrada(string palavraDigitada){

    for (int i = 0; i < QTD_PALAVRAS; i++) {
        
        string palavraNoIndice;
        for (int j = 0; j < 15; j++) {
            
            if (matrizArrayDePalavras[i][j] != '\0') {
                
                palavraNoIndice += matrizArrayDePalavras[i][j];
            }else{
                
                break;
            }
        }
        if (palavraNoIndice == palavraDigitada) {
            
            tirarPalavraDaTabela(i);
            for (int k = 0; k < 15; k++) {
                
                if (matrizArrayDePalavras[i][k] == '\0') {
                    
                    break;
                }else{
                    
                    matrizArrayDePalavras[i][k] = '\0';
                }
            }
            return true;
        }
    }
    return false;
}

void tirarPalavraDaTabela(int indice){
    
    for (int i = 0; i < 15; i ++) {
        
        if (camposUsados[indice][0] == camposUsados[indice][1]-1) {
            
            int campo = camposUsados[indice][i];
            
            int positionY = ((campo -1)/TAMANHO_TABELA);
            int positionX = (campo%TAMANHO_TABELA);
            
            if (!indiceRepeteEmOutraPalavra(campo)) {
                
                matrizTabela[positionY][positionX] = '#';
            }
            camposUsados[indice][i] = 0;
        }else{
            
            int campo = camposUsados[indice][i];
            
            int positionY = ((campo -1)/TAMANHO_TABELA);
            int positionX = (campo%TAMANHO_TABELA);
            
            if (!indiceRepeteEmOutraPalavra(campo)) {
                
                matrizTabela[positionY][positionX] = '#';
            }
            camposUsados[indice][i] = 0;
        }
    }
}

bool indiceRepeteEmOutraPalavra(int indice){
    
    int contador = 0;
    
    for (int i = 0; i < QTD_PALAVRAS; i++) {
        
        for (int j = 0; j < 15; j++) {
            
            if (camposUsados[i][j] == indice) {
                
                contador ++;
            }
        }
    }
    if (contador > 1) {
        
        return true;
    }
    
    return false;
}

bool testePossivelCampoParaPalavra(int indices, string palavra, bool vertical){

    if (vertical) {

        int ultimoIndice = (int)(indices + (palavra.length()*TAMANHO_TABELA));

        if (ultimoIndice >= TAMANHO_TABELA*TAMANHO_TABELA) {

            return true;
        }
    }else{

        int primeiroIndeceDaLinha = 0;
        int ultimoIndiceDaLinha = 0;
        int indiceZero = indices;
        int quantidadeDeCampos = (int)palavra.length();
        int tamanhodaGrid = TAMANHO_TABELA;
        int ultimoIndice = indices + quantidadeDeCampos;

        primeiroIndeceDaLinha = (indiceZero -1)/tamanhodaGrid;
        primeiroIndeceDaLinha = primeiroIndeceDaLinha * tamanhodaGrid + 1;
        ultimoIndiceDaLinha = primeiroIndeceDaLinha+tamanhodaGrid-1;

        if (ultimoIndice <= primeiroIndeceDaLinha || ultimoIndice >= ultimoIndiceDaLinha || indices <= primeiroIndeceDaLinha || indices >= ultimoIndiceDaLinha || indices < 0 || ultimoIndice > TAMANHO_TABELA*TAMANHO_TABELA-1) {

            return true;
        }
    }

    for (int i = 0; i < QTD_PALAVRAS; i++) {
        
        for (int j = 0; j < 15; j++) {
            
            for (int k = 0; k < palavra.length(); k++) {
                
                if (camposUsados[i][j] == 0) {
                    
                    break;
                    break;
                }
                if (vertical) {
                    
                    if (camposUsados[i][j] == indices + k*TAMANHO_TABELA) {
                        
                        if (matrizArrayDePalavras[i][j] != palavra[k]) {
                            
                            return true;
                        }
                    }
                }else{
                    
                    if (camposUsados[i][j] == indices + k) {
                        
                        if (matrizArrayDePalavras[i][j] != palavra[k]) {
                            
                            return true;
                        }
                    }
                }
            }
        }
    }

    return false;
}

void adicionaCampoUsado(int indice, int palavraNumero){

    for(int j = 0; j < 15; j++){
        
        if (camposUsados[palavraNumero][j] == 0){
            
            camposUsados[palavraNumero][j] = indice;
            break;
        }
    }
}

char letraAleatoria(){

    char letraAleatoria = '\0';

    int sorteio = rand() % 26 +1;

    switch (sorteio) {
        case 1:
            letraAleatoria = 'A';
            break;
        case 2:
            letraAleatoria = 'B';
            break;
        case 3:
            letraAleatoria = 'C';
            break;
        case 4:
            letraAleatoria = 'D';
            break;
        case 5:
            letraAleatoria = 'E';
            break;
        case 6:
            letraAleatoria = 'F';
            break;
        case 7:
            letraAleatoria = 'G';
            break;
        case 8:
            letraAleatoria = 'H';
            break;
        case 9:
            letraAleatoria = 'I';
            break;
        case 10:
            letraAleatoria = 'J';
            break;
        case 11:
            letraAleatoria = 'K';
            break;
        case 12:
            letraAleatoria = 'L';
            break;
        case 13:
            letraAleatoria = 'M';
            break;
        case 14:
            letraAleatoria = 'N';
            break;
        case 15:
            letraAleatoria = 'O';
            break;
        case 16:
            letraAleatoria = 'P';
            break;
        case 17:
            letraAleatoria = 'Q';
            break;
        case 18:
            letraAleatoria = 'R';
            break;
        case 19:
            letraAleatoria = 'S';
            break;
        case 20:
            letraAleatoria = 'T';
            break;
        case 21:
            letraAleatoria = 'U';
            break;
        case 22:
            letraAleatoria = 'V';
            break;
        case 23:
            letraAleatoria = 'W';
            break;
        case 24:
            letraAleatoria = 'X';
            break;
        case 25:
            letraAleatoria = 'Y';
            break;
        case 26:
            letraAleatoria = 'Z';
            break;
    }

    return letraAleatoria;
}

string PalavraAleatoria(){

    string palavra;
    int indice;
    do{

        indice = rand() % 20 +1;

    }while(testePalavraUsada(indice));

    switch (indice) {
        case 1:
            palavra = "CELULAR";
            break;
        case 2:
            palavra = "ARVORE";
            break;
        case 3:
            palavra = "TORPEDO";
            break;
        case 4:
            palavra = "LIVRO";
            break;
        case 5:
            palavra = "REVISTA";
            break;
        case 6:
            palavra = "TELEVISAO";
            break;
        case 7:
            palavra = "REMEDIO";
            break;
        case 8:
            palavra = "BANHEIRO";
            break;
        case 9:
            palavra = "COMPUTADOR";
            break;
        case 10:
            palavra = "SORVETE";
            break;
        case 11:
            palavra = "PREGUICA";
            break;
        case 12:
            palavra = "CAVALO";
            break;
        case 13:
            palavra = "LAGARTO";
            break;
        case 14:
            palavra = "CACHORRO";
            break;
        case 15:
            palavra = "CARRO";
            break;
        case 16:
            palavra = "ELEVADOR";
            break;
        case 17:
            palavra = "ESCADA";
            break;
        case 18:
            palavra = "PREDIO";
            break;
        case 19:
            palavra = "CADERNO";
            break;
        case 20:
            palavra = "JORNAL";
    }

    return palavra;
}

bool testePalavraUsada(int indice){

    for (int i = 0; i < QTD_PALAVRAS; i ++) {

        if (palavrasUsadas[i] == indice) {

            return true;
        }else if (palavrasUsadas[i] == 0){

            palavrasUsadas[i] = indice;
            break;
        }
    }


    return false;
}
