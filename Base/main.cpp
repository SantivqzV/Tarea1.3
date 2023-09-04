//
//  main.cpp
//  Avance2
//
//  Created by Ma. Guadalupe Roque Díaz de León on 30/05/23.
//

#include <iostream>
#include "Video.h"
#include "Poliformismo.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
void poliformismo(Poliformismo inventario){
    int opcion, oscares, cantidadEpisodios;
    double calificacion;
    string genero;


    cin >> opcion;

    switch (opcion) {
        case 1:
            cin >> calificacion;
            inventario.reporteCalificacion(calificacion);
            break;

        case 2:
            cin >> genero;
            inventario.reporteGenero(genero);
            break;

        case 3:
            inventario.reporteInventario();
            break;

        case 4:
            cin >> oscares;
            inventario.reportePeliculas(oscares);
            break;

        case 5:
            cin >> cantidadEpisodios;
            inventario.reporteSeries(cantidadEpisodios);
            break;

        default:
            cout << "Error\n";
            break;
    }


}
int main() {

        // Declaracion de objetos
        Video viernes;
        Pelicula pel;
        Serie serie2;
        Poliformismo neflix;

        Episodio episodio_viernes{"Tigres_Rayados", 90, 100};
        Episodio episodio_sabado{"Tigres_Campeones", 90, 100};
        Pelicula peli{"0001", "Tigres_Chivas", 600, "Deportes", 100.0, 20};
        Serie serie1{"0002", "POO", 500, "Programacion", 100};

        int opcion;

        // Añadir episodios a la serie1
        serie1.agregaEpisodio(episodio_viernes);
        serie1.agregaEpisodio(episodio_sabado);

        // leer la opcion
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << serie1.getGenero() << endl;
                cout << serie1.getDuracion() << endl;
                cout << serie1.getCalificacion() << endl;
                cout << serie1.getEpisodio(0).str() << endl;
                cout << serie1.getEpisodio(1).str() << endl;
                cout << serie1.str() << endl;
                break;

            case 2:
              cout << "CDV=" << viernes.str() << endl;
              cout << "CDP=" << pel.str() << endl;
              cout << "CDS=" << serie2.str() << endl;
                break;

            case 3:
               neflix.leerArchivo("/Users/orteg/OneDrive/Documentos/CodeBlocks/Avance2_final/Inventario1.csv");
                    poliformismo(neflix);
               break;

            case 4:
                neflix.leerArchivo("/Users/orteg/OneDrive/Documentos/CodeBlocks/Avance2_final/Inventario2.csv");
                    poliformismo(neflix);
              break;

        default:
              cout << "incorrecta" ;
        }

    return 0;
}
