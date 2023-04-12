#include <iostream>

using namespace std;

template<class T1, class T2, class T3>
T1 foo(T1 x, T2 y, T3& z ){
  z = x / y;
  return x * y;
}

int main(){
    float x = 1.1;
    int y = 2;
    float z;
    float s = foo(1, 1.3, z);

    cout << "prod = " << s << endl;
    cout << "div  = " << z << endl;
    
    return 0;
}