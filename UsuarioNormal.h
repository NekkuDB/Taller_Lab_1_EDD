#pragma once
#include <string>
#include "Usuario.h"

class UsuarioNormal : public Usuario {
public:
    UsuarioNormal(std::string usuario, std::string contrasena, int edad, std::string correo);
    
    // Métodos específicos para usuarios normales
    int getEdad() const;
    void setEdad(int edad);
    std::string getCorreo() const;
    void setCorreo(std::string correo);
    
    
    
private:

};
