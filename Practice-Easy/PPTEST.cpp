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

bool pairCompare(const pair<int, int>& firstElem, const pair<int, int>& secondElem) {
  if (firstElem.first < secondElem.first) return true;
  else if (firstElem.first == secondElem.first) return firstElem.second > secondElem.second;
  else return false;
}

int main () {
	int t;
	inp(t);

	while (t--) {
		int n, w;
		inp(n); inp(w);

		pair <int ,int> vt[n+1];
		
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			inp(x); inp(y); inp(z);
			pair<int,int> p(x*y,z);
			vt[i] = p;
		}

		sort (vt+1, vt+n+1,pairCompare);
		// for (int i = 1; i <= n; i++) {
		// 	printf("%d %d\n",vt[i].first, vt[i].second);
		// }
		int dp[n+1][w+1];
		memset(dp,0,sizeof(dp));

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= w; j++) {
				if (vt[i].second <= j) dp[i][j] = max(dp[i-1][j-vt[i].second] + vt[i].first, dp[i-1][j]);
				else dp[i][j] = dp[i-1][j];
			}
		}

		// for (int i = 1; i <= n; i++) {
		// 	for (int j = 1; j <= w; j++) {
		// 		printf("%d ",dp[i][j]);
		// 	}
		// 	printf("\n");
		// }

		printf("%d\n",dp[n][w]);
	}
}