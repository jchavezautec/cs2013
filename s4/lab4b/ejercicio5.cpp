#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class Vec{
private:
  vector<T> vec;
public:
  void push_back_many(T arg){
    vec.push_back(arg);
  }
  template<typename T0, typename...Ts>
  void push_back_many(T0 arg, Ts...args){
    vec.push_back(arg);
    push_back_many(args...);
  }

  void print(){
    for(int e: vec)
      cout << e << " ";
    cout << endl;
  }
};

int main() {
  Vec<int> vec;
  vec.push_back_many(1);
  vec.push_back_many(2);
  vec.print();
  vec.push_back_many(3,4,5);
  vec.print();
}