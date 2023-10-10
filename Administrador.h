#pragma once
#include <string>
#include <vector>
#include "Usuario.h"

class Administrador : public Usuario {
public:
    Administrador(std::string usuario, std::string contrasena, int edad, std::string correo);
    
    // Métodos específicos para administradores
    void agregarUsuario(Usuario* nuevoUsuario);
    void eliminarUsuario(Usuario* usuarioAEliminar);
    void listarUsuarios() const; // Método para listar los usuarios en la base de datos
    
private:
    // Vector para almacenar usuarios en la base de datos
    std::vector<Usuario*> baseDeDatosUsuarios;
};

// Administrador.cpp
#include "Administrador.h"
#include <iostream>

Administrador::Administrador(std::string usuario, std::string contrasena, int edad, std::string correo)
    : Usuario(usuario, contrasena, edad, correo) {
    // Constructor de Administrador, se inicializa llamando al constructor de Usuario
}

void Administrador::agregarUsuario(Usuario* nuevoUsuario) {
    baseDeDatosUsuarios.push_back(nuevoUsuario);
    std::cout << "Usuario agregado por el administrador." << std::endl;
}

void Administrador::eliminarUsuario(Usuario* usuarioAEliminar) {
    // Encuentra y elimina al usuario de la base de datos
    for (auto it = baseDeDatosUsuarios.begin(); it != baseDeDatosUsuarios.end(); ++it) {
        if (*it == usuarioAEliminar) {
            delete *it; // Libera la memoria del usuario eliminado
            baseDeDatosUsuarios.erase(it);
            std::cout << "Usuario eliminado por el administrador." << std::endl;
            return;
        }
    }
    std::cout << "Usuario no encontrado en la base de datos." << std::endl;
}

void Administrador::listarUsuarios() const {
    std::cout << "Usuarios en la base de datos:" << std::endl;
    for (const Usuario* usuario : baseDeDatosUsuarios) {
        std::cout << "Usuario: " << usuario->getUsuario() << ", Edad: " << usuario->getEdad() << std::endl;
    }
}
