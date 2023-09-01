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

/**
 * Función complemento de método de ordenamiento Merge
 * 
 * Esta función auxiliar funciona para combinar los subvectores resultantes 
 *  de las operaciones realizadas en la función ordenaMerge.
 * 
 * @param[in, out] vector<double> arr, El vector de números a ordenar
 * @param[in] start, indice de inicio del primer subvector
 * @param[in] end, indice final del segundo subvector
 * @param[in] mid, indice medio que divide los subvectores
 * @param[in] size, tamaño del vector orginal que entra a la función "ordenaMerge"
 * 
 * @return el mismo vector<double> arr con los elementos combinados y ordenados
 * 
 * Complejidad de Tiempo: O(n)
 * Complejidad de Espacio: O(n)
*/

void ordenaMergeUne(vector<double> &arr, int start, int end, int mid, int size){
    int i = start;
    int j = mid + 1;
    int k = start;

    vector<double> temp(size);

    while(i <= mid && j <= end){
        if(arr[i] < arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    ///Copiar los elementos restantes del arreglo al vector temporal 
    while(i <= mid){
        temp[k] = arr[i];
        i++;
        k++;
    }

    ///Copiar los elementos restantes del arreglo al vector temporal
    while(j <= end){
        temp[k] = arr[j];
        j++;
        k++;
    }

    ///Pasar toda la información del arreglo temporal al arreglo principal
    for(int x = start; x <= end; x++){
        arr[x] = temp[x];
    }
}

/**
 * Ordenar con el método de merge
 * 
 * Este método divide el vector en subvectores más pequeños, los ordena y luego
 *  los combina mediante la función de ordenaMergeUne para obtener un vector ordenado
 * 
 * @param[in, out] vector<double> arr, el vector de numeros a ordenar
 * @param[in] start, indice de inicio del vector
 * @param[in] end, indice final del vector
 * @param[in] size, tamaño del vector orginal que entra a la función "ordenaMerge"
 * 
 * @return el mismo vector<double> arr ordenado de forma ascendente
 * 
 * Complejidad de tiempo: O(nlog(n))
 * Complejidad de espacio: O(n)
*/
void ordenaMerge(vector<double> &arr, int start, int end, int size){
    if(start < end){
        int mid = (start + end)/2;

        ///Llama recursivamente a la misma función para dividir en mitades
        ordenaMerge(arr, start, mid, size);
        ordenaMerge(arr, mid + 1, end, size);

        ///llama a la función para unir las mitades ordenadas
        ordenaMergeUne(arr, start, end, mid, size);
    }
}
