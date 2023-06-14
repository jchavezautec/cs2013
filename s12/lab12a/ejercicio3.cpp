#include <iostream>
#include <stack>

using namespace std;

class EditorTexto {
private:
    string texto;
    stack<string> historial;
public:
    EditorTexto() {
        texto = "";
    }

    void agregarTexto(const string& nuevoTexto) {
        historial.push(texto);
        texto += nuevoTexto;
    }

    void deshacer() {
        if (!historial.empty()) {
            texto = historial.top();
            historial.pop();
        }
    }

    string getTexto() const {
        return texto;
    }
};

int main() {
    EditorTexto editor;

    editor.agregarTexto("Hola ");
    cout << editor.getTexto() << endl; // Salida: Hola

    editor.agregarTexto("Mundo ");
    editor.agregarTexto("en C++");
    cout << editor.getTexto() << endl; // Salida: Hola Mundo en C++

    editor.deshacer();
    cout << editor.getTexto() << endl; // Salida: Hola Mundo

    editor.deshacer();
    cout << editor.getTexto() << endl; // Salida: Hola

    return 0;
}
