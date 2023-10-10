#include <iostream>
#include <vector>
#include <string>
#include "Usuario.h"
#include "Administrador.h"
#include "Nino.h"
#include "UsuarioNormal.h"
#include "Software.h"
#include "Juego.h"
#include "Ofimatica.h"
#include "Produccion.h"
#include "Navegador.h"
#include "Seguridad.h"
#include "Social.h"
#include "TiposSoftware.h"
#include <algorithm>
#include <limits>

// UsuarioNormal.cpp
UsuarioNormal::UsuarioNormal(std::string usuario, std::string contrasena, int edad, std::string correo)
    : Usuario(usuario, contrasena, edad, correo) {
    // No es necesario inicializar edad y correo aquí
}

// Método para obtener la edad de UsuarioNormal
int UsuarioNormal::getEdad() const {
    return Usuario::getEdad(); // Acceder al getter de la clase base
}

// Método para establecer la edad de UsuarioNormal
void UsuarioNormal::setEdad(int edad) {
    Usuario::setEdad(edad); // Acceder al setter de la clase base
}

// Método para obtener el correo de UsuarioNormal
std::string UsuarioNormal::getCorreo() const {
    return Usuario::getCorreo(); // Acceder al getter de la clase base
}

// Método para establecer el correo de UsuarioNormal
void UsuarioNormal::setCorreo(std::string correo) {
    Usuario::setCorreo(correo); // Acceder al setter de la clase base
}

// Constructor de Juego
Juego::Juego(std::string nombre, std::string developer, int clasificacionEdad, float precio, std::string genero)
    : Software(nombre, developer, clasificacionEdad, precio), genero(genero), historialPartidas("") {

}


std::string Juego::getGenero() const {
    return genero;
}


void Juego::setGenero(std::string genero) {
    this->genero = genero;
}


std::string Juego::getHistorialPartidas() const {
    return historialPartidas;
}


void Juego::registrarPartida(std::string resultado) {
    if (!historialPartidas.empty()) {
        historialPartidas += ", ";
    }
    historialPartidas += resultado;
}

void Juego::jugar() {
    std::cout << "Estás jugando el juego: " << getNombre() << std::endl;
}

void Juego::mostrarDetalles() const {
    std::cout << "Nombre: " << getNombre() << "\n";
    std::cout << "Desarrollador: " << getDeveloper() << "\n";
    std::cout << "Clasificación de Edad: " << getClasificacionEdad() << "\n";
    std::cout << "Precio: $" << getPrecio() << "\n";
    std::cout << "Género: " << genero << "\n";
    std::cout << "Historial de Partidas: " << historialPartidas << "\n";
}

void Juego::mostrarInformacion() const {
    mostrarDetalles();
}

// Constructor de Ofimatica
Ofimatica::Ofimatica(std::string nombre, std::string developer, int clasificacionEdad, float precio, int cantidadArchivos)
    : Software(nombre, developer, clasificacionEdad, precio), cantidadArchivos(cantidadArchivos) {
    funcionalidades = "";
}

// Método para obtener la cantidad de archivos del software de ofimática
int Ofimatica::getCantidadArchivos() const {
    return cantidadArchivos;
}

// Método para establecer la cantidad de archivos del software de ofimática
void Ofimatica::setCantidadArchivos(int cantidadArchivos) {
    this->cantidadArchivos = cantidadArchivos;
}

// Método para obtener las funcionalidades adicionales del software de ofimática
std::string Ofimatica::getFuncionalidades() const {
    return funcionalidades;
}

// Método para agregar una funcionalidad al software de ofimática
void Ofimatica::agregarFuncionalidad(std::string funcionalidad) {
    if (!funcionalidades.empty()) {
        // Si ya hay funcionalidades anteriores, agrega una línea nueva
        funcionalidades += "\n";
    }
    funcionalidades += funcionalidad;
}

// Constructor de Produccion
Produccion::Produccion(std::string nombre, std::string developer, int clasificacionEdad, float precio, std::string tipoSolucion)
    : Software(nombre, developer, clasificacionEdad, precio), tipoSolucion(tipoSolucion) {
    recursosAsignados = std::vector<std::string>();
}

