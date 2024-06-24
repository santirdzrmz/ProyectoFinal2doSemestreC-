/*
- Nombre: Santiago Rodriguez 
- Matricula: A01198752
- Carrera: IDM
- Fecha: 5/22/2024
- ¿Qué aprendí en el desarrollo de esta clase? 
Aprendi a usar apuntadores en un contexto de polimorfismo, como cuando llamo una funcion de pelicula o serie y utilizo un apuntador para llamar 
a su str especifica. Tambien creando el array con apuntador de arrPtrVideos. Aprendí a utilizar apuntadores especificos
como cuando utilice un apuntador para encontrar el typeid de un objeto para asi saber como categorizarlo. 
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h
#include <typeinfo>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include "Episodio.h"
#include <stdio.h>

class Polimorfismo{
    private:
        static const int MAX_VIDEOS = 100;
        Video *arrPtrVideos[MAX_VIDEOS];
        int cantidadVideos;
    public:
        Polimorfismo();
        void setPtrVideo(int index, Video* video);
        void setCantidad(int _cantidad);
        int getCantidad();
        Video* getPtrVideo(int index);
        void leerArchivo(std::string nombreArchivo);
        void reporteInventario();
        void reporteCalificacion(double _calificacion);
        void reporteGenero(std::string _genero);
        void reportePeliculas();
        void reporteSeries();


};

#endif
