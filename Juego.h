#pragma once
#include <string>
#include "Software.h"
#include "TiposSoftware.h"
#include <iostream> 

class Juego : public Software {
public:
    Juego(std::string nombre, std::string developer, int clasificacionEdad, float precio, std::string genero);

    // Métodos específicos para juegos
    std::string getGenero() const;
    void setGenero(std::string genero);

    // Otros atributos específicos para juegos
    std::string getHistorialPartidas() const;
    void registrarPartida(std::string resultado);

    // Funciones virtuales que se pueden anular en subclases si es necesario
    virtual void jugar();

    virtual void mostrarDetalles() const;
    virtual void mostrarInformacion() const;


private:
    std::string genero;
    std::string historialPartidas; // Un registro de resultados de partidas
};
