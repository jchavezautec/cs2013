#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

template<class T>
class printVector{
private:
    char _end;
public:
    printVector(char c = ' '): _end(c) {}
    void operator() (T x){
        cout << x << _end;
    }
};

int main(){
    vector<int> v(10);
    for (int i=0; i<10; i++)
        v[i] = rand()%100;
    //generate(v.begin(), v.end(), [](){return rand()%100;});
    
    for_each(v.begin(), v.end(), printVector<int>());
    cout << endl;

    vector<int>::iterator it = v.begin();

    int max_val = *it;
    for (it = next(v.begin()); it!=v.end(); it++)
        if (*it > max_val)
            max_val = *it;

    cout << "max_val = "<< max_val << endl;

    float suma = 0.;
    for (it = v.begin(); it!=v.end(); it++)
        suma += *it;

    cout << "promedio = "<< suma / v.size() << endl;

    return 0;
}