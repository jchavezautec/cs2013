//overloading operator <<
#include <iostream>

using namespace std;

class Coor{
friend ostream &operator<<(ostream &os, const Coor &item);
friend istream &operator>>(istream &is, Coor &item); 
friend Coor operator+(const Coor &item1, const Coor &item2);
friend bool operator==(const Coor &item1, const Coor &item2);
public:
    Coor() = default;
    Coor(double x, double y): x(x), y(y){}
private:
    double x;
    double y;
};

ostream &operator<<(ostream &os, const Coor &item){
    os << "(" << item.x << ", " << item.y << ")";
    return os;
}

istream &operator>>(istream &is, Coor &item){
    is >> item.x >> item.y;
    return is;
}

Coor operator+(const Coor &item1, const Coor &item2){
    Coor obj;
    obj.x = item1.x + item2.x;
    obj.y = item1.y + item2.y;
    return obj;
}

bool operator==(const Coor &item1, const Coor &item2){
    return (item1.x == item2.x) && (item1.y == item2.y);
}

int main(){
    Coor obj1(1.1, 2.2);
    Coor obj2(3.3, 4.4);

    Coor obj3 = obj1 + obj2;
    cout << obj3 << endl;
    
    Coor obj4(1.1,2.2);
    cout << (obj1 == obj4) << endl;
    cout << (obj1 == obj2) << endl;
    
    return 0;
}