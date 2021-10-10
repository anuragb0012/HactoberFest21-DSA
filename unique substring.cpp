//Print all unique substrings in a string.
#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	set<string> uniquesubstrings;
	
	string tp;
	
	for (int i = 0; i < s.size(); i++) {
	    tp = "";
	    for(int j = i; j < s.size(); j++){
	        tp += s[j];
	        uniquesubstrings.insert(tp);
	    }
	}
	
	for(auto j:uniquesubstrings){
	    cout << j << " ";
	}
	
	cout << endl;
	
	return 0;
}
