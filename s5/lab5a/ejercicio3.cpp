#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void choose_five(vector<string> A){
    random_shuffle(A.begin(), A.end());
    for_each(A.begin(), A.begin()+5, [](string s){cout << s << " ";}); 
    cout << endl;
}
int main(){
    string figs = "CDET";
    vector<string> deck(52);

    int i = -1;
    generate(deck.begin(), deck.end(), [&](){
        i++;
        return to_string(i%13+1) + figs[i/13];
    });
    for_each(deck.begin(), deck.end(), 
        [](string s){cout << s << " ";}); cout << endl;

    cout << "5 cartas al azar: ";
    choose_five(deck);
}