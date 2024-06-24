
//  main.cpp
//  Avance3
//
//  Created by Ma. Guadalupe Roque Díaz de León on 05/06/24.
//
// Clases Base - Video - con método virtual str() para Poliformismo
// Clases Derivadas - Pelicula, Serie
// Clase usada para composición - Episodio
// Arreglo de apuntadores


/*
Nombre: Santiago Rodriguez
Matricula: A01198752
Carrera: IDM
Fecha: 6/13/2024
- ¿Qué aprendí en el desarrollo de cada clase?

En la clase Pelicula y Serie aprendí temas importantes de herencia y como utilizar apuntadores con la
sobrecarga del operador <<. Aprendi como crear un arreglo de apuntadores en la clase Polimorfismo al igual
que el uso de apuntadores especificos para llamar funciones como la de str(). En la clase de Episodio aprendi
a como funciona la composicion, ya que utilice esa clase para despues utilizarla como un arreglo de ella misma en Serie. 
*/

#include <iostream>
#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Polimorfismo.h"

using namespace std;


int main() {
    // Declaracion de objetos
    Video viernes("100", "Computer", 100, "Ing.", 100);
    Episodio episodio("ExitoDTB", 100, 100);
    Pelicula pelicula("007", "Xochitl", 2024, "PANPRI", 100, 100);
    Polimorfismo super;
    

    // Pruebas de la sobrecarga del operador <<
    cout << viernes << endl;  // sobrecarga del operador <<
    cout << viernes.str() << endl;
    cout << pelicula << endl; // sobrecarga del operador <<
    cout << pelicula.str() << endl;
    cout << episodio << endl; // sobrecarga del operador <<
    cout << episodio.str() << endl;

    super.leerArchivo("InventarioFinal.csv");

    for(int index = 0; index < super.getCantidad(); index++){
        cout << super.getPtrVideo(index)->str() << endl;
        cout << *super.getPtrVideo(index) << endl;
    }
    return 0;
}
