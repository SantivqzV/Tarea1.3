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

/**
 * Convertir un IP a un valor en base 10
 * 
 * Para toda IP entra un vector temporal de 4 elementos, el primer elemento corresponde 
 *  al primer octeto de una IP y el ultimo corresponde al ultimo elemento de la IP. La
 *  formula general para la conversión es (valor de octeto 1 * 256^3) + (Valor de octeto 2 * 256^2) +
 *  (valor de octeto 3 * 256) + valor de octeto 4. Se procesa esta formula en la función y el resultado 
 *  se agrega a un vector que contiene los valores de la ip ya convertidos en base 10.
 * 
 * @param[in] vector<double> temp, vector que contiene los octetos de una dirección IP
 * @param[in, out] vector<double> ipsNuevo, vector que guarda los valores en base 10 de la IP.
 * 
 * @return vector<double> ipsNuevo, con un valor en base 10 nuevo de la IP.
 * 
 * @note complejidad de tiempo: O(n)
 * @note complejidad de espacio: O(1)
*/
void operacionConvertir(vector<double> &ipsNuevo, vector<double> &temp){
    double total;
    for(int i = 0; i <= 3; i++){
        total += temp[3-i] * (pow(256, i));
    }
    ipsNuevo.push_back(total);
}

int main(){
    ///Definir vectores para guardar los IPs orginiales y los que serán convertidos
    vector<string> ips = {"0.0.0.1","0.1.0.1","1.1.1.1"};
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

    ///Imprimir los IPs en base 10
    for(int i = 0; i < ipsConvertidos.size();i++){
        cout << ipsConvertidos[i] << endl;
    }
}
