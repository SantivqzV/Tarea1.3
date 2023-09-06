/**
 * Santiago Vázquez Villarreal - A01177850
 * Adrian Gómez
 * Saúl Ortega Figueroa - A01252717
 * 
 * Fecha de creación: 01/09/2023
 * Fecha de modificación: 01/09/2023
 * V1
 * 
 * Este programa tienen como objetivo procesar un archivo llamado "bitacoraelb.txt", el cual contiene registros 
 * con direcciones IP y otros datos. El programa realiza lo siguiente:
 * 1. Lee el archivo y guarda los registros en vectores para fecha, hora, Ip e información.
 * 2. Crea objetos para cada registro y almacena los elementos en ellos
 * 3. Ordena los objetos de tipo Linea de manera ascendente en función de las IPs
 * 4. Posteriormente el usuario podrá solicitar dos direcciones IP que definen un rango de busqueda
 * 5. el programa mostrará los datos que corresponden a ese rango. 
 * 6. Finalmente, se guardará el resultado del ordenamiento en un archivo.
 * 
 * Notas:
 * - Se utiliza una función operacionConvertirKey para convertir las direcciones IP en números base 10 para comparación
 * - El programa hace uso de la función ordenaPorMerge para ordenar los registros en base a la IP.
 * */
#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <sstream>
#include "tarea3.h"
using namespace std;


int main(){
    ///Definir vectores para guardar los IPs orginiales y los que serán convertidos
    vector<string> fechas;
    vector<string> horas;
    vector<string> ips;
    vector<string> info;

    ///Definir el vector donde serán guardado los objetos que corresponden a cada linea de código
    vector<Linea> elementos;

    ///Leer el archivo
    ifstream archivo("bitacoraelb.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }

    ///Parsear el archivo linea por linea guardando sus elementos en los vectores predefinidos
    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string fecha, mes, dia, hora, ip, informacion;
        ss >> fecha; // Leer el año
        ss >> mes;   // Leer el mes
        ss >> dia;   // Leer el día
        ss >> hora;  // Leer la hora
        ss.ignore(6); // Ignorar " | IP: "
        ss >> ip;     // Leer la IP
        ss.ignore(8); // Ignorar " | INFO: "
        getline(ss, informacion);
        string fecha_completa = fecha + " " + mes + " " + dia;
        fechas.push_back(fecha_completa);
        horas.push_back(hora);
        ips.push_back(ip);
        info.push_back(informacion);
    }
    archivo.close();

    ///Loop para iterar sobre el vector de la IP original y crear objetos para cada linea
    for(int i = 0; i < ips.size();i++){
        string fechaTemp = fechas[i];
        string horasTemp = horas[i];
        string ipTemp = ips[i];
        string infoTemp = info[i];

        ///Crear objeto
        elementos.push_back(Linea(fechaTemp,horasTemp,ipTemp,infoTemp,operacionConvertirKey(ips[i])));
    }

    ///Variables para método de ordenamiento
    int start = 0;
    int end = elementos.size() - 1;

    ///Ordenar la información en base a la IP
    ordenaPorMerge(elementos, 0, end,elementos.size());

    ///Busqueda de rango de IPs
    ///Pedir al usuario que ingrese 2 IPs para establecer el rango de busqueda
    string inicio;
    string fin;
    cout << "Ingresa el rango de IPs que desea buscar" << endl;
    cin >> inicio;
    cin >> fin;

    ///Convertir los ips a su número equivalente en base 10
    double a = operacionConvertirKey(inicio);
    double b = operacionConvertirKey(fin);

    ///Buscar los indices para el rango de busqueda
    double menor = binarySearchFirstGreaterThanOrEqual(elementos, a, 0, elementos.size() - 1);
    double mayor = binarySearchLastLessThanOrEqual(elementos, b, 0, elementos.size() - 1);

    ///Imprimir el resultado de la busqueda del rango.
    cout << endl << "Resultado de Busqueda: " << endl; 
    for(menor; menor <= mayor; menor++){
        elementos[menor].print();
    }
    
    ///Crear un archivo de tipo texto y escribirle toda la información ordenada de forma ascendente en función de la IP
    ofstream Myfile("libreriaOrdenada.txt");
    for (int i = 0; i < elementos.size(); i++) {
        Myfile << elementos[i].escribir();
    }
}