// Método para obtener el tipo de solución del software de producción
std::string Produccion::getTipoSolucion() const {
    return tipoSolucion;
}

// Método para establecer el tipo de solución del software de producción
void Produccion::setTipoSolucion(std::string tipoSolucion) {
    this->tipoSolucion = tipoSolucion;
}

// Método para obtener la cantidad de recursos asignados al software de producción
int Produccion::getCantidadRecursos() const {
    return recursosAsignados.size();
}

// Método para asignar un recurso al software de producción
void Produccion::asignarRecurso(std::string recurso) {
    recursosAsignados.push_back(recurso);
}

// Constructor de Navegador
Navegador::Navegador(std::string nombre, std::string developer, int clasificacionEdad, float precio)
    : Software(nombre, developer, clasificacionEdad, precio) {
    historialNavegacion = std::vector<std::string>();
}

// Método para obtener el historial de navegación del software de navegación
const std::vector<std::string>& Navegador::getHistorialNavegacion() const {
    return historialNavegacion;
}

// Método para agregar una página al historial de navegación
void Navegador::agregarPaginaHistorial(std::string pagina) {
    historialNavegacion.push_back(pagina);
}

// Constructor de Seguridad
Seguridad::Seguridad(std::string nombre, std::string developer, int clasificacionEdad, float precio, TipoMalware tipoMalware)
    : Software(nombre, developer, clasificacionEdad, precio), tipoMalware(tipoMalware) {
    registrosAcceso = std::vector<std::string>();
}

// Método para obtener el tipo de malware del software de seguridad
TipoMalware Seguridad::getTipoMalware() const {
    return tipoMalware;
}

// Método para establecer el tipo de malware del software de seguridad
void Seguridad::setTipoMalware(TipoMalware tipoMalware) {
    this->tipoMalware = tipoMalware;
}

// Método para obtener el registro de accesos al software de seguridad
std::string Seguridad::getRegistroAcceso() const {
    std::string registroAcceso = "Registro de accesos al software de seguridad:\n";
    for (const std::string& registro : registrosAcceso) {
        registroAcceso += registro + "\n";
    }
    return registroAcceso;
}

// Método para agregar un registro de acceso al software de seguridad
void Seguridad::agregarRegistroAcceso(std::string registro) {
    registrosAcceso.push_back(registro);
}

// Constructor de Social
Social::Social(std::string nombre, std::string developer, int clasificacionEdad, float precio, int cantidadAmigos) 
    : Software(nombre, developer, clasificacionEdad, precio), cantidadAmigos_(cantidadAmigos) {

    amigos_ = std::vector<std::string>();  // Lista de amigos, si ya tienes esta variable en Social.h
}


std::string Social::getEstado() const {
    return estado_;
}

void Social::setEstado(std::string estado) {
    estado_ = estado;
}

void Social::agregarAmigo() {
    // Cuerpo de la función...
}

bool esNino(const std::string& username, const std::vector<Nino>& ninos) {
    for (const auto& nino : ninos) {
        if (nino.getUsuario() == username) {
            return true;
        }
    }
    return false;
}

int Social::getCantidadAmigos() const {
    return amigos_.size();
}

void Social::agregarAmigo(std::string amigo) {
    amigos_.push_back(amigo);
}

void Social::eliminarAmigo(const std::string& amigo) {
    auto it = std::remove(amigos_.begin(), amigos_.end(), amigo);
    if (it != amigos_.end()) {
        amigos_.erase(it, amigos_.end());
        std::cout << "Amigo " << amigo << " eliminado con éxito.\n";
    } else {
        std::cout << "Amigo " << amigo << " no encontrado.\n";
    }
}

std::vector<std::string> Social::obtenerListaAmigos() const {
    return amigos_;
}


std::vector<std::string> registroSoftware; // Declaración de la variable


