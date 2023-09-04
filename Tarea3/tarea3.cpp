/**
 * Santiago Vázquez Villarreal - A01177850
 * Adrian Gómez
 * Saúl Ortega
 * 
 * Fecha de creación: 01/09/2023
 * Fecha de modificación: 01/09/2023
 * V1
 * 
*/
#include <iostream>
#include <vector>
#include <math.h>
#include "tarea3.h"
using namespace std;

int main(){
    ///Definir vectores para guardar los IPs orginiales y los que serán convertidos
    vector<string> ips = {"1.0.0.1", "0.0.0.2", "0.1.0.1","192.02.12.1","0.0.0.0","0.1.1.1","1.1.1.1"};
    vector<Linea> elementos;
    
    ///Loop para iterar sobre el vector de la IP original
    for(int i = 0; i < ips.size();i++){
        string ipTemp = ips[i];
        elementos.push_back(Linea("","",ipTemp,"",operacionConvertirKey(ips[i])));
    }

    ///Variables para método de ordenamiento
    int start = 0;
    int end = elementos.size() - 1;

    ///Ordenar la información en base a la IP
    ordenaMerge(elementos, 0, end,elementos.size());

    ///Desplegar Fecha, Hora, IP en formato original, INFO
    for (int i = 0; i < elementos.size(); i++) {
        elementos[i].print();
    }
}
