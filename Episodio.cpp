//  Episodio.cpp
//
//  Created by Santiago Rodriguez A01198752
//


#include "Episodio.h"

/**
 * Constructor por defecto de la clase Episodio.
 */
Episodio::Episodio(){}

/**
 * Constructor para la clase Episodio.
 *
 * Inicializa el título, la temporada y la calificación del episodio.
 *
 * @param _titulo El título del episodio.
 * @param _temporada El número de temporada del episodio.
 * @param _calificacion La calificación del episodio.
 */
Episodio::Episodio(std::string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

/**
* Establece el título del Episodio.
* @param _titulo El nuevo título para el Episodio.
*/
void Episodio::setTitulo(std::string _titulo){
    titulo = _titulo;
}

/**
* Establece la temporada del episodio.
*
* @param _temporada La nueva temporada para el episodio.
*/
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}

/**
* Establece la calificación del episodio.
*
* @param _calificacion La nueva calificación para el episodio.
*/
void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

/**
* Obtiene el título del episodio.
*
* @return El título del episodio.
*/
std::string Episodio::getTitulo(){
    return titulo;
}

/**
* Obtiene la temporada del episodio.
*
* @return La temporada del episodio.
*/
int Episodio::getTemporada(){
    return temporada;
}

/**
* Obtiene la calificación del episodio.
*
* @return La calificación del episodio.
*/
int Episodio::getCalificacion(){
    return calificacion;
}

/**
* Devuelve una representación de cadena del episodio.
*
* @return Una cadena que contiene el título, la temporada y la calificación del episodio, separados por espacios.
*/
std::string Episodio::str(){
    return titulo + " " + std::to_string(temporada) + " " + std::to_string(calificacion);
}

/**
 * Sobrecarga del operador << para la clase Episodio.
 *
 * Esta función sobrecarga el operador << para que pueda imprimir un objeto de la clase Episodio.
 * Toma como parámetros un flujo de salida y un objeto constante de tipo Episodio.
 * Devuelve el flujo de salida modificado.
 *
 * @param out Flujo de salida donde se imprimirá el objeto.
 * @param _episodio Objeto de tipo Episodio que se va a imprimir.
 * @return El flujo de salida modificado que contiene la representación en cadena del objeto.
 */
std::ostream &operator<<(std::ostream &out, const Episodio &_episodio){
    out << std::fixed << _episodio.titulo << "_" << _episodio.temporada << "_" << _episodio.calificacion;
    return out;
}
