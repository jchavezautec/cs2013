#include <iostream>

using namespace std;

template <class T>
T foo(T x, int n){
  T sum = 1;
  for(int i=1; i<=n; i++)
    sum += i * x;
  return sum;
}

template<class T1, class T2, class T3>
T1 foo(T1 x, T2 y, T3& z ){
  z = x / y;
  return x * y;
}

template<typename T1, typename T2>
class Numeros{
  private:
    T1 _x;
    T2 _y;
  public:
    Numeros(T1 x, T2 y){
      _x = x;
      _y = y;
    }
    T1 suma(){ return _x + _y; }
    T1 resta(){ return _x - _y; }
    T2 mult(){ return _x * _y; }
    float div(){ return _x / _y;}
};

#include <vector>

template<class T>
class RandomVector{
  private:
    vector<T> vec;
  public:
    RandomVector(int n){
      for(int i=0; i<n; i++){
        T z = rand() % 101 - 50; // z : [-50,50]
        vec.push_back(z / 10);
      }
    }
    void print(){
      for(auto e: vec)
        cout << e << " ";
      cout << endl;
    }
};

int main () {
   /*
   // Ejercicio 1.1
   //float s = foo(1.1, 2);
   //cout << "sum = " << s << endl;

   // Ejercicio 1.2
   float z;
   cout << foo(1.2,2,z) << endl;
   cout << z << endl;
   cout << "*******************" << endl;
   cout << foo(5,2,z) << endl;
   cout << z << endl;
    
   // Ejercicio 2.1
   Numeros<float,int> obj(2.1, 3);
   cout << obj.suma() << endl;
   cout << obj.resta() << endl;
   cout << obj.mult() << endl;
   cout << obj.div() << endl;  
   */
   RandomVector<int> v1(10);
   RandomVector<float> v2(10);

   v1.print();
   v2.print();
  
   return 0;
}
