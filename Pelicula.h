/*
- Nombre: Santiago Rodriguez 
- Matricula: A01198752
- Carrera: IDM
- Fecha: 5/22/2024
- ¿Qué aprendí en el desarrollo de esta clase? 
Aprendi a como crear una nueva clase trayendo los atributos de otra, en este caso, creando la clase pelicula con los 
atributos de video e importando sus metodos. También como utilizar sobrecarga
de operadores como fue con el caso de <<.
*/


#include <string>
#include "Video.h"

#ifndef PELICULA_H
#define PELICULA_H

class Pelicula: public Video{
    private:
        int oscares;
    public:
    Pelicula();
    Pelicula(std::string _id, std::string _titulo,
    int _duracion, std::string _genero,
    double _calificacion, int _oscares);

    void setOscares(int value);

    int getOscares();

    std::string str();

    friend std::ostream& operator<< (std::ostream &out, const Pelicula &_pelicula);
};

#endif //PELICULA.H