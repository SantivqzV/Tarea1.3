//Creado por Sa�l Ortega Figueroa el 25/05/2023
//

#include "Poliformismo.h"

using namespace std;
//Constructor default
Poliformismo::Poliformismo(){
    //incializar el arreglo de apuntadores con nullptr y cantidad con 0
    for(int index = 0; index < MAX_VIDEOS; index++)
    arrPrtVideos[index] = nullptr;
    cantidadVideos = 0;

    for(int index = 0; index < MAX_PELICULAS; index++)
    arrPtrPeliculas[index] = nullptr;
    cantidadPeliculas = 0;

    for(int index = 0; index < MAX_SERIES; index++)
    arrPtrSeries[index] = nullptr;
    cantidadSeries = 0;
}

void Poliformismo::reporteInventario(){
    //Pelicula peli;
    int contPelis = 0;
    int contSeries = 0;

    //ciclo for para recorrer tood el arrPtrVideos
    for(int index = 0; index < cantidadVideos; index++){
        // usar typeID( )para verificar el tipo del apuntador
        if(typeid(*arrPrtVideos[index]) == typeid(Pelicula)){
            contPelis++;
        }
        else{
            contSeries++;
        }
        cout << arrPrtVideos[index]->str() << endl;
    }

    //Desplegar la cantidad de Pel�culas y la cantidad de Series
    cout << "Peliculas = " << contPelis << endl;
    cout << "Series = " << contSeries << endl;
}

void Poliformismo::reporteCalificacion(double _calificacion){
    //declarar contador
    int contador = 0;

    //for para recorrer el arreglo de apuntadores
    for(int index = 0; index < cantidadVideos; index++){
        //verificar si tiene la calificacion solicitada
        if (arrPrtVideos[index]->getCalificacion() == _calificacion){
            cout << arrPrtVideos[index]->str() << endl;
            contador++;
        }
    }
    //desplegar el total
    cout << "total = " << contador << endl;
}

void Poliformismo::reporteGenero(string _genero){
    //declarar el contador
    int contador = 0;

    //recorrer todo el arreglo de apuntadores de PrtVideo
    for(int index = 0; index < cantidadVideos; index++){
        //verificar si tiene el genero solicitado
        if (arrPrtVideos[index]->getGenero() == _genero){
            cout << arrPrtVideos[index]->str() << endl;
            contador++;
        }
    }
    //desplegar el total de videos de ese genero
    cout << "total = " << contador << endl;
}

void Poliformismo::reportePeliculas(int _oscares){
    //delcarar el contador
    double contador = 0;
    int sumaCalificaciones = 0;

    for (int index = 0; index < cantidadPeliculas; index++){
        if (arrPtrPeliculas[index]->getOscares() == _oscares){
            sumaCalificaciones = sumaCalificaciones + arrPtrPeliculas[index]->getCalificacion();
            cout << arrPtrPeliculas[index]->str() << endl;
            contador++;
        }
    }
    if (sumaCalificaciones > 0){
    //cout << "suma = " << sumaCalificaciones << endl;
    //cout << "contador = " << contador << endl;
    cout << "cal promedio = " << sumaCalificaciones/contador << endl;
    }
    else{
        cout << "no peliculas\n";
    }
}

void Poliformismo::reporteSeries(int _cantidadEpisodios){
    //declarar el contador y variables para promedio
    double contador = 0;
    int sumaCalificaciones = 0;

    for (int index = 0; index < cantidadSeries; index++){
        if (arrPtrSeries[index]->getCantidad() == _cantidadEpisodios){
            sumaCalificaciones = sumaCalificaciones + arrPtrSeries[index]->getCalificacion();
            cout << arrPtrSeries[index]->str() << endl;
            contador++;
        }
    }
    if (sumaCalificaciones > 0){
        cout << "cal promedio = " << sumaCalificaciones/contador << endl;
    }
    else{
        cout << "no series\n";
    }
}

