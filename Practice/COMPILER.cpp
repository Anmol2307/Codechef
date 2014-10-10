#include <iostream>

using namespace std;

int main () {
	int t;
	cin>>t;
	while (t--) {
		string str;
		cin>>str;
		int val = 0; 
		int length = 0;
		int dum = 0;
		int i;
		for (i = 0; i < str.size();i++) {
			if (str[i] == '<') val++;
			else if (str[i] == '>') val--;
			if (val < 0) {
				cout << length << endl;
				break;
			}
			length++;
			if (val == 0) dum = length;
		}
		if (i==str.size()) cout << dum << endl; 
	}
}