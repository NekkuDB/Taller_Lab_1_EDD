#pragma once
#include "TiposSoftware.h"
#include <string>
#include <vector>
#include <iostream> // Para std::cout y std::cin
#include "Software.h"

class Social : public Software {
public:
    Social(std::string nombre, std::string developer, int clasificacionEdad, float precio, int cantidadAmigos);

    int getCantidadAmigos() const;
    void agregarAmigo(std::string amigo);
    std::string getEstado() const;
    void setEstado(std::string estado);

    void publicarEstado() {
        std::cout << "Publicando estado..." << std::endl;

    }

    void enviarMensaje() {
        std::cout << "Enviando mensaje..." << std::endl;

    }

    void agregarAmigo(std::string amigo, int edadAmigo);


    void eliminarAmigo(const std::string& amigo);

    void inicializarAmigos(const std::vector<std::string>& amigosIniciales);
    void agregarAmigo();
    std::vector<std::string> obtenerListaAmigos() const;
private:
    int cantidadAmigos_;
    std::string tipoUsuario_;
    std::vector<std::string> amigos_;
    std::string estado_;
    int getClasificacionEdad() const {
        return clasificacionEdad_;
    }
    int clasificacionEdad_;
    
};