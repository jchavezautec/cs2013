#include <iostream>

using namespace std;

template <class T>
class Numeros{
private:
    T a;
    T b;
public:
    Numeros(T a, T b){
        this->a = a;
        this->b = b;
    }

    T suma(){
        return a + b;
    }

    T resta(){
        return a - b;
    }

    T mult(){
        return a * b;
    }

    float div(){
        return a / b;
    }

    void mostrar_ops(){
        cout << "======================================" << endl;
        cout << "Cuando a = " << a << " y b = " << b << endl;
        cout << "Suma: " << suma() << endl;
        cout << "Resta: " << resta() << endl;
        cout << "Multiplicacion: " << mult() << endl;
        cout << "Division: " << div() << endl;
        cout << "======================================" << endl;
    }
};

int main(){
    Numeros<int> obj(2, 3);
    obj.mostrar_ops();

    Numeros<double> obj2(2.1, 3.2);
    obj2.mostrar_ops();

    return 0;
}