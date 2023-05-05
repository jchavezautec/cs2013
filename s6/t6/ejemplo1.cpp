#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v{1,2,4,5};

    cout << "Vector Original:" << endl;
    cout << "================" << endl;

    for (int i = 0; i < v.size(); i ++){
        cout << "v[" << i << "]=" << v[i];
        cout << ", &v["<< i << "]=" << &v[i];
        cout << endl;
    }

    v.insert(v.begin()+2,3);

    cout << "\nVector Modificado:" << endl;
    cout << "==================" << endl;

    for (int i = 0; i < v.size(); i ++){
        cout << "v[" << i << "]=" << v[i];
        cout << ", &v["<< i << "]=" << &v[i];
        cout << endl;
    }

    return 0;
}