int main() {
    // Crear e inicializar la base de datos con usuarios y software
    Administrador admin("admin", "adminpass", 30, "admin@example.com");
    std::vector<Nino> ninos;
    std::vector<UsuarioNormal> usuariosNormales;

    // Agregar 4 usuarios Nino a la lista de ninos
    ninos.push_back(Nino("nino1", "ninopass1", 10, "nino1@example.com"));
    ninos.push_back(Nino("nino2", "ninopass2", 12, "nino2@example.com"));
    ninos.push_back(Nino("nino3", "ninopass3", 9, "nino3@example.com"));
    ninos.push_back(Nino("nino4", "ninopass4", 11, "nino4@example.com"));

    // Agregar 10 usuarios UsuarioNormal a la lista de usuariosNormales
    usuariosNormales.push_back(UsuarioNormal("usuario1", "userpass1", 25, "usuario1@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario2", "userpass2", 20, "usuario2@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario3", "userpass3", 28, "usuario3@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario4", "userpass4", 22, "usuario4@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario5", "userpass5", 30, "usuario5@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario6", "userpass6", 27, "usuario6@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario7", "userpass7", 35, "usuario7@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario8", "userpass8", 31, "usuario8@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario9", "userpass9", 26, "usuario9@example.com"));
    usuariosNormales.push_back(UsuarioNormal("usuario10", "userpass10", 29, "usuario10@example.com"));

    std::vector<Software*> software;
    software.push_back(new Juego("Galaxy Quest", "Electronic Arts", 10, 29.99, "Aventura"));
    software.push_back(new Juego("Cyber Knights", "Ubisoft", 12, 39.99, "Aventura"));
    software.push_back(new Juego("Lost Legends", "Rockstar Games", 16, 49.99, "Aventura"));
    software.push_back(new Juego("Nebula Strike", "Bethesda", 18, 59.99, "Aventura"));
    software.push_back(new Juego("Dark Matter Saga", "Capcom", 18, 69.99, "Aventura"));

    software.push_back(new Juego("Inferno Blitz", "Activision", 10, 29.99, "Acción"));
    software.push_back(new Juego("Warriors of Light", "Square Enix", 12, 39.99, "Acción"));
    software.push_back(new Juego("Steel Titans", "Valve", 16, 49.99, "Acción"));
    software.push_back(new Juego("Apocalypse Riders", "Konami", 18, 59.99, "Acción"));
    software.push_back(new Juego("Crimson Chaos", "Epic Games", 18, 69.99, "Acción"));

    software.push_back(new Juego("Kingdoms of Strategy", "Blizzard Entertainment", 10, 29.99, "Estrategia"));
    software.push_back(new Juego("Empire Builders", "CD Projekt Red", 12, 39.99, "Estrategia"));
    software.push_back(new Juego("Age of Wonders", "Sega", 16, 49.99, "Estrategia"));
    software.push_back(new Juego("Star Commanders", "Square Enix", 18, 59.99, "Estrategia"));
    software.push_back(new Juego("Space Empires", "Electronic Arts", 18, 69.99, "Estrategia"));
    
    software.push_back(new Juego("Counter-Strike: Global Offensive", "Valve", 18, 19.99, "FPS"));
    software.push_back(new Juego("World of Warcraft", "Blizzard Entertainment", 12, 14.99, "MMO"));
    software.push_back(new Juego("Tetris", "Tetris Company", 0, 4.99, "Puzzle"));
    software.push_back(new Juego("The Sims 4", "Electronic Arts", 12, 39.99, "Simulación"));
    software.push_back(new Juego("Rocket League", "Psyonix", 10, 19.99, "Deportes"));
    software.push_back(new Juego("Stardew Valley", "ConcernedApe", 10, 14.99, "Simulación agrícola"));
    software.push_back(new Juego("Minecraft", "Mojang Studios", 7, 26.95, "Sandbox"));
    
    software.push_back(new Ofimatica("Microsoft Office", "Microsoft", 0, 149.99, 3));
    software.push_back(new Ofimatica("LibreOffice", "The Document Foundation", 0, 0.00, 3));
    software.push_back(new Ofimatica("Google Workspace", "Google", 0, 6.00, 5));
    software.push_back(new Ofimatica("WPS Office", "Kingsoft", 0, 29.99, 3));
    software.push_back(new Ofimatica("Zoho Office Suite", "Zoho Corporation", 0, 12.00, 4));
    
    software.push_back(new Produccion("Adobe Premiere Pro", "Adobe Inc.", 18, 249.99, "Video"));
    software.push_back(new Produccion("Ableton Live", "Ableton AG", 18, 449.00, "Música"));
    software.push_back(new Produccion("Final Cut Pro", "Apple Inc.", 18, 299.99, "Video"));
    software.push_back(new Produccion("Pro Tools", "Avid Technology", 18, 599.00, "Música"));
    software.push_back(new Produccion("OBS Studio", "OBS Project", 0, 0.00, "Streaming"));
    software.push_back(new Produccion("Adobe Photoshop", "Adobe Inc.", 12, 20.99, "Fotos"));

    software.push_back(new Navegador("Google Chrome", "Google LLC", 0, 0.00));
    software.push_back(new Navegador("Mozilla Firefox", "Mozilla Foundation", 0, 0.00));
    software.push_back(new Navegador("Microsoft Edge", "Microsoft Corporation", 0, 0.00));
    software.push_back(new Navegador("Safari", "Apple Inc.", 0, 0.00));
    
    software.push_back(new Seguridad("Norton Security", "NortonLifeLock", 0, 49.99, TipoMalware::Ransomware));
    software.push_back(new Seguridad("Malwarebytes", "Malwarebytes Corporation", 0, 59.99, TipoMalware::Spyware));
    software.push_back(new Seguridad("Kaspersky Internet Security", "Kaspersky Lab", 0, 49.99, TipoMalware::Botnets));
    software.push_back(new Seguridad("Bitdefender Total Security", "Bitdefender", 0, 59.99, TipoMalware::Rootkits));
    software.push_back(new Seguridad("McAfee Total Protection", "McAfee, LLC", 0, 49.99, TipoMalware::Gusanos));
    software.push_back(new Seguridad("AVG Internet Security", "AVG Technologies", 0, 59.99, TipoMalware::Troyanos));
    
    software.push_back(new Social("Facebook", "Meta Platforms, Inc.", 18, 0.00, 2500));
    software.push_back(new Social("Instagram", "Meta Platforms, Inc.", 13, 0.00, 2000));
    software.push_back(new Social("Twitter", "Twitter, Inc.", 13, 0.00, 1500));
    software.push_back(new Social("LinkedIn", "LinkedIn Corporation", 18, 0.00, 1000));
    software.push_back(new Social("Snapchat", "Snap Inc.", 13, 0.00, 800));



    
    bool loggedIn = false;
    std::string currentUser;

    while (true) {
        if (!loggedIn) {
            // Menú de inicio de sesión
            std::cout << "Bienvenido al sistema de gestión de software." << std::endl;
            std::cout << "1. Iniciar sesión" << std::endl;
            std::cout << "2. Salir del programa" << std::endl;
            std::cout << "Seleccione una opción: " << std::endl;
            int choice;
            std::cin >> choice;

            if (choice == 1) {
                // Implementa la lógica de inicio de sesión aquí
                std::string username, password;
                std::cout << "Usuario: ";
                std::cin >> username;
                std::cout << "Contraseña: ";
                std::cin >> password;

                // Verifica credenciales y actualiza loggedIn y currentUser si es necesario
                for (auto& usuario : ninos) {
                    if (usuario.getUsuario() == username && usuario.getContrasena() == password) {
                        loggedIn = true;
                        currentUser = username;
                        break;
                    }
                }
                for (auto& usuario : usuariosNormales) {
                    if (usuario.getUsuario() == username && usuario.getContrasena() == password) {
                        loggedIn = true;
                        currentUser = username;
                        break;
                    }
                }
                if (!loggedIn && admin.getUsuario() == username && admin.getContrasena() == password) {
                    loggedIn = true;
                    currentUser = username;
                }
            } else if (choice == 2) {
                std::cout << "¡Hasta luego!" << std::endl;
                break; // Sale del programa
            } else {
                std::cout << "Opción no válida. Por favor, elige 1 o 2." << std::endl;
            }
        } else {
        // Menú principal después de iniciar sesión
        std::cout << "Bienvenido, " << currentUser << "!" << std::endl;
        std::cout << "Menú principal:" << std::endl;
        std::cout << "1. Agregar software" << std::endl;
        std::cout << "2. Eliminar software" << std::endl;
        std::cout << "3. Ver registro (log) de software" << std::endl;
        std::cout << "4. Utilizar software en específico" << std::endl;
        std::cout << "5. Cerrar sesión" << std::endl;
        int choice;
        std::cin >> choice;

        // Implementa la lógica para cada opción del menú aquí
            switch (choice) {
            case 1: // Agregar software
                if (currentUser == "admin") {
            // Solo el administrador puede agregar software
            std::string nombre, developer;
            int clasificacionEdad;
            float precio;

            // Solicita los detalles del nuevo software
            std::cout << "Nombre del software: ";
            std::cin.ignore();
            std::getline(std::cin, nombre);

            std::cout << "Desarrollador: ";
            std::getline(std::cin, developer);

            std::cout << "Clasificación de edad: ";
            std::cin >> clasificacionEdad;

            std::cout << "Precio: ";
            std::cin >> precio;

            // Agrega el nuevo software al catálogo
            software.push_back(new Software(nombre, developer, clasificacionEdad, precio));

            std::cout << "El software ha sido agregado con éxito." << std::endl;
        } else {
            std::cout << "No tienes permiso para realizar esta acción." << std::endl;
        }
        break;
            case 2: // Eliminar software
                if (currentUser == "admin" || currentUser == "usuario_normal") {
            // El administrador y los usuarios normales pueden eliminar software
            std::cout << "Lista de software disponible:" << std::endl;
            for (int i = 0; i < software.size(); ++i) {
                std::cout << i + 1 << ". " << software[i]->getNombre() << std::endl;
            }
            int softwareIndex;
            std::cout << "Seleccione el software que desea eliminar (ingrese el número): ";
            std::cin >> softwareIndex;

            // Verifica si el índice es válido
            if (softwareIndex >= 1 && softwareIndex <= software.size()) {
                // Libera la memoria del objeto de software eliminado
                delete software[softwareIndex - 1];
                // Elimina el puntero del vector
                software.erase(software.begin() + softwareIndex - 1);
                std::cout << "El software ha sido eliminado con éxito." << std::endl;
            } else {
                std::cout << "Selección no válida." << std::endl;
            }
        } else {
            std::cout << "No tienes permiso para realizar esta acción." << std::endl;
        }
        break;

            case 3: // Ver registro de software
                 if (currentUser == "admin" || currentUser == "usuario_normal") {
            // El administrador y los usuarios normales pueden ver el registro
            std::cout << "Registro de software:" << std::endl;
            for (const auto& logEntry : registroSoftware) {
                std::cout << logEntry << std::endl;
            }
        } else {
            std::cout << "No tienes permiso para realizar esta acción." << std::endl;
        }
        break;
        
 
        case 4: // Utilizar software en específico
        {
        while (true) {
        std::cout << "Lista de software disponible:" << std::endl;
        for (int i = 0; i < software.size(); ++i) {
            std::cout << i + 1 << ". " << software[i]->getNombre() << std::endl;
        }
        int softwareIndex;
        std::cout << "Seleccione el software que desea utilizar (ingrese el número): ";
        std::cin >> softwareIndex;

        // Verifica si el índice es válido
        if (softwareIndex >= 1 && softwareIndex <= software.size()) {
            Software* selectedSoftware = software[softwareIndex - 1];

        
                switch (selectedSoftware->getTipo()) {
                    case TipoSoftware::Social:
                    {
                        Social* socialSoftware = dynamic_cast<Social*>(selectedSoftware);
                        if (socialSoftware) {
                            std::cout << "Usando el software de redes sociales: " << socialSoftware->getNombre() << std::endl;
                            
                            // Verificar si el software ya ha sido inicializado con amigos
                            if (socialSoftware->getCantidadAmigos() == 0) {
                                if (esNino(currentUser, ninos)) {
                                    // Encuentra dos otros niños y añádelos como amigos
                                    std::vector<std::string> amigosNinos;
                                    int count = 0;
                                    for (const auto& nino : ninos) {
                                        if (count >= 2) break; // Ya hemos encontrado dos niños
                                        if (nino.getUsuario() != currentUser) { // No queremos añadirnos a nosotros mismos
                                            amigosNinos.push_back(nino.getUsuario());
                                            count++;
                                        }
                                    }
                                    for (const auto& nombreAmigo : amigosNinos) {
                                        socialSoftware->agregarAmigo(nombreAmigo);
                                    }
                                } else {
                                    // Añadir dos amigos cualesquiera para usuarios normales (Puedes modificar esto según tus necesidades)
                                    socialSoftware->agregarAmigo("AmigoPorDefecto1");
                                    socialSoftware->agregarAmigo("AmigoPorDefecto2");
                                }
                            }
                    
                            
                            int opcion;
                            do {
                                std::cout << "\nMenú de Software Social:\n";
                                std::cout << "1. Agregar amigo\n";
                                std::cout << "2. Eliminar amigo\n";
                                std::cout << "3. Publicar estado\n";
                                std::cout << "4. Ver lista de amigos\n";
                                std::cout << "5. Regresar al menú anterior\n";
                                std::cout << "Ingresa tu opción: ";
                                std::cin >> opcion;
                            
                                switch(opcion) {
                                    case 1:
                                    {
                                        std::string nuevoAmigo;
                                        std::cout << "Ingresa el nombre del nuevo amigo: ";
                                        std::cin >> nuevoAmigo; // Asumiendo que los nombres no tienen espacios. Si no es el caso, usa std::getline
                                        socialSoftware->agregarAmigo(nuevoAmigo);
                                        std::cout << nuevoAmigo << " ha sido añadido como amigo.\n";
                                        break;
                                    }
                                    case 2:
                                    {
                                        std::string amigoAEliminar;
                                        std::cout << "Ingresa el nombre del amigo a eliminar: ";
                                        std::cin >> amigoAEliminar; // Lo mismo respecto a los espacios
                                        // Suponiendo que tienes una función eliminarAmigo en tu clase Social
                                        socialSoftware->eliminarAmigo(amigoAEliminar);
                                        std::cout << amigoAEliminar << " ha sido eliminado de tu lista de amigos.\n";
                                        break;
                                    }
                                    case 3:
                                        socialSoftware->publicarEstado();
                                        break;
                                    case 4:
                                    {
                                        std::vector<std::string> listaAmigos = socialSoftware->obtenerListaAmigos();
                                        std::cout << "\nLista de amigos:\n";
                                        for(const auto& amigo : listaAmigos) {
                                            std::cout << amigo << "\n";
                                        }
                                        break;
                                    }
                                    case 5:
                                        std::cout << "Regresando al menú anterior.\n";
                                        break;
                                    default:
                                        std::cout << "Opción no válida. Inténtalo de nuevo.\n";
                                        break;
                                }
                            } while (opcion != 5 && socialSoftware);
                        } else {
                            std::cout << "No puedes utilizar este software como software de redes sociales." << std::endl;
                        }
                    
                        break;
                    }

                    
                    case TipoSoftware::Juego:
                    
                    {
                        Juego* juegoSoftware = dynamic_cast<Juego*>(selectedSoftware);
                        if (juegoSoftware) {
                            int opcion;
                            while (true) {
                                std::cout << "\nMenú del Juego:\n";
                                std::cout << "1. Mostrar detalles del juego" << std::endl;
                                std::cout << "2. Establecer/Modificar género del juego" << std::endl;
                                std::cout << "3. Ver historial de partidas" << std::endl;
                                std::cout << "4. Registrar nueva partida" << std::endl;
                                std::cout << "5. Salir" << std::endl;
                                std::cout << "Ingrese la opción: ";
                                std::cin >> opcion;
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpia el buffer
                                
                                switch (opcion) {
                                    case 1:
                                        juegoSoftware->mostrarDetalles();
                                        break;
                    
                                    case 2:
                                    {
                                        std::cout << "Ingrese el nuevo género para el juego: ";
                                        std::string nuevoGenero;
                                        std::getline(std::cin, nuevoGenero); // Aceptar nombres de géneros con espacios
                                        juegoSoftware->setGenero(nuevoGenero);
                                        std::cout << "Género del juego actualizado a: " << nuevoGenero << std::endl;
                                        break;
                                    }
                    
                                    case 3:
                                        std::cout << "\nHistorial de Partidas:\n" << juegoSoftware->getHistorialPartidas() << std::endl;
                                        break;
                    
                                    case 4:
                                    {
                                        std::cout << "Ingrese el resultado de la nueva partida: ";
                                        std::string resultado;
                                        std::getline(std::cin, resultado);
                                        juegoSoftware->registrarPartida(resultado);
                                        std::cout << "Partida registrada con éxito.\n";
                                        break;
                                    }
                    
                                    case 5:
                                        std::cout << "Regresando al menú anterior.\n";
                                        return 0;
                    
                                    default:
                                        std::cout << "Opción no válida. Inténtalo de nuevo.\n";
                                }
                            }
                        } else {
                            std::cout << "Error al acceder al juego." << std::endl;
                        }
                        break;
                    }
                    case TipoSoftware::Seguridad:
                        {
                            Seguridad* seguridadSoftware = dynamic_cast<Seguridad*>(selectedSoftware);
                            if (seguridadSoftware) {
                                std::cout << "Usando el software de seguridad: " << seguridadSoftware->getNombre() << std::endl;
                    
                                int opcion;
                                do {
                                    std::cout << "\nMenú de Software de Seguridad:\n";
                                    std::cout << "1. Realizar escaneo\n";
                                    std::cout << "2. Actualizar base de datos de virus\n";
                                    std::cout << "3. Ver historial de escaneos\n";
                                    std::cout << "4. Configurar opciones de escaneo\n";
                                    std::cout << "5. Regresar al menú anterior\n";
                                    std::cout << "Ingresa tu opción: ";
                                    std::cin >> opcion;
                    
                                    switch(opcion) {
                                        case 1:
                                            seguridadSoftware->realizarEscaneo();
                                            break;
                                        case 2:
                                            seguridadSoftware->actualizarBaseDatos();
                                            std::cout << "Base de datos actualizada.\n";
                                            break;
                                        case 3:
                                            seguridadSoftware->mostrarHistorialEscaneos();
                                            break;
                                        case 4:
                                            seguridadSoftware->configurarOpciones();
                                            break;
                                        case 5:
                                            std::cout << "Regresando al menú anterior.\n";
                                            break;
                                        default:
                                            std::cout << "Opción no válida. Inténtalo de nuevo.\n";
                                            break;
                                    }
                                } while (opcion != 5);
                            } else {
                                std::cout << "No puedes utilizar este software como software de seguridad." << std::endl;
                            }
                        }
                        break;
                    case TipoSoftware::Produccion:
                    {
                        Produccion* produccionSoftware = dynamic_cast<Produccion*>(selectedSoftware);
                        if (produccionSoftware) {
                            std::cout << "Usando el software de producción: " << produccionSoftware->getNombre() << std::endl;
                    
                            int opcionProduccion;
                            do {
                                std::cout << "\nMenú de Software de Producción:\n";
                                std::cout << "1. Crear proyecto\n";
                                std::cout << "2. Editar proyecto\n";
                                std::cout << "3. Exportar proyecto\n";
                                std::cout << "4. Mostrar información del proyecto\n";
                                std::cout << "5. Regresar al menú anterior\n";
                                std::cout << "Ingresa tu opción: ";
                                std::cin >> opcionProduccion;
                    
                                switch(opcionProduccion) {
                                    case 1:
                                        produccionSoftware->crearProyecto();
                                        std::cout << "Proyecto creado.\n";
                                        break;
                                    case 2:
                                        produccionSoftware->editarProyecto();
                                        std::cout << "Proyecto editado.\n";
                                        break;
                                    case 3:
                                        produccionSoftware->exportarProyecto();
                                        std::cout << "Proyecto exportado.\n";
                                        break;
                                    case 4:
                                        produccionSoftware->mostrarInformacionProyecto();
                                        break;
                                    case 5:
                                        std::cout << "Regresando al menú anterior.\n";
                                        break;
                                    default:
                                        std::cout << "Opción no válida. Inténtalo de nuevo.\n";
                                        break;
                                }
                            } while (opcionProduccion != 5);
                        } else {
                            std::cout << "No puedes utilizar este software como software de producción." << std::endl;
                        }
                    
                        break;
                    }
                    case TipoSoftware::Ofimatica:
                    {
                        Ofimatica* ofimaticaSoftware = dynamic_cast<Ofimatica*>(selectedSoftware);
                        if (ofimaticaSoftware) {
                            bool subMenuRunning = true;
                            while (subMenuRunning) {
                                // Display submenu options
                                std::cout << "---- Submenu Ofimática ----\n";
                                std::cout << "1. Crear archivo\n";
                                std::cout << "2. Borrar archivo\n";
                                std::cout << "3. Mostrar cantidad de archivos\n";
                                std::cout << "4. Regresar al menú principal\n";
                                std::cout << "Elija una opción: ";
                                
                                int subMenuChoice;
                                std::cin >> subMenuChoice;
                
                                switch (subMenuChoice) {
                                    case 1:
                                        ofimaticaSoftware->crearArchivo();
                                        std::cout << "Archivo creado.\n";
                                        break;
                                    case 2:
                                        ofimaticaSoftware->borrarArchivo();
                                        std::cout << "Archivo borrado.\n";
                                        break;
                                    case 3:
                                        std::cout << "Cantidad de archivos: " << ofimaticaSoftware->getCantidadArchivos() << "\n";
                                        break;
                                    case 4:
                                        subMenuRunning = false;  // Exit submenu
                                        break;
                                    default:
                                        std::cout << "Opción no válida.\n";
                                        break;
                                }
                            }
                        } else {
                            std::cout << "Software seleccionado no es de tipo Ofimática.\n";
                        }
                    }
                    break;
                    default:
                        std::cout << "Tipo de software desconocido." << std::endl;
                }
            } else {
                std::cout << "Selección no válida." << std::endl;
            }
    
            std::cout << "¿Desea salir del programa? (s/n): ";
            char salir;
            std::cin >> salir;
            if (salir == 's' || salir == 'S') {
                break;
            }
        }
    
        return 0;
    }

            case 5: // Cerrar sesión
                std::cout << "¿Deseas logear con otro usuario o terminar el programa?" << std::endl;
                    std::cout << "1. Logear con otro usuario" << std::endl;
                    std::cout << "2. Terminar el programa" << std::endl;
                    int logoutChoice;
                    std::cin >> logoutChoice;
                    if (logoutChoice == 1) {
                        loggedIn = false;
                        currentUser = "";
                    } else if (logoutChoice == 2) {
                        std::cout << "¡Hasta luego!" << std::endl;
                        // Liberar la memoria de los objetos de software
                        for (auto& s : software) {
                            delete s;
                        }
                        return 0;
                    }
                    break;

                default:
                    std::cout << "Opción no válida. Por favor, elige una opción válida." << std::endl;
                    break;
                
                
        }
    }
}
    // Liberar la memoria de los objetos de software
    for (auto& s : software) {
        delete s;
    }

    return 0;
}