void Poliformismo::setPtrVideo(int _index, Video *_video){
    if (_index >=0 && _index < MAX_VIDEOS){
        arrPrtVideos[_index] = _video;
    }
}

void Poliformismo::setCantidadVideos(int _cantidad){
    if (_cantidad >= 0 && _cantidad <= MAX_VIDEOS-1)
        cantidadVideos = _cantidad;
}

Video* Poliformismo::getPtrVideo(int _index){
    if (_index >= 0 && _index < MAX_VIDEOS){
        return arrPrtVideos[_index];
    }
    return nullptr;
}

int Poliformismo::getCantidad(){
    return cantidadVideos;
}

void Poliformismo::leerArchivo(string nombre ){
    int index;
    Episodio episodio;
    fstream entrada;
    // row - arreglo de 7 elementos de strings, para almacenar los datos de la l�nea del archivo ya separados
    string row[7];
    // line- almacena la linea le�da, y word la palabra que se saca de line
    string line, word;
    //contadores de pel�culas y series, incialmente son 0
    int iR = 0;

    //Abrir archivo de entrada
    entrada.open(nombre, ios::in);

    //getline(entrada,line) - lee una l�nea del archivo y almacena en line
    while ( getline(entrada,line)){
        //usado para separar las palabras split()
        stringstream s(line);
        //cout << "line = " << line << endl; //borrar
        //Cada vez que inicia una nueva l�nea inicializar iR = 0
        iR = 0;

        //Ciclo que extrae caracteres de s y los almacena en word hasta que encuenta el delimitador ","
        while ( getline(s, word, ',')){
            //a�ade la word al arreglo row e incrementa iR p/la proxima palabra.
            row[iR++] = word;
        }

        //Determinar si la linea es P-Pelicula, S-Serie, E-Episodio
        if (row[0] == "P"){
            //se crea un apuntador usando el operador new y el constructor con par�metros y se guarda en el arrPtrPeliculas
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula( row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            // cout << "Pelicula" << arrPeliculas[cantidadPeliculas]->str() << endl;
            cantidadPeliculas++; //inc la cantidad de peliculas
        }
        else if (row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie( row[1], row[2], stoi(row[3]),row[4], stod(row[5]));
            //cout << "Serie" << arrSeries[cantidadSeries]->str() << endl;
            cantidadSeries++;
        }
        else if (row[0] == "E"){
            //Calcular a qu� Serie le pertenece el episodio
            index = stoi(row[1]) - 500;
            //Se agrega el episodio usando el m�todo agregaEpisodio
            //Se crea el apuntador y se convierte a objeto usando el operador de indirecci�n
            arrPtrSeries[index]->agregaEpisodio(*(new Episodio( row[2], stoi(row[3]), stoi(row[4]))));
            //cout << "Episodio" << arrSeries[index]->str() << endl;
        }
    }
    //fuera del ciclo
    // ya se termino de ller toto el archivo ahora se guarlos
    // apuntadores de Pelicula y Seire en el arrPtrVideo
    // copiar todos los apuntadores del arreglo de Series al arreglo de apuntadores de Video
    double promedio;

    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index]->calcularPromedio();
        arrPrtVideos[cantidadVideos++] = arrPtrSeries[index];
    }

    //copiar todos los apuntadores del arreglo de Peliculas al arreglo de apuntadores de Video
    for(int index = 0; index < cantidadPeliculas; index++){
        arrPrtVideos[cantidadVideos++] = arrPtrPeliculas[index];
    }


    //Desplegar todo el contenido del arreglo de apuntadores de la clase Video (Base) - se da el POLIFORMISMO
    // el m�todo str() que corresponde al tipo del apuntador almacenado, no el correspondiente al tipo del arreglo.
    for (int index = 0; index < cantidadVideos; index++){
        cout << index << " " << arrPrtVideos[index]->str() << endl;
    }

    entrada.close(); // cerrar el archivo
    //cout << "Se leyo\n"; //Borrar
}
