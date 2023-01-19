#include <iostream>

using namespace std;

template<class...Ts>
float suma_alternada(Ts... args){
    return (args-...);
}

/*
 args-... = arg1-(arg2-(arg3-(arg4-(arg5))))
          = arg1-arg2+arg3-arg4+arg5

 args-... = arg1-arg2-arg3-arg4-arg5 (INCORRECTO)
*/

int main(){
    cout << suma_alternada(1) << endl;
    cout << suma_alternada(3,4) << endl; 
    cout << suma_alternada(1,2,3,4,5) << endl;
    cout << suma_alternada(3,3,2,1,0) << endl;
    return 0;
}