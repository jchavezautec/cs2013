#include <iostream>

using namespace std;

template <class T>
<<<<<<< HEAD
class GuessTheNumber{
private:
    int numero;
public:
    GuessTheNumber(): numero(rand() % 10){};
    void guessNumber(T n){
        if (numero == (int)n)
            cout << "Adivinaste!" << endl;
        else
            cout << "Sigue intentando" << endl;
=======
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
>>>>>>> aaabd7447294cdb65bd133a981d5eb159087bbd9
    }
};

int main(){
<<<<<<< HEAD
    GuessTheNumber<int> guess;
    int n;
    cout << "Adivina el numero: ";
    cin >> n;
    guess.guessNumber(n);

    GuessTheNumber<float> guess2;
    float n2;
    cout << "Adivina el numero: ";
    cin >> n2;
    guess2.guessNumber(n2);

=======
    Numeros<int> obj(2, 3);
    obj.mostrar_ops();

    Numeros<double> obj2(2.1, 3.2);
    obj2.mostrar_ops();
>>>>>>> aaabd7447294cdb65bd133a981d5eb159087bbd9

    return 0;
}