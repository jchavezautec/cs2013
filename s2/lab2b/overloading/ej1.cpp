#include <iostream>
using namespace std;

class numComp {
private:
  int real, imag;

public:
  numComp(int r=0, int i=0) {
    real = r;
    imag = i;
  }

  numComp operator+(numComp const &obj) {
    numComp res;
    res.real = real + obj.real;
    res.imag = imag + obj.imag;
    return res;
  }

  numComp operator-(numComp const &obj) {
    numComp res;
    res.real = real - obj.real;
    res.imag = imag - obj.imag;
    return res;
  }

  numComp operator*(numComp const &obj) {
    numComp res;
    res.real = (real * obj.real - imag * obj.imag);
    res.imag = (real * obj.imag + imag * obj.real);
    return res;
  }

  void show() { 
    cout << real << " + i" << imag << '\n'; 
  }
};

int main() {
  numComp c1(2, 3), c2(1, 1);
  c1.show();
  c2.show();

  numComp c3 = c1 + c2;
  numComp c4 = c1 - c2;
  numComp c5 = c1 * c2;

  c3.show();
  c4.show();
  c5.show();
  
}
