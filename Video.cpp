//  Video.cpp
//
//  Created by Santiago Rodriguez A01198752
//

#include "Video.h"

Video::Video(){
    ID = "0000";
}

/**
 * Construye un objeto Video con los parámetros dados.
 *
 * @param _ID el ID del video
 * @param _titulo el título del video
 * @param _duracion la duración del video en minutos
 * @param _genero el género del video
 * @param _calificacion la calificación del video
 */
Video::Video(std::string _ID,
    std::string _titulo,
    int _duracion,
    std::string _genero,
    double _calificacion){
    ID = _ID;
    titulo = _titulo;
    duracion = _duracion;
    genero = _genero;
    calificacion = _calificacion;
}

/**
 * Establece el ID del video.
 *
 * @param _ID el nuevo ID del video
 */
void Video::setID(std::string _ID){
    ID = _ID;
}

/**
 * Establece el título del video.
 *
 * @param _titulo el nuevo título del video
 */
void Video::setTitulo(std::string _titulo){
    titulo = _titulo;
}

/**
 * Establece la duración del video en minutos.
 *
 * @param _duracion la nueva duración del video en minutos
 */
void Video::setDuracion(int _duracion){
    duracion = _duracion;
}

/**
 * Establece el género del video.
 *
 * @param _genero el nuevo genre del video
 */
void Video::setGenero(std::string _genero){
    genero = _genero;
}

/**
 * Establece la calificación del video.
 *
 * @param _calificacion la nueva calificación del video
 */
void Video::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

/**
 * Obtiene el ID del video.
 *
 * @return el ID del video
 */
std::string Video::getID(){
    return ID;
}

/**
 * Obtiene el título del video.
 *
 * @return el título del video
 */
std::string Video::getTitulo(){
    return titulo;
}

/**
 * Obtiene la duración del video
 *
 * @return la duración del video
 */
int Video::getDuracion(){
    return duracion;
}

/**
 * Obtiene el genero del video.
 *
 * @return el genero del video
 */
std::string Video::getGenero(){
    return genero;
}

/**
 * Obtiene la calificación del video.
 *
 * @return la calificación del video
 */
double Video::getCalificacion(){
    return calificacion;
}

/**
 * Genera una representación en formato de cadena de caracteres del video.
 * La representación está en el formato: "ID titulo duracion genero calificacion".
 *
 * @return la representación en formato de cadena de caracteres del video
 */
std::string Video::str(){
    return ID + " " + titulo + " " + std::to_string(duracion) + " " + genero + " " + std::to_string(calificacion);
}

/**
 * Genera una representación en formato de cadena de caracteres del video.
 * La representación está en el formato: "ID_titulo_duracion_genero_calificacion".
 *
 * @param out el flujo de salida
 * @param _video el video a representar
 * @return el flujo de salida actualizado
 */
std::ostream &operator<<(std::ostream &out, const Video &_video){
    out << std::fixed << _video.ID << "_" << _video.titulo << "_" << _video.duracion << "_" << _video.genero << "_" << _video.calificacion;
    return out;
}
