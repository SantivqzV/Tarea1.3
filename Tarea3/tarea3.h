// -*- EstandarProgramaciónTEC-c++ -*-
/**
 * Santiago Vázquez Villarreal - A01177850
 * Manuel Adrian Gómez - A00834254
 * Saúl Ortega Figueroa - A01252717
 * 
 * Fecha de creación: 01/09/2023
 * Fecha de modificación: 01/09/2023
 * V1
 * 
 * Este archivo pertenece a tarea3.cpp, éste contiene la clase y métodos utilizados
 * para el funcionamiento del programa. 
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

/**
 * @class Linea
 * @brief Representa una línea de datos de un archivo con elementos como fecha, tiempo, Ip, información y clave numérica
 * 
 * Esta clase proporciona una estructura para almacenar y manipular datos de las líneas del archivo "bitacoraelb.txt".
 *  Cada objeto de Linea contiene la siguiente información: fecha, tiempo, IP, info, clave numérica en base 10.
 *  La clase tambien incluye métodos para imprimir, escribir en un documento, ordenar y buscar elementos
*/
class Linea {
    private:
        /// Variables correspondientes a cada elemento de una linea del archivo
        string fecha;
        string time;
        string ip;
        string info;

        /// Variable correspondiente a la IP en número base 10
        double key;
    public:
        ///Constructor por default
        Linea();
        Linea(string, string, string, string, double);

        ///Imprimir
        void print();

        ///Escribir en documento
        string escribir();

        ///Getter para clave
        double getKey(){
            return key;
        }

        ///Sorting
        void ordenaMerge(vector<Linea>, int, int, int);
        void ordenaMergeUne(vector<Linea>, int, int, int, int);

        ///Busqueda
        double busquedaBinariaLessOrEqual(vector<Linea>, double, int, int);
        double busquedaBinariaGreaterOrEqual(vector<Linea>, double, int, int);
};

/// Constructor por default de clase Linea. 
Linea::Linea(){
    fecha = "";
    time = "";
    ip = "";
    info = "";
    key = 0;
}

/**
 * Constructor base de clase linea. 
 * 
 * @param _fecha La fecha escrita en la linea
 * @param _time La hora escrita en la linea
 * @param _ip La ip escrita en la Linea
 * @param _info La info adicional escrita en la linea
 * @param _key La clave numerica en base 10 obtenida por la conversión de la IP
*/
Linea::Linea(string _fecha, string _time, string _ip, string _info, double _key ){
    fecha = _fecha;
    time = _time;
    ip = _ip;
    info = _info;
    key = _key;
}

/**
 * Imprimir objeto
 * 
 * Imprimir todos los elementos de un objeto de clase Linea
 * 
 * @param[in] _fecha La fecha escrita en la linea
 * @param[in] _time La hora escrita en la linea
 * @param[in] _ip La ip escrita en la Linea
 * @param[in] _info La info adicional escrita en la linea
 * 
 * @return impresión de linea en terminal
*/
void Linea::print(){
    cout <<  fecha << " " << time << " | IP: " << ip << " | INFO: " << info << endl;
}

/**
 * Establecer un string con la impresión de la linea.
 * 
 * Escribir en un string la linea completa para que despues pueda ser escrita en un documento aparte. 
 * 
 * @param[in] _fecha La fecha escrita en la linea
 * @param[in] _time La hora escrita en la linea
 * @param[in] _ip La ip escrita en la Linea
 * @param[in] _info La info adicional escrita en la linea
 * 
 * @return impresión de linea en terminal
*/
string Linea::escribir(){
    stringstream ss;
    ss <<  fecha << " " << time << " | IP: " << ip << " | INFO: " << info << endl;
    return ss.str();
}

/**
 * Convertir un IP a un valor en base 10
 * 
 * Para toda IP entra un vector temporal de 4 elementos, el primer elemento corresponde 
 *  al primer octeto de una IP y el ultimo corresponde al ultimo elemento de la IP. La
 *  formula general para la conversión es (valor de octeto 1 * 256^3) + (Valor de octeto 2 * 256^2) +
 *  (valor de octeto 3 * 256) + valor de octeto 4. Se procesa esta formula en la función y el resultado 
 *  se retorna a la función principal de operacionConvertirKey.
 * 
 * @param[in] vector<double> temp, vector que contiene los octetos de una dirección IP
 * @param[in, out] double total, double donde se guarda el valor de la IP convertida
 * 
 * @return total, el valor en base 10 de la IP.
 * 
 * @note complejidad de tiempo: O(n)
 * @note complejidad de espacio: O(1)
*/
void operacionConvertir(vector<double> &temp, double &total){
    for(int i = 0; i <= 3; i++){
        total += temp[3-i] * (pow(256, i));
    }
}

