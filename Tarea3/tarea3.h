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