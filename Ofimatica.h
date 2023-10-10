#pragma once
#include <string>
#include "Software.h"

class Ofimatica : public Software {
public:
    Ofimatica(std::string nombre, std::string developer, int clasificacionEdad, float precio, int cantidadArchivos);
    
    // Métodos específicos para software de ofimática
    int getCantidadArchivos() const;
    void setCantidadArchivos(int cantidadArchivos);
    
    // Otros atributos específicos para ofimática
    std::string getFuncionalidades() const;
    void agregarFuncionalidad(std::string funcionalidad);
    
    // Métodos para crear y borrar archivos
    void crearArchivo();
    void borrarArchivo();
    
private:
    int cantidadArchivos;
    std::string funcionalidades; // Un registro de funcionalidades adicionales del software
};


void Ofimatica::crearArchivo() {
    cantidadArchivos++;
}

// Borrar un archivo (disminuir la cantidad de archivos, mínimo 0)
void Ofimatica::borrarArchivo() {
    if (cantidadArchivos > 0) {
        cantidadArchivos--;
    }
};