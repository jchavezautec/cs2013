#include <iostream>
#include <vector>

using namespace std;

// Definición de la clase Usuario
class Usuario {
private:
    string nombre;

public:
    Usuario(const string& nombre) : nombre(nombre) {}

    string getNombre() const {
        return nombre;
    }
};

// Definición del iterador de la base de datos
class DatabaseIterator {
private:
    vector<Usuario>& usuarios;
    int indice;

public:
    DatabaseIterator(vector<Usuario>& usuarios) : usuarios(usuarios), indice(0) {}

    Usuario& getCurrent() {
        return usuarios[indice];
    }

    void next() {
        indice++;
    }

    bool hasNext() {
        return indice < usuarios.size();
    }
};

// Definición de la base de datos
class Database {
private:
    vector<Usuario> usuarios;

public:
    void agregarUsuario(const string& nombre) {
        usuarios.push_back(Usuario(nombre));
    }

    DatabaseIterator createIterator() {
        return DatabaseIterator(usuarios);
    }
};

// Función main
int main() {
    Database database;
    database.agregarUsuario("Alice");
    database.agregarUsuario("Bob");
    database.agregarUsuario("Charlie");

    DatabaseIterator iterator = database.createIterator();
    while (iterator.hasNext()) {
        Usuario& usuario = iterator.getCurrent();
        cout << "Nombre de usuario: " << usuario.getNombre() << endl;
        iterator.next();
    }

    return 0;
}
