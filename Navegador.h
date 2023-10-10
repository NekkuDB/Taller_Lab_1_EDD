// Navegador.h
#pragma once
#include <string>
#include <vector>
#include "Software.h"

class Navegador : public Software {
public:
    Navegador(std::string nombre, std::string developer, int clasificacionEdad, float precio);
    
    // Métodos específicos para software de navegación
    const std::vector<std::string>& getHistorialNavegacion() const;
    void agregarPaginaHistorial(std::string pagina);
    
    // Otros métodos y atributos específicos para navegadores si es necesario
    
private:
    std::vector<std::string> historialNavegacion; // Historial de navegación del usuario
};
