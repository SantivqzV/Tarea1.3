// Creado por Sa�l Ortega Figueroa el 25/05/2023

#ifndef Poliformismo_h
#define Poliformismo_h
#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;
const int MAX_VIDEOS = 100;
const int MAX_PELICULAS = 50;
const int MAX_SERIES = 50;

class Poliformismo{

private:
    //arreglo de apuntadores de la clase Base
    Video *arrPrtVideos[MAX_VIDEOS];
    Pelicula *arrPtrPeliculas[MAX_PELICULAS];
    Serie *arrPtrSeries[MAX_SERIES];

    int cantidadVideos;
    int cantidadPeliculas;
    int cantidadSeries;

public:
    //Constructor default
    Poliformismo();

    //setters
    void setPtrVideo(int _index, Video *_video);
    void setCantidadVideos(int _cantidadVideos);

    //getters
    Video* getPtrVideo(int _index);
    int getCantidad();


    //Otros M�todos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas(int _oscares);
    void reporteSeries(int _cantidadEpisodios);

    void leerArchivo(string _nombre);
};
#endif /* Poliformismo_h */

