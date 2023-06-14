#include <iostream>
#include <stack>

using namespace std;

string validarParentesis(const string& cadena) {
    stack<char> pila;

    for (char c : cadena) {
        if (c == '(' || c == '{' || c == '[') {
            pila.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (pila.empty()) {
                return "Error: Operacion incorrecta!";
            }

            char top = pila.top();
            pila.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return "Error: Operacion incorrecta!";
            }
        }
    }

    if (!pila.empty()) {
        return "Error: Operacion incorrecta!";
    }
    return "Operacion correcta!";
}

int main() {
    string cadena1 = "[1+(3*5)-3]}";
    cout << validarParentesis(cadena1) << endl;
    // Error: Operacion incorrecta!

    string cadena2 = "{1+[1-(3*4)/7]";
    cout << validarParentesis(cadena2) << endl;
    // Error: Operacion incorrecta!

    string cadena3 = "[1+(5*2)]";
    cout << validarParentesis(cadena3) << endl;
    // Operacion correcta!
    
    return 0;
}
