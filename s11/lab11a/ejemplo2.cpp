#include <iostream>

using namespace std;

class Foo {
public:
  static int x;
  int y = 0;

  static void f1() {
    x = 2;
    // y = 3;
  }
  void f2() {
    x = 3;
    y = 3;
  }
};

int Foo::x = 3;

int main() {
  Foo::f1();
  Foo obj1;
  cout << "x = " << obj1.x << ", ";
  cout << "y = " << obj1.y << endl;

  Foo obj2;
  cout << "x = " << obj1.x << ", ";
  cout << "y = " << obj1.y << endl;

  return 0;
}