#include <iostream>
#include <list>
#include <algorithm>

using namespace std;


void bubbleSort(list<int>::iterator begin, list<int>::iterator end){
    for (auto i = begin; i != end; i++)
        for (auto j = i; j != end; j++)
            if (*i > *j)
                swap(*i,*j);
}

int main(){
    list<int> l;
    generate_n(front_inserter(l), 10, [](){return rand()%10;});
    
    for_each(l.begin(), l.end(), [](int x){cout << x << " ";});
    cout << endl;

    bubbleSort(l.begin(), l.end());
    for_each(l.begin(), l.end(), [](int x){cout << x << " ";});
    cout << endl;

    return 0;
}