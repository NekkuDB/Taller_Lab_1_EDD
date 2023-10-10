#pragma once
#include <string>
#include "TiposSoftware.h"

class Software {
public:
    // Constructor predeterminado
    Software() : nombre(""), developer(""), clasificacionEdad(0), precio(0.0), tipo(TipoSoftware::Social) {}

    // Constructor personalizado
    Software(std::string nombre, std::string developer, int clasificacionEdad, float precio);

    // Métodos para acceder y modificar atributos
    std::string getNombre() const;
    std::string getDeveloper() const;
    int getClasificacionEdad() const;
    float getPrecio() const;

    void setNombre(std::string nombre);
    void setDeveloper(std::string developer);
    void setClasificacionEdad(int clasificacionEdad);
    void setPrecio(float precio);

    TipoSoftware getTipo() const {
        return tipo;
    }
    
    virtual ~Software() {}
protected:
    TipoSoftware tipo;

private:
    std::string nombre;
    std::string developer;
    int clasificacionEdad;
    float precio;
};

// Implementa el constructor personalizado de la clase Software
Software::Software(std::string nombre, std::string developer, int clasificacionEdad, float precio) {
    this->nombre = nombre;
    this->developer = developer;
    this->clasificacionEdad = clasificacionEdad;
    this->precio = precio;
}

// Implementa los métodos de acceso y modificación
std::string Software::getNombre() const {
    return nombre;
}

std::string Software::getDeveloper() const {
    return developer;
}

int Software::getClasificacionEdad() const {
    return clasificacionEdad;
}

float Software::getPrecio() const {
    return precio;
}

void Software::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Software::setDeveloper(std::string developer) {
    this->developer = developer;
}

void Software::setClasificacionEdad(int clasificacionEdad) {
    this->clasificacionEdad = clasificacionEdad;
}

void Software::setPrecio(float precio) {
    this->precio = precio;
}
