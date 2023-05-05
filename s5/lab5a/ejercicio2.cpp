#include <iostream>
#include <algorithm>

using namespace std;

struct CAfin{
    int _a, _b;
    CAfin(int a, int b): _a(a), _b(b){}
    char operator()(char c){
        return (_a * (c - 'A') + _b) % 26 + 'A';
    }
};

int main(){
    CAfin cifrar(5, 8);         // c = (ax+b)%26 = (5x+8)%26          
    //cout << "Original: " << s << endl;
    
    //transform(s.begin(), s.end(), s.begin(), cifrar);
    //cout << "Cifrado: " << s << endl;

    string c = "EVAVAUINCLAKECZWCVCRIUZIKECLWQFWIUESEIPZA";
    string alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cout << "Cifrado: " << c << endl;
    
    for(int i=0; i<c.length()  ; i++){
        for(int j=0; j<alf.length(); j++){
            if (c[i] == cifrar(alf[j])){
                cout << alf[j];
            }
        }
    }
    cout << endl;
    return 0;
}