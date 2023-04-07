#include <iostream>

using namespace std;


template<class... Ts>
auto suma(Ts... args){
    return (args+...);
}

int main(){
    cout << "Utilizando 'suma'" << endl;
    cout << suma(1) << endl;
    cout << suma(1,2) << endl;
    cout << suma(1,2,3.5,0.5,5) << endl;

    return 0;
}