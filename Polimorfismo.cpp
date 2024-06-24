//  Polimorfismo.cpp
//
//  Created by Santiago Rodriguez A01198752
//

#include "Polimorfismo.h"

/**
 * Constructor de la clase Polimorfismo
 *
 * @return void
 */

Polimorfismo::Polimorfismo(){
    for (int index = 0; index < MAX_VIDEOS; index ++){
        arrPtrVideos[index] = nullptr;
    }

    cantidadVideos = 0;
}

/**
 * Asigna un puntero a un video dado su indice.
 *
 * @param index el indice del video
 * @param video puntero a un video
 *
 * @return void
 */

void Polimorfismo::setPtrVideo(int index, Video* video){
    if (index >= 0 && index <= MAX_VIDEOS){
        arrPtrVideos[index] = video;
    }
}

/**
 * Asigna la cantidad de videos guardados en el arreglo de apuntadores.
 *
 * @param _cantidad la cantidad de videos
 *
 * @return void
 */

void Polimorfismo::setCantidad(int _cantidad){
    if (_cantidad >= 0 &&  _cantidad <= MAX_VIDEOS){
        cantidadVideos = _cantidad;
    }
}

/**
 * Retorna la cantidad de videos guardados en el arreglo de apuntadores.
 *
 * @return la cantidad de videos
 */

int Polimorfismo::getCantidad(){
    return cantidadVideos;
}

/**
 * Retorna un puntero a un video dado su indice.
 *
 * @param index el indice del video
 *
 * @return puntero a un video
 */

Video* Polimorfismo::getPtrVideo(int index){
    Video* vid;
    if (index >= 0 &&  index <= cantidadVideos){
        return arrPtrVideos[index];
    }
    return vid;
}

/**
 * Reporta la cantidad total de videos y muestra los detalles de cada video.
 *
 * @return void
 */

void Polimorfismo::reporteInventario(){
    int cantidadSeries = 0;
    int cantidadPeliculas = 0;
    int counter = 0;
    while (counter < cantidadVideos){
        std::cout << arrPtrVideos[counter]->str() << std::endl;
        if (typeid(*arrPtrVideos[counter]) ==  typeid(Serie)){ //Typeid funciona mejor que hacerlo string
            cantidadSeries++;
        } else { //No es necesario ponerle otro else if
            cantidadPeliculas++;
        }
        counter++;
    }
    std::cout << "Peliculas = " << cantidadPeliculas << std::endl;
    std::cout << "Series = " << cantidadSeries << std::endl;
}

/**
 * Reporta la cantidad total de videos con una calificación dada y muestra los detalles de cada video.
 *
 * @param _calificacion la calificación a buscar
 *
 * @return void
 */

void Polimorfismo::reporteCalificacion(double _calificacion){
    int cantidadCalificacion = 0;
    int counter = 0;
    while (counter < cantidadVideos){
        if (arrPtrVideos[counter]->getCalificacion() == _calificacion){
            std::cout << arrPtrVideos[counter]->str() << std::endl;
            cantidadCalificacion++;
        }
        counter++;
    }
    std::cout << "Total = " << cantidadCalificacion << std::endl;
}

/**
 * Reporta la cantidad total de videos con un genero dada y muestra los detalles de cada video.
 *
 * @param _genero el genero a buscar
 *
 * @return void
 */

void Polimorfismo::reporteGenero(std::string _genero){
    int cantidadGenero = 0;
    int counter = 0;
    while (counter < cantidadVideos){
        if (arrPtrVideos[counter]->getGenero() == _genero){
            std::cout << arrPtrVideos[counter]->str() << std::endl;
            cantidadGenero++;
        }
        counter++;
    }
    std::cout << "Total = " << cantidadGenero << std::endl;
}

/**
 * Reporta la cantidad total de peliculas y muestra los detalles de cada pelicula.
 *
 * @return void
 */

void Polimorfismo::reportePeliculas(){
    int cantidadPeliculas = 0;
    int counter = 0;
    while (counter < cantidadVideos){
        if (typeid(*arrPtrVideos[counter]) ==  typeid(Pelicula)){
            std::cout << arrPtrVideos[counter]->str() << std::endl;
            cantidadPeliculas++;
        }
        counter++;
    }
    if (cantidadPeliculas == 0){
        std::cout << "No peliculas" << std::endl;
    }else{
        std::cout << "Total Peliculas = " << cantidadPeliculas << std::endl;
    }
}

/**
 * Reporta la cantidad total de series y muestra los detalles de cada serie.
 *
 * @return void
 */

void Polimorfismo::reporteSeries(){
    int cantidadSeries = 0;
    int counter = 0;
    while (counter < cantidadVideos){
        if (typeid(*arrPtrVideos[counter]) == typeid(Serie)){
            std::cout << arrPtrVideos[counter]->str() << std::endl;
            cantidadSeries++;
        }
        counter++;
    }
    if (cantidadSeries == 0){
        std::cout << "No series" << std::endl;
    }else{
        std::cout << "Total Series = " << cantidadSeries << std::endl;
    }
}

/**
 * Lee un archivo CSV y lo almacena en un arreglo de apuntadores.
 *
 * @param nombreArchivo el nombre del archivo CSV
 *
 * @return void
 */

void Polimorfismo::leerArchivo(std::string nombreArchivo){
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    std::fstream entrada;
    std::string row[7];
    std::string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombreArchivo, std::ios::in);

    while (getline(entrada, line)){
        std::stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')){
            row[iR++] = word;
        }


        if(row[0] == "P"){
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            cantidadPeliculas++;
        } else if(row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            cantidadSeries++;
        } else {
            index = stoi(row[1]) - 500;
            arrPtrSeries[index]-> agregaEpisodio(*(new Episodio(row[2], stoi(row[3]), stoi(row[4]))));
        }
        
    }

    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->calculaDuracion();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrVideos[cantidadVideos++] = arrPtrSeries[index];
    }

    for(int index = 0; index < cantidadPeliculas; index++){
        arrPtrVideos[cantidadVideos++] = arrPtrPeliculas[index];
    }

    entrada.close();

}

