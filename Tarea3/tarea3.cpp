/**
 * Santiago Vázquez Villarreal - A01177850
 * Adrian Gómez
 * Saúl Ortega - A01252717
 * 
 * Fecha de creación: 01/09/2023
 * Fecha de modificación: 01/09/2023
 * V1
 * 
*/
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
    vector<Linea> elementos;

    ifstream archivo("bitacoraelb.txt");
    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return 1;
    }
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

    ///Loop para iterar sobre el vector de la IP original
    for(int i = 0; i < ips.size();i++){
        string fechaTemp = fechas[i];
        string horasTemp = horas[i];
        string ipTemp = ips[i];
        string infoTemp = info[i];
        
        elementos.push_back(Linea(fechaTemp,horasTemp,ipTemp,infoTemp,operacionConvertirKey(ips[i])));
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
