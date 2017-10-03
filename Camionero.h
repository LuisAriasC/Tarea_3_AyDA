/*
 Un camionero conduce desde DF a Acapulco siguiendo una ruta dada y llevando un camión que le permite, con el tanque de gasolina lleno, recorrer n kilómetros sin parar. El camionero dispone de un mapa de carreteras que le indica las distancias entre las gasolineras que hay en su ruta. Como va con prisa, el camionero desea detenerse a abastecer gasolina el menor número de veces posible.
 
 Diseñe un algoritmo eficiente que determine en qué gasolineras tiene que parar el camionero.
 
                O(n) -> Este algoritmo es lineal y depende del número de gasolineras (x)
 */

#ifndef Camionero_h
#define Camionero_h

#include <iostream>

using namespace std;

void paradas(int aut, int *gas, int n){
    int autonomia = aut;
    
    for (int i = 0; i < n; i++) {
        
        if ((autonomia-(gas[i]+gas[i+1])) <= 0) {
            autonomia = autonomia - gas[i];
            cout << "Detente en la gasolineria número:" << i+1 << "  Automia: " << autonomia << endl;
            autonomia = aut;
        }
        else {
            cout << "Pasar la gasolinería número " << i+1 << " Autonomía: " << autonomia << endl;
            autonomia = autonomia - gas[i];
        }
    }
}


#endif /* Camionero_h */
