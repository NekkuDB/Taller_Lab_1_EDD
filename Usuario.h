#pragma once
#include <string>

class Usuario {
public:
    Usuario(std::string usuario, std::string contrasena, int edad, std::string correo);
    
    // Métodos para acceder y modificar atributos
    std::string getUsuario() const;
    std::string getContrasena() const;
    int getEdad() const;
    std::string getCorreo() const;
    
    void setUsuario(std::string usuario);
    void setContrasena(std::string contrasena);
    void setEdad(int edad);
    void setCorreo(std::string correo);
    
    
private:
    std::string usuario;
    std::string contrasena;
    int edad;
    std::string correo;
};

// Implementación del constructor
Usuario::Usuario(std::string usuario, std::string contrasena, int edad, std::string correo) {
    this->usuario = usuario;
    this->contrasena = contrasena;
    this->edad = edad;
    this->correo = correo;
}

// Implementación de los métodos de acceso y modificación
std::string Usuario::getUsuario() const {
    return usuario;
}

std::string Usuario::getContrasena() const {
    return contrasena;
}

int Usuario::getEdad() const {
    return edad;
}

std::string Usuario::getCorreo() const {
    return correo;
}

void Usuario::setUsuario(std::string usuario) {
    this->usuario = usuario;
}

void Usuario::setContrasena(std::string contrasena) {
    this->contrasena = contrasena;
}

void Usuario::setEdad(int edad) {
    this->edad = edad;
}

void Usuario::setCorreo(std::string correo) {
    this->correo = correo;
}
