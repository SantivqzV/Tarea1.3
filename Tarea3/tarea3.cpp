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
    vector<string> ips = {"0.1.0.1","0.0.0.1","1.0.1.1","0.0.1.0"};
    vector<double> ipsConvertidos = {};
    
    ///Loop para iterar sobre el vector de la IP original
    for(int i = 0; i < ips.size();i++){
        ///Definir variables para las iteraciones
        string target = ips[i];
        string octet = "";

        ///Definir vector de octetos y el vector temporal
        vector<string> octets;
        vector<double> temp;

        ///Loop para parsear el string de la IP y quedar con 4 octetos
        for(int j = 0; j < target.size();j++){
            if(target[j] == '.'){
                octets.push_back(octet);
                octet = "";
            }
            else{
                octet += target[j];
            }
        }
        octets.push_back(octet);

        ///Cambiar los octetos a double y pasarlos al vector temporal
        for(int j = 0; j < octets.size(); j++){
            temp.push_back(stod(octets[j]));
        }

        ///Llamar la operacionConvertir para hacer la conversión de los octetos a un número de base 10
        operacionConvertir(ipsConvertidos,temp);
    }

    ///Variables para método de ordenamiento
    int start = 0;
    int end = ipsConvertidos.size() - 1;

    ///Llamar a ordenaMerge
    ordenaMerge(ipsConvertidos, start, end, ipsConvertidos.size());
    
    ///Imprimir los IPs en base 10
    for(int i = 0; i < ipsConvertidos.size();i++){
        cout << ipsConvertidos[i] << endl;
    }
}
