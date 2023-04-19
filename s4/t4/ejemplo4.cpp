#include <iostream>
#include <cmath>

using namespace std;


template<class... Ts>
float suma(Ts... args){
    float s = (pow(args,2)+...);
    return s / sizeof...(args);
}

int main(){
    cout << "Utilizando 'suma'" << endl;
    cout << suma(1) << endl;
    cout << suma(1,2) << endl;
    cout << suma(1,2,3.5,0.5,5) << endl;

    return 0;
}