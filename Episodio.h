/*
- Nombre: Santiago Rodriguez 
- Matricula: A01198752
- Carrera: IDM
- Fecha: 5/22/2024
- ¿Qué aprendí en el desarrollo de esta clase? 
Aprendi a como desarrollar los setters, getters, constructores basicos y que cada uno tenga sus propias variables.
También como utilizar sobrecarga de operadores como fue con el caso de <<.
*/

#include <string>
#include <iostream>

#ifndef EPISODIO_H
#define EPISODIO_H

class Episodio{
private:
    std::string titulo;
    int temporada;
    int calificacion;
public:
    Episodio();
    Episodio(std::string _titulo, int _temporada, int _calificacion);

    void setTitulo(std::string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

    std::string getTitulo();
    int getTemporada();
    int getCalificacion();

    std::string str();
    friend std::ostream &operator<<(std::ostream &out, const Episodio &_episodio);
};

#endif //EPISODIO.H