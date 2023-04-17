#include <iostream>

using namespace std;

template <class T>
void swap_func(T& x, T& y){
    T temp = x;
    x = y;
    y = temp;
}

int main(){
    int x = 2;
    int y = 3;

    swap_func(x,y);

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    
    char a = 'a';
    char b = 'b';

    swap_func(a,b);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}