#include <iostream>
#include <map>
#include <set>

using namespace std;
	
int main(){
	map<string, int> word_count;
	string word;

    set<string> stop_words = {"en","y"};

	while (getline(cin,word)){
		if (word.begin()==word.end())
			break;
        if (stop_words.find(word) == stop_words.end())
		    word_count[word]++;
	}

	for (const auto &w: word_count){
		cout << w.first << ": ";
		cout << w.second;
	    cout << (w.second > 1 ? " veces": " vez") << endl;
	}

	return 0;
}