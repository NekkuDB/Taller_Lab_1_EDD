// Produccion.h
#pragma once
#include <string>
#include "Software.h"

class Produccion : public Software {
public:
    Produccion(std::string nombre, std::string developer, int clasificacionEdad, float precio, std::string tipoSolucion);
    
    // Métodos específicos para software de producción
    std::string getTipoSolucion() const;
    void setTipoSolucion(std::string tipoSolucion);
    
    // Otros atributos específicos para producción
    int getCantidadRecursos() const;
    void asignarRecurso(std::string recurso);
    
    void crearProyecto() {

    }

    void editarProyecto() {

    }

    void exportarProyecto() {

    }

    void mostrarInformacionProyecto() {

    }

private:
    std::string tipoSolucion;
    std::vector<std::string> recursosAsignados; // Un registro de recursos asignados al software
};
