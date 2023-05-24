#include <iostream>

class Logger {
public:
    // Atributo estático para almacenar la instancia única
    static Logger* instance;
    static Logger getInstance() {
        // Implementar la lógica para retornar la instancia única
        if (instance == nullptr) {
            instance = new Logger();
        }
        return *instance;
    }

    void log(const std::string& message) {
        // Implementar la lógica para imprimir el mensaje en la consola
        std::cout << message << std::endl;
    }
private:
    // Constructor privado para evitar la creación de instancias
    Logger() {}
};

// Inicializar el atributo estático
Logger* Logger::instance = nullptr;

int main() {
    Logger logger = Logger::getInstance();
    logger.log("Este es un mensaje de prueba.");
	
	// Resultado esperado en consola:
	// Este es un mensaje de prueba.

    return 0;
}
