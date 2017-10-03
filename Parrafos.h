/*
 Dada una secuencia de palabras p1, p2, ..., pn de longitudes l1, l2, ..., ln se desea agruparlas en líneas de longitud L. Las palabras están separadas por espacios cuya amplitud ideal (en milímetros) es b, pero los espacios pueden reducirse o ampliarse si es necesario (aunque sin solapamiento de palabras), de tal forma que una línea pi, pi+1, ..., pj tenga exactamente longitud L. Sin embargo, existe una penalización por reducción o ampliación en el número total de espacios que aparecen o desaparecen. El costo de fijar la línea pi, pi+1, ..., pj es (j – i)|b’ – b|, siendo b’ el ancho real de los espacios, es decir (L – li – li+1 – ... – lj)/(j – i). No obstante, si j = n (la última palabra) el costo será cero a menos que b’ < b (ya que no es necesario ampliar la última línea).
 
 Diseñe un algoritmo para resolver el problema.
 
                                            O(n)

 */

#ifndef Parrafos_h
#define Parrafos_h

#include <iostream>
#include <vector>
using namespace std;

class linea{
    int maxTam;
    int b;
    int total;
    vector<int> palabras;
public:
    linea(int maxTam,int b){
        this->maxTam = maxTam;
        this->b = b;
        total = 0;
    }
    bool insertarPalabra(int palabra){
        if(getLongitud()+palabra+b > maxTam){
            if(!pasarSiguiente(palabra)){
                while(b>=2){
                    b--;
                    if (getLongitud()+palabra <= maxTam){
                        palabras.push_back(palabra);
                        total += palabra;
                        return true;
                    }
                }
            }
            else{
                while(getLongitud() != maxTam){
                    b++;
                }
                return false;
            }
        }
        else{
            palabras.push_back(palabra);
            total += palabra;
            return true;
        }
        return false;
    }
    
    bool pasarSiguiente(int palabra){
        int original = b;
        unsigned long costoAchicar = 0;
        unsigned long costoPasarSiguiente = 0;
        bool cabe = false;
        while(b>=2){
            b--;
            costoAchicar++;
        }
        if (getLongitud()+palabra <= maxTam){
            cabe = true;
        }
        b = original;
        while(getLongitud() != maxTam){
            b++;
            costoPasarSiguiente++;
        }
        costoAchicar = palabras.size()* costoAchicar;
        costoPasarSiguiente = (palabras.size()-1)* costoPasarSiguiente;
        b = original;
        if (cabe == true)
            return costoAchicar > costoPasarSiguiente;
        else
            return true;
    }
    
    void setB(int b){
        this->b = b;
    }
    int getB(){
        return b;
    }
    unsigned long getLongitud(){
        return total+(b*(palabras.size()-1));
    }
    void clear(){
        total = 0;
        palabras.clear();
    }
    void print(){
        for(int i = 0; i < palabras.size();i++){
            cout << palabras[i] << " ";
        }
    }
};


#endif /* Parrafos_h */
