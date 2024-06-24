/*
- Nombre: Santiago Rodriguez 
- Matricula: A01198752
- Carrera: IDM
- Fecha: 5/22/2024
- ¿Qué aprendí en el desarrollo de esta clase? 
Aprendi a como generar arreglos con clases y objetos creados por un usuario. Como es el arreglo de episodios.
*/

#include "Episodio.h"
#include "Video.h"

#ifndef SERIE_H
#define SERIE_H

class Serie: public Video{
    private:
        Episodio episodios[5];
        int cantidad;
    public:
        Serie();
        Serie(std::string _id, std::string _titulo,
        int _duracion, std::string _genero,
        double _calificacion);

        void calculaDuracion();
        void setEpisodio(int index, Episodio epi);
        void setCantidad(int _cantidad);

        Episodio getEpisodio(int index);

        int getCantidad();

        double calculaPromedio();

        std::string str();

        void agregaEpisodio(Episodio epi);

};

#endif //SERIE.H