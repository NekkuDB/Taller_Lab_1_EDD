#pragma once
#include <string>
#include <vector>
#include "Software.h"

enum class TipoMalware {
    Ransomware,
    Spyware,
    Botnets,
    Rootkits,
    Gusanos,
    Troyanos
};

class Seguridad : public Software {
public:
    Seguridad(std::string nombre, std::string developer, int clasificacionEdad, float precio, TipoMalware tipoMalware);
    
    // Métodos específicos para software de seguridad
    TipoMalware getTipoMalware() const;
    void setTipoMalware(TipoMalware tipoMalware);
    
    // Atributos y métodos adicionales específicos para seguridad
    std::string getRegistroAcceso() const;
    void agregarRegistroAcceso(std::string registro);
    
    void realizarEscaneo() {

    }

    void actualizarBaseDatos() {

    }

    void mostrarHistorialEscaneos() {

    }

    void configurarOpciones() {

    }
private:
    TipoMalware tipoMalware;
    std::vector<std::string> registrosAcceso; // Registro de accesos al software de seguridad
};
