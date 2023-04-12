#include <iostream>

using namespace std;

template <class T>
T foo(T x, int n){
  T sum = 1;
  for(int i=1; i<=n; i++)
    sum += i * x;
  return sum;
}

int main(){
   float s = foo(1, 2);
   cout << "sum = " << s << endl;

   return 0;  
}