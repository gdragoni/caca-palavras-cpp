//
//  PalavrasAleatorias.hpp
//  CacaPalavras
//
//  Created by Gabriel A. Dragoni on 3/18/16.
//  Copyright © 2016 Gabriel A. Dragoni. All rights reserved.
//

#ifndef PalavrasAleatorias_hpp
#define PalavrasAleatorias_hpp

#include <cstring>
#include <iostream>                                     /*biblioteca cout cin*/
#include <cstring>                                      /*biblioteca para string*/
#include <cstdlib>                                      /*<stdlib>*/
#include <stdio.h>                                      /* printf, NULL */
#include <stdlib.h>                                     /* srand, rand */
#include <time.h>                                       /* time */

using namespace std;

class PalavrasAleatorias{               /* Arquivo cabecalho, usado para encapsular os metodos dessa classe */
    
protected:
        
public:
    
    PalavrasAleatorias(void){        /* metodo contrutor*/
       
    }
    ~PalavrasAleatorias(void){      /* metodo destrutor*/
        
        
    }
    
   string palavra(string tema);     /*metodo publico para retornar uma palavra aleatoria com tema escolhido*/
    char letra();                   /*metodo publico retoran letra aleatoria*/
};

#endif /* PalavrasAleatorias_hpp */
