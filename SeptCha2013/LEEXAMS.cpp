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

double dp[51][1<<16];

int main () {
	int t;
	inp(t);

	while (t--) {
		int n;
		inp(n);
		int P[n], A[n], B[n];
		
		for (int i = 0; i < n; i++) {
			inp(P[i]);inp(A[i]);inp(B[i]);
		}

		memset(dp,0,sizeof(dp));
		
		dp[0][1<<(A[0]-1)] = (double)P[0]/(double)100;
		dp[0][1<<(B[0]-1)] = (double)(100-P[0])/(double)100;
		

		int index = 1<<16;
		for (int i = 1; i < n; i++) {
			double val = 0;
			for (int j = 1; j < index; j++) {
				if (dp[i-1][j] != 0 && (((1 << (A[i]-1)) & j) == 0)) {
					// val = (double)dp[i-1][j]*(double)P[i]/(double)100;
					dp[i][j + (1 << (A[i]-1))] += (double)dp[i-1][j]*(double)P[i]/(double)100;
				}
				if (dp[i-1][j] != 0 && (((1 << (B[i]-1)) & j) == 0)) {
					// val = (double)dp[i-1][j]*(double)(100-P[i])/(double)100;
					dp[i][j + (1 << (B[i]-1))] += (double)dp[i-1][j]*(double)(100-P[i])/(double)100;
				}
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 1; j < 8; j++) {
		// 		printf("%lf ",dp[i][j]);
		// 	}
		// 	printf("\n");
		// }

		double ans = 0;
		for (int i = 1; i < index; i++) {
			if (dp[n-1][i] != 0){
				ans += (double)dp[n-1][i];
			}
		}
		printf("%.9lf\n",ans);

	}
}