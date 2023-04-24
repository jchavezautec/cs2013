#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibonacci(int n){
    if(n<=2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    transform(v.begin(), v.end(), v.begin(), fibonacci);
    for_each(v.begin(), v.end(), [](int x){cout << x << " ";});
    cout << "\n---------------------------------\n";
}