//  Pelicula.cpp
//
//  Created by Santiago Rodriguez A01198752
//

#include "Pelicula.h"

/**
 * Constructor por defecto de la clase Pelicula.
 * Inicializa el numero de oscar con el valor 100.
 */
Pelicula::Pelicula():Video() {
    oscares = 100;
}

/**
 * Constructor de la clase Pelicula.
 * Inicializa los atributos de la clase con los valores pasados como argumentos.
 * @param _id el identificador de la pelicula.
 * @param _titulo el titulo de la pelicula.
 * @param _duracion la duracion de la pelicula.
 * @param _genero el genero de la pelicula.
 * @param _calificacion la calificacion de la pelicula.
 * @param _oscares el numero de oscar de la pelicula.
 */
Pelicula::Pelicula(std::string _id, std::string _titulo, 
int _duracion, std::string _genero,
double _calificacion, int _oscares) : Video(_id, _titulo, _duracion, _genero, _calificacion) {
    oscares = _oscares;
}

/**
 * Setter del numero de oscar de la pelicula.
 * @param value el nuevo valor del numero de oscar.
 */
void Pelicula::setOscares(int value) {
    oscares = value;
}

/**
 * Getter del numero de oscar de la pelicula.
 * @return el numero de oscar de la pelicula.
 */
int Pelicula::getOscares() {
    return oscares;
}

/**
 * Retorna una cadena con los atributos de la pelicula.
 * @return una cadena con los atributos de la pelicula.
 */
std::string Pelicula::str() {
    return ID + " " + titulo + " " + std::to_string(duracion) + " " 
    + genero + " " + std::to_string(calificacion) + " " + std::to_string(oscares);
}

/**
 * Sobrecarga del operador << para imprimir la informacion de una pelicula.
 * @param out el flujo de salida donde se imprimira la informacion.
 * @param _pelicula la pelicula a imprimir.
 * @return el flujo de salida actualizado.
 */
std::ostream& operator<<(std::ostream &out, const Pelicula &_pelicula) {
    out << std::fixed << _pelicula.ID << "_" << _pelicula.titulo << "_" << _pelicula.duracion << "_" << _pelicula.genero << "_" << _pelicula.calificacion << "_" << _pelicula.oscares;
    return out;
}
