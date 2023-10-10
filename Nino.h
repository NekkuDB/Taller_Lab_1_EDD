#pragma once
#include <string>
#include "Usuario.h"

class Nino : public Usuario {
public:
    Nino(std::string usuario, std::string contrasena, int edad, std::string correo);
    
    // Métodos específicos para niños
    void agregarAmigo(Nino* amigo);
    void eliminarAmigo(Nino* amigo);
    void mostrarAmigos() const;
    
    // Atributos específicos para niños
    int obtenerCantidadAmigos() const; // Por ejemplo, un contador de amigos
    
private:
    std::vector<Nino*> amigos; // Vector para almacenar a los amigos del niño
    int cantidadAmigos; // Atributo para llevar un registro de la cantidad de amigos
};

// Implementación del constructor
Nino::Nino(std::string usuario, std::string contrasena, int edad, std::string correo)
    : Usuario(usuario, contrasena, edad, correo) {
    // Constructor de Nino, se inicializa llamando al constructor de Usuario
    cantidadAmigos = 0; // Inicializa la cantidad de amigos en 0
}

// Implementación de los métodos específicos para niños
void Nino::agregarAmigo(Nino* amigo) {
    amigos.push_back(amigo);
    cantidadAmigos++;
}

void Nino::eliminarAmigo(Nino* amigo) {
    // Encuentra y elimina al amigo de la lista de amigos
    for (auto it = amigos.begin(); it != amigos.end(); ++it) {
        if (*it == amigo) {
            amigos.erase(it);
            cantidadAmigos--;
            return;
        }
    }
}

void Nino::mostrarAmigos() const {
    std::cout << "Lista de amigos de " << getUsuario() << ":" << std::endl;
    for (const Nino* amigo : amigos) {
        std::cout << amigo->getUsuario() << std::endl;
    }
}

int Nino::obtenerCantidadAmigos() const {
    return cantidadAmigos;
}
