#include <iostream>

using namespace std;

int main () {

	long long int x;
	cin>>x;
	if (x%6 == 0 || x%6 == 1 || x%6 == 3) cout << "yes" <<endl;
	else cout << "no"<<endl;
}