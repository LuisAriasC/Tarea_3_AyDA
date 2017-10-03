/*
 Supongamos que tenemos n hombres y n mujeres y dos matrices M y H que contienen las preferencias de los unos por los otros. Más concretamente, la fila M[i,·] es una ordenación (de mayor a menor) de las mujeres según las preferencias del i-ésimo hombre y, análogamente, la fila H[i,·] es una ordenación (de mayor a menor) de los hombres según las preferencias de la i-ésima mujer.
 
 Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres y mujeres tal que todas las parejas formadas sean estables. Una pareja (h,m) es estable si no se da ninguna de estas dos circunstancias:
 
 Existe una mujer m’ (que forma la pareja (h’,m’)) tal que el hombre h la prefiere sobre la mujer m y además la mujer m’ también prefiere a h sobre h’.
 Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujer m lo prefiere sobre el hombre h y además el hombre h” también prefiere a m sobre la mujer m”.
 
                                                O(n^2)
 */

#ifndef Match_h
#define Match_h

#include "Subsecuencias.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool preferences(vector<vector<int>> matches, int x, int m, int y, int n){
    for (int i = 0; i < n; i++){
        if (matches[m][i] == y){
            return true;
        }
        if (matches[m][i] == x){
            return false;
        }
    }
    return true;
}


void match(vector<vector<int>> matches, int t){
    vector<int> muj;
    vector<bool> match;
    
    for (int i = 0; i < t; i++){
        match.push_back(false);
        muj.push_back(-1);
    }
    
    
    int hom = t;
    while (hom > 0){
        int hombre = 0;
        for (int i = 0; i < t; i++){
            if (match[i] == false){
                hombre = i;
                i = t;
            }
        }
        for (int i = 0; i < t && match[hombre] == false; i++){
            int mujer = matches[hombre][i];
            if (muj[mujer - t] == -1){
                muj[mujer - t] = hombre;
                match[hombre] = true;
                hom--;
            }
            else{
                int hom2 = muj[mujer - t];
                if (preferences(matches, hombre, mujer, hom2, t) == false){
                    muj[mujer - t] = hombre;
                    match[hombre] = true;
                    match[hom2] = false;
                }
            }
        }
    }
    
    cout << "Matches:" << endl;
    for (int i = 0; i < t; i++){
        cout << "Al hombre en la posición " << muj[i] << " toca match con " << i + t << endl;
    }
    
}

#endif /* Match_h */
