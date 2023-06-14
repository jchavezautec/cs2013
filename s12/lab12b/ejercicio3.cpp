#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Tarea {
private:
    string nombre;
    int prioridad;

public:
    Tarea(const string& n, int p) : nombre(n), prioridad(p) {}

    string getNombre() const { return nombre;}
    int getPrioridad() const { return prioridad;}

    // Sobrecargamos el operador < para que la 'priority_queue' 
    // ordene las tareas por prioridad
    bool operator<(const Tarea& otra) const {
        return prioridad < otra.prioridad; 
    }
};

class GestorTareas {
private:
    priority_queue<Tarea> tareas; // Usamos una 'priority_queue' en lugar de una queue
public:
    void agregarTarea(const Tarea& tarea) {
        tareas.push(tarea);
        cout << "Tarea agregada: " << tarea.getNombre() << ", Prioridad: " << tarea.getPrioridad() << endl;
    }

    void ejecutarTareas() {
        cout << "Ejecutando tareas..." << endl;

        while (!tareas.empty()) {
            Tarea tareaActual = tareas.top(); // Usamos top() en lugar de front()
            tareas.pop();
            cout << "Ejecutando tarea: " << tareaActual.getNombre() << ", Prioridad: " << tareaActual.getPrioridad() << endl;
        }
    }
};

int main() {
    GestorTareas gestor;

    Tarea tareaA("Tarea A", 2);
    Tarea tareaB("Tarea B", 1);
    Tarea tareaC("Tarea C", 3);

    gestor.agregarTarea(tareaA);
    gestor.agregarTarea(tareaB);
    gestor.agregarTarea(tareaC);

    gestor.ejecutarTareas(); // Salida: Tarea C, Tarea A, Tarea B

    return 0;
}
