/*
 Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} es una subsecuencia de X 
 (siendo k ≤ m) si existe una secuencia creciente {i1 i2 ... ik} de índices de X tales que 
 para todo j = 1, 2, ..., k  tenemos xij = zj.
 Dadas dos secuencias X e Y, se dice que Z es una subsecuencia común de X e Y si es
 subsecuencia de X y subsecuencia de Y.
 Diseñe un algoritmo que permita determinar la subsecuencia de longitud máxima
 común a dos secuencias.
 La complejiad de mi algoritmo es igual a n*m porque se recorren las dos
 secuencias una de jongitud n y otra de longitud m
 
                                            O(n*m)
 */

#ifndef Subsecuencias_h
#define Subsecuencias_h

#include "Camionero.h"
#include <string>


using namespace std;

int check_final(string text, int i, string subtext, int j){
    int max = 0;
    while(text[i] == subtext[j]){
        ++i;
        ++j;
        max++;
    }
    return max;
}


string find_ij(string text, int i, string subtext, int j){
    string max = " ";
    while(text[i] == subtext[j]){
        max += text[i];
        ++i;
        ++j;
    }
    return max;
}


string BoyerMoore(string text, int n , string subtext, int m){
    string subsecuencia;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(text[i] == subtext[j]){
                if(check_final(text, i, subtext, j) >= subsecuencia.length()){
                    subsecuencia = find_ij(text, i, subtext, j);
                }
            }
        }
    }
    if (subsecuencia.length() == 0){
        return "No existe ninguna subsecuencia";
    }else{
        return subsecuencia;
    }
}



#endif /* Subsecuencias_h */
