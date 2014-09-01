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

vector <int> dist;
vector <int> fuel;
int n;
long long int dp[1005];
		

void findWays() {
	dp[0] = 0;
	for (int i = 1; i <= 1000; i++) {
		dp[i] = INT_MAX;
	}

	for (int i = 1; i <= 1000; i++) {
		for (int j = 0; j < n; j++) {
			if (fuel[j] <= i) dp[i] = min(1 + dp[i-fuel[j]], dp[i]);
		}
	}
}

int main () {
	int t;
	inp(t);

	while (t--) {
		inp(n);
		dist.clear();
		fuel.clear();		
		for (int i = 0; i < n; i++) {
			int x;
			inp(x);
			dist.push_back(2*x);
		}

		for (int i = 0; i < n; i++) {
			int x;
			inp(x);
			fuel.push_back(x);
		}

		sort (fuel.begin(), fuel.end());
		findWays();
		long long int ans = 0;
		for (int i = 0; i < n; i++) {
			// printf("%d %d\n",dist[i],dp[dist[i]])	;
			ans += dp[dist[i]];	
		}

		printf("%lli\n",ans);
	}
} 