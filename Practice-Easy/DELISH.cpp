#include <bits/stdc++.h>

using namespace std;

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}



int main () {

	int t;
	inp(t);

	while (t--) {
		int n;
		inp(n);

		int arr[n+1];

		for (int i = 1; i <= n; i++) {
			inp(arr[i]);
		}

		long long int max_end = arr[1], max_total = arr[1];

		for (int i = 2; i <= n; i++) {
			max_end = max(arr[i],max_end+arr[i]);
			max_total = max(max_end, max_total);
		}

		printf("%lli\n",max_total);
	}
}