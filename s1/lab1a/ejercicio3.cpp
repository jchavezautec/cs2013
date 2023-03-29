#include <iostream>
#include <cmath>

using namespace std;

class Vector3D{
friend ostream &print(ostream&, const Vector3D&);
friend class Matriz2D;
private:
    float* ptr;
public:
    Vector3D(){
        ptr = new float[3];
        for(int i = 0; i < 3; i++){
            ptr[i] = 0;
        }
    }
    Vector3D(float x, float y, float z){
        ptr = new float[3];
        ptr[0] = x;
        ptr[1] = y;
        ptr[2] = z;
    }
    ~Vector3D(){
        delete[] ptr;
        ptr = NULL;
    }
    float modulo(){
        return sqrt(ptr[0]*ptr[0] + ptr[1]*ptr[1] + ptr[2]*ptr[2]);
    }

};

ostream &print(ostream& os, const Vector3D& item){
    for(int i = 0; i < 3; i++){
        os << item.ptr[i] << " ";
    }
    os << endl;
    return os;
}

class Matriz2D{
public:
    Matriz2D(){
        n = 3;
        ptr = new int*[n];
        for(int i = 0; i < n; i++){
            ptr[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ptr[i][j] = rand() % 10;
            }
        }
    }
    Matriz2D(int n): n(n){
        ptr = new int*[n];
        for(int i = 0; i < n; i++){
            ptr[i] = new int[n];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ptr[i][j] = rand() % 10;
            }
        }
    }
    Matriz2D(const Vector3D& obj, int k){
        n = 3;
        m = k;
        ptr = new int*[n];
        for(int i = 0; i < n; i++){
            ptr[i] = new int[m];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ptr[i][j] = obj.ptr[i];
            }
        }
    }
    ~Matriz2D(){
        for(int i = 0; i < n; i++){
            delete[] ptr[i];
        }
        delete[] ptr;
        ptr = NULL;
    }
    friend ostream &print(ostream&, const Matriz2D&); 
private:
    int n;
    int m;
    int** ptr;
};

ostream &print(ostream& os, const Matriz2D& item){
    for(int i = 0; i < item.n; i++){
        for(int j = 0; j < item.m; j++){
            os << item.ptr[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

int main(){
    Vector3D obj1(1, 2, 3);
    Matriz2D obj2(obj1, 5);
    print(cout, obj2);
}