#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	vector<int> nums(100);
    map<int, int> hist;

    generate(nums.begin(), nums.end(), [](){return rand()%21;});
    for_each(nums.begin(), nums.end(), [](int x){cout << x << " ";});
    cout << endl;

    for (auto it = nums.begin(); it!=nums.end();  it++)
        hist[*it]++;

    map<int,int>::iterator it = hist.begin();
    pair<int, int> max_pair = {(*it).first, (*it).second};

    for (auto pair: hist){
        if (pair.second > max_pair.second)
            max_pair.second = pair.second;
            max_pair.first = pair.first;
    }

    cout << "Moda: " << max_pair.first;
    cout <<", con " << max_pair.second << " rep." << endl;

	return 0;
}
