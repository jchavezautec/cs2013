#include <iostream>

using namespace std;

template <class T>
class range{
private:
    T min;
    T max;
    T step;
public:
    range(T min, T max, T step){
        this->min = min;
        this->max = max;
        this->step = step;
    }

    void print(){
        for(T i = min; i <= max; i += step){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main () {
    range<int> obj(1, 10, 1);
    obj.print();

    range<double> obj2(1.1, 11, 1.1);
    obj2.print();

    return 0;
}
