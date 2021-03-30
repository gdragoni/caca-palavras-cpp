//
//  PalavrasAleatorias.cpp
//  CacaPalavras
//
//  Created by Gabriel A. Dragoni on 3/18/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#include "PalavrasAleatorias.hpp"

int palavrasUsadas[20];

string PalavraAleatoriaTemaAnimal();
string PalavraAleatoriaTemaFruta();
string PalavraAleatoriaTemaObjeto();
string PalavraAleatoriaTemaNome();

bool testePalavraUsada(int indice);

string PalavrasAleatorias::palavra(string tema){
    
    if (tema == "ANIMAL") {
        
        return PalavraAleatoriaTemaAnimal();
    }else if (tema == "FRUTA"){
        
        return PalavraAleatoriaTemaFruta();
    }else if (tema == "OBJETO"){
        
        return PalavraAleatoriaTemaObjeto();
    }else if (tema == "NOME"){
        
        return PalavraAleatoriaTemaNome();
    }else if (tema == "MISTURADO"){
        
        int sorteio = rand() % 4;
        
        switch (sorteio) {
            case 0:
                
                return PalavraAleatoriaTemaAnimal();
                break;
            case 1:
                
                return PalavraAleatoriaTemaFruta();
                break;
            case 2:
                
                return PalavraAleatoriaTemaObjeto();
                break;
            case 3:
                
                return PalavraAleatoriaTemaNome();
        }
    }
    
    return NULL;
}

string PalavraAleatoriaTemaAnimal(){
    
    string palavra;
    int indice;
    do{
        
        indice = rand() % 20 +1;
        
    }while(testePalavraUsada(indice));
    
    switch (indice) {
        case 1:
            palavra = "GATO";
            break;
        case 2:
            palavra = "GAFANHOTO";
            break;
        case 3:
            palavra = "LONTRA";
            break;
        case 4:
            palavra = "URSO";
            break;
        case 5:
            palavra = "GAVIAO";
            break;
        case 6:
            palavra = "GIRAFA";
            break;
        case 7:
            palavra = "JACARE";
            break;
        case 8:
            palavra = "URUBU";
            break;
        case 9:
            palavra = "SAPO";
            break;
        case 10:
            palavra = "CAMELO";
            break;
        case 11:
            palavra = "CAPIVARA";
            break;
        case 12:
            palavra = "LEOPARDO";
            break;
        case 13:
            palavra = "LAGARTO";
            break;
        case 14:
            palavra = "CACHORRO";
            break;
        case 15:
            palavra = "ABELHA";
            break;
        case 16:
            palavra = "ZEBRA";
            break;
        case 17:
            palavra = "POLVO";
            break;
        case 18:
            palavra = "TUBARAO";
            break;
        case 19:
            palavra = "BALEIA";
            break;
        case 20:
            palavra = "MACACO";
    }
    
    return palavra;
}

string PalavraAleatoriaTemaFruta(){
    
    string palavra;
    int indice;
    do{
        
        indice = rand() % 20 +1;
        
    }while(testePalavraUsada(indice));
    
    switch (indice) {
        case 1:
            palavra = "GOIABA";
            break;
        case 2:
            palavra = "ABACATE";
            break;
        case 3:
            palavra = "ABACAXI";
            break;
        case 4:
            palavra = "PERA";
            break;
        case 5:
            palavra = "LARANJA";
            break;
        case 6:
            palavra = "LIMAO";
            break;
        case 7:
            palavra = "ACEROLA";
            break;
        case 8:
            palavra = "DAMASCO";
            break;
        case 9:
            palavra = "FRAMBOESA";
            break;
        case 10:
            palavra = "TANGERINA";
            break;
        case 11:
            palavra = "MEXERICA";
            break;
        case 12:
            palavra = "FIGO";
            break;
        case 13:
            palavra = "CAJU";
            break;
        case 14:
            palavra = "AMORA";
            break;
        case 15:
            palavra = "BANANA";
            break;
        case 16:
            palavra = "MANGA";
            break;
        case 17:
            palavra = "MORANGO";
            break;
        case 18:
            palavra = "KIWI";
            break;
        case 19:
            palavra = "MELANCIA";
            break;
        case 20:
            palavra = "PESSEGO";
    }
    
    return palavra;
}

string PalavraAleatoriaTemaObjeto(){
    
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
            palavra = "GARRAFA";
            break;
        case 3:
            palavra = "CADEIRA";
            break;
        case 4:
            palavra = "MESA";
            break;
        case 5:
            palavra = "GAVETA";
            break;
        case 6:
            palavra = "ARMARIO";
            break;
        case 7:
            palavra = "CANETA";
            break;
        case 8:
            palavra = "RADIO";
            break;
        case 9:
            palavra = "COMPUTADOR";
            break;
        case 10:
            palavra = "APONTADOR";
            break;
        case 11:
            palavra = "CARTEIRA";
            break;
        case 12:
            palavra = "PORTA";
            break;
        case 13:
            palavra = "PRATO";
            break;
        case 14:
            palavra = "GELADEIRA";
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

string PalavraAleatoriaTemaNome(){
    
    string palavra;
    int indice;
    do{
        
        indice = rand() % 20 +1;
        
    }while(testePalavraUsada(indice));
    
    switch (indice) {
        case 1:
            palavra = "GABRIEL";
            break;
        case 2:
            palavra = "WELLINGTON";
            break;
        case 3:
            palavra = "MATHEUS";
            break;
        case 4:
            palavra = "IGOR";
            break;
        case 5:
            palavra = "YURI";
            break;
        case 6:
            palavra = "MARIA";
            break;
        case 7:
            palavra = "JEFERSON";
            break;
        case 8:
            palavra = "GUSTAVO";
            break;
        case 9:
            palavra = "LUCAS";
            break;
        case 10:
            palavra = "FELIPE";
            break;
        case 11:
            palavra = "MARCOS";
            break;
        case 12:
            palavra = "DENISE";
            break;
        case 13:
            palavra = "SABRINA";
            break;
        case 14:
            palavra = "SUZETE";
            break;
        case 15:
            palavra = "JULIANA";
            break;
        case 16:
            palavra = "DOUGLAS";
            break;
        case 17:
            palavra = "TATIANE";
            break;
        case 18:
            palavra = "LUCIANA";
            break;
        case 19:
            palavra = "FLAVIO";
            break;
        case 20:
            palavra = "TEREZA";
    }
    
    return palavra;
}

char PalavrasAleatorias::letra(){
    
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

bool testePalavraUsada(int indice){
    
    for (int i = 0; i < 20; i ++) {
        
        if (palavrasUsadas[i] == indice) {
            
            return true;
        }else if (palavrasUsadas[i] == 0){
            
            palavrasUsadas[i] = indice;
            break;
        }
    }
    
    return false;
}