#include <iostream>

using namespace std;

class printString{
private:
    char _end;
public:
    printString(char c = ' '): _end(c) {}
    void operator() (string s){
        cout << s << _end;
    }
};

#include <algorithm>

int main(){
    string v[4] = {"Hola","Mundo","en","C++"};

    for_each(v, v+4, printString('\n'));

    return 0;
}

