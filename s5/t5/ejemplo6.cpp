#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v(5);

    // Numeros aleatorios entre 0 y 9
    generate(v.begin(), v.end(), [](){return rand()%10;});
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << "\n---------------------------------\n";

    int n=1;
    generate(v.begin(), v.end(), [&n](){return n++;});
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << "\n---------------------------------\n";

    generate(v.begin(), v.end(), [i=1]()mutable{return i*=2;});
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << "\n---------------------------------\n";

}