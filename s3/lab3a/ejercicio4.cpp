#include <iostream>

using namespace std;

template <class T>
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
    }
};

int main(){
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


    return 0;
}