#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void random_choose(vector<string> v, int n){
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.begin()+n, [](string x){cout << x << " ";}); cout << endl;
}

int main(){
    int  i = 0;                    // variable: 1 - 13
    string figs = "CDET";
    vector<string> deck(52);

    generate(deck.begin(), deck.end(), [&](){return to_string((i++)%13+1) + figs[i/13];});
    for_each(deck.begin(), deck.end(), [](string x){cout << x << " ";}); cout << endl;

    random_choose(deck, 5);

    return 0;
}