/*      Alumno: Luis Carlos Arias Camacho      Matrícula: A01364808         */

#include "Match.h"
#include "Parrafos.h"


int main(){
    
    cout << "EJERCICIO 1" << endl;
    int aut = 20;
    int gasolinerias[] = {10, 18, 12, 5, 6, 15, 3, 14, 12,1,1,1,1,2,15};
    int n = sizeof(gasolinerias)/sizeof(*gasolinerias);
    paradas(aut, gasolinerias, n);
    cout << endl << endl;
    
    cout << "EJERCICIO 2" << endl;
    int tamLinea = 26;
    int b = 2;
    vector<int> longitudes = {10,10,4,8,10,12,12};
    
    vector<linea> parrafo;
    linea nueva(tamLinea,b);
    int i = 0;
    while(i<longitudes.size()){
        if(nueva.insertarPalabra(longitudes[i]))
            i++;
        else{
            parrafo.push_back(nueva);
            nueva.clear();
            nueva.setB(b);
        }
    }
    parrafo.push_back(nueva);
    
    for(int j = 0; j < parrafo.size();j++){
        parrafo[j].print();
        cout << " con b: " << parrafo[j].getB() <<endl;
    }
    cout << endl << endl;
    
    cout << "EJERCICIO 3" << endl;
    string cadena = "La semana i de este año fue, sinceramente, muy mal organizada y ejecutada";
    string secuencia = "¿Por que preguntas eso? Como te decia, sinceramente, muy mal y cansado";
    cout << BoyerMoore(cadena, cadena.length(), secuencia, secuencia.length()) << endl;
    cout << endl << endl;
    
    cout << "EJERCICIO 4" << endl;
    vector<vector<int>> parejas = {
        { 7, 2, 5, 6, 9 },{ 9, 5, 7, 6, 2 },{ 2, 5, 9, 7, 6 },{ 6, 7, 9, 2, 5 },
        { 3, 4, 1, 8, 0 },{ 8, 3, 1, 4, 0 },{ 1, 8, 0, 3, 4 },{ 4, 3, 1, 0 ,8},
    };
    match(parejas, 5);
    
    return 0;
}
