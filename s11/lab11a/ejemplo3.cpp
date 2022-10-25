#include <iostream>

using namespace std;

class Singleton
{
    private:
        int _data;
        static Singleton* _inst;
        Singleton(int data) {
            this->_data = data;
        }
 
    public:
        static Singleton* getInstance(int data);    
        int getData(){
            return _data;
        }
};

Singleton* Singleton::_inst = NULL;
Singleton* Singleton::getInstance(int data){
    if (_inst == NULL)
        _inst = new Singleton(data);
    return _inst;
}

int main(){
    Singleton *ptr1 = Singleton::getInstance(7);
    cout << "data = " << ptr1->getData() << endl;

    Singleton *ptr2 = Singleton::getInstance(3);
    cout << "data = " << ptr2->getData() << endl;

    return 0;
}

