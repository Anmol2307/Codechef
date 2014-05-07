#include <iostream>
#include <limits>

using namespace std;

int main () {
	int n, k;
	cin>> n >> k;
	long long int arr[n];
	long long int odd[n];
	long long int even[n];
	long long int max = numeric_limits<int>::min();
	long long int min = numeric_limits<int>::max();
	for (int i = 0 ;i < n; i++) {
		cin>>arr[i];
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	for (int i = 0; i < n; i++) {
		odd[i] = max - arr[i]; 
	}
	for (int i = 0; i < n; i++) {
		even[i] = max - min - odd[i]; 
	}
	if (k%2) {
		for (int i = 0; i < n; i++) {
			cout << odd[i] << " ";
		}
		cout << endl;
	}
	else {
		if (k!= 0) {
			for (int i = 0; i < n; i++) {
				cout << even[i] << " ";
			}
			cout << endl;
		}
		else {
			for (int i = 0; i < n; i++) {
				cout << arr[i] << " ";
			}
			cout << endl;
		}
	}

}