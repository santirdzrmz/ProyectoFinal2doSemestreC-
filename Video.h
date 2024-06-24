/*
- Nombre: Santiago Rodriguez 
- Matricula: A01198752
- Carrera: IDM
- Fecha: 5/22/2024
- ¿Qué aprendí en el desarrollo de esta clase? 
Aprendi a como crear clases y objetos con más atributos, setters y getters. También como utilizar sobrecarga
de operadores como fue con el caso de <<.
*/

#include <string>
#ifndef VIDEO_H
#define VIDEO_H
#include <iostream>

class Video{
protected:
    std::string ID;
    std::string titulo;
    int duracion;
    std::string genero;
    double calificacion;
public:
    Video();
    Video(std::string _ID,
    std::string _titulo,
    int _duracion,
    std::string _genero,
    double _calificacion);

    void setID(std::string _ID);
    void setTitulo(std::string _titulo);
    void setDuracion(int _duracion);
    void setGenero(std::string _genero);
    void setCalificacion(double _calificacion);

    std::string getID();
    std::string getTitulo();
    int getDuracion();
    std::string getGenero();
    double getCalificacion();

    virtual std::string str();

    friend std::ostream& operator<<(std::ostream &out, const Video &_video);


};

#endif // VIDEO.H