/**
 * Convertir un IP a un valor en base 10
 * 
 * Para toda string IP que entra, se parsea en 4 partes eliminando los 3 puntos. Cada parte se guarda
 * en un elemento de un vector temporal. Despues, ese vector se manda a operacionConvertir para poder
 * tener un resultado de tipo double que corresponde a la IP que entró en base decimal. 
 * 
 * @param[in] string ip, una IP de tipo string
 * 
 * @return total, el valor en base 10 de la IP
 * 
 * Complejidad de Tiempo: O(n)
 * Complejidad de Espacio: O(1)
 * 
*/
double operacionConvertirKey(string ip){
 ///Definir variables para las iteraciones
        string target = ip;
        string octet = "";
        double total;
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
        operacionConvertir(temp, total);
        return total; 
}


/**
 * Función complemento de método de ordenamiento Merge
 * 
 * Esta función auxiliar se utiliza para combinar los subvectores resultantes 
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

void ordenaMergeUne(vector<Linea> &arr, int start, int end, int mid, int size){
    int i = start;
    int j = mid + 1;
    int k = start;

    vector<Linea> temp(size);
    
    ///Se utiliza getKey() debido a que arr[i] y arr[j] iteran por un vector de elementos, se necesita el getKey para poder comparar IPs
    while(i <= mid && j <= end){
        if(arr[i].getKey() < arr[j].getKey()){
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
 * @param[in, out] vector<Linea> arr, el vector de numeros a ordenar
 * @param[in] start, indice de inicio del vector
 * @param[in] end, indice final del vector
 * @param[in] size, tamaño del vector orginal que entra a la función "ordenaMerge"
 * 
 * @return el mismo vector<double> arr ordenado de forma ascendente
 * 
 * Complejidad de tiempo: O(nlog(n))
 * Complejidad de espacio: O(n)
*/
void ordenaPorMerge(vector<Linea> &arr, int start, int end, int size){
    if(start < end){
        int mid = (start + end)/2;

        ///Llama recursivamente a la misma función para dividir en mitades
        ordenaPorMerge(arr, start, mid, size);
        ordenaPorMerge(arr, mid + 1, end, size);

        ///llama a la función para unir las mitades ordenadas
        ordenaMergeUne(arr, start, end, mid, size);
    }
}

/**
 * Buscar con el método binario (Variación: First Greater Than Or Equal)
 * 
 * Este método busca el primer elemento en un vector ordenado que sea mayor o igual al valor objetivo. 
 * 
 * @param[in] vector<Linea> arr, el vector donde se encuentran los datos a buscar
 * @param[in] double target, el valor a buscar en el vector
 * @param[in] int left, el valor del índice de inicio
 * @param[in] int right, el valor del índice final (size - 1)
 * 
 * @return double result, índice donde se encuentra el primer valor mayor o igual al target
 * 
 * Complejidad de Tiempo: O(nLog(n))
 * Complejidad de Espacio: O(1)
*/
double binarySearchFirstGreaterThanOrEqual(vector<Linea>& arr, double target, int left, int right){
    double result = -1;  
    
    while (left <= right) {
        int mid = (left + right)/2;
        ///El valor del vector a comparar, se utiliza el getter debido a que el vector esta conformado por objetos de tipo linea
        double midVal = arr[mid].getKey();

        if(midVal >= target){
            //Se busca en la parte izquierda del arreglo
            //Como se esta buscando un valor mayor o igual al objetivo, el mid se guarda como respuesta
            result = mid;
            right = mid - 1;
        }
        
        else{
            ///Se busca en la parte derecha del vector
            left = mid + 1;
        }
    }

    return result;
}

/**
 * Buscar con el método binario (Variación: Last Less Than Or Equal)
 * 
 * Este método busca el último elemento en un vector ordenado que sea menor o igual al valor objetivo. 
 * 
 * @param[in] vector<Linea> arr, el vector donde se encuentran los datos a buscar
 * @param[in] double target, el valor a buscar en el vector
 * @param[in] int left, el valor del índice de inicio
 * @param[in] int right, el valor del índice final (size - 1)
 * 
 * @return double result, índice donde se encuentra el último valor menor o igual al target
 * 
 * Complejidad de Tiempo: O(nLog(n))
 * Complejidad de Espacio: O(1)
*/
double binarySearchLastLessThanOrEqual(vector<Linea>& arr, double target, int left, int right){
    double result = -1;  
    
    while (left <= right) {
        int mid = (left + right)/2;
        ///El valor del vector a comparar, se utiliza el getter debido a que el vector esta conformado por objetos de tipo linea que no se pueden comparar con un double. 
        double midVal = arr[mid].getKey();

        if(midVal <= target){
            ///Se busca en la parte derecha del arreglo
            ///Como se busca el último número menor o igual al objetivo, se guarda el valor de mid como resultado
            result = mid;
            left = mid + 1;
        }
        else{
            ///Se busca en la parte izquierda del arreglo
            right = mid - 1;
        }
    }

    return result;
}
