// Serie.cpp
//
// Created by Santiago Rodriguez A01198752
//


#include "Serie.h"

/**
 * Default constructor for the Serie class.
 * Initializes the count field with the value 0.
 */
Serie::Serie():Video() {
    cantidad = 0;
}

/**
 * Parameterized constructor for the Serie class.
 * Assigns the attributes of the parent Video class.
 * @param _id ID of the serie
 * @param _titulo title of the serie
 * @param _duracion duration of the serie
 * @param _genero genre of the serie
 * @param _calificacion rating of the serie
 */
Serie::Serie(std::string _id, std::string _titulo, int _duracion, std::string _genero,
              double _calificacion):Video(_id, _titulo, _duracion, _genero, _calificacion) {}

/**
 * Calculates the total duration of the series episodes.
 */
void Serie::calculaDuracion() {
    int duracionTotal = 0;
    for (int index = 0; index < cantidad; index++){
        duracionTotal+=episodios[index].getTemporada();
    }
    duracion = duracionTotal;
}

/**
 * Sets an episode at the specified position.
 * @param index position of the episode
 * @param epi episode to set
 */
void Serie::setEpisodio(int index, Episodio epi) {
    if (index < cantidad && index >= 0){
        episodios[index] = epi;
    }
}

/**
 * Sets the count of episodes in the series.
 * @param _cantidad count of episodes
 */
void Serie::setCantidad(int _cantidad) {
    if (_cantidad >= 0 && _cantidad <= 5){
        cantidad = _cantidad;
    }
}

/**
 * Returns the episode at the specified position.
 * @param index position of the episode
 * @return episode at the specified position
 */
Episodio Serie::getEpisodio(int index) {
    Episodio epi;
    if (index >= 0 && index <= cantidad){
        return episodios[index];
    }
    return epi;
}

/**
 * Returns the count of episodes in the series.
 * @return count of episodes
 */
int Serie::getCantidad() {
    return cantidad;
}

/**
 * Calculates the average rating of the series episodes.
 * @return average rating
 */
double Serie::calculaPromedio() {
    int index = 0;
    double sum = 0; 
    while (index < cantidad){
        sum += episodios[index].getCalificacion();
        index++;
    }
    double promedio = 0;
    if (cantidad > 0){
        promedio = sum / cantidad; 
    }

    return promedio;
}

/**
 * Returns a string representation of the series and its episodes.
 * @return string representation of the series and its episodes
 */
std::string Serie::str() {
    std::string resultado;
    resultado = ID + " " + titulo + " " + std::to_string(duracion) + " " + genero + " " + std::to_string(calificacion) + " " + std::to_string(cantidad)+ "\n";
    int index = 0;
    while(index < cantidad){
        resultado += episodios[index].str() + "\n";
        index++;
    }
    return resultado;
}

/**
 * Adds an episode to the series.
 * @param epi episode to add
 */
void Serie::agregaEpisodio(Episodio epi) {
    if (cantidad < 5){
        episodios[cantidad++] = epi;
    }
}

