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

#define MOD 1000000007
#define i64 long long

int power(int a,int k){
    if(k == 0) return 1;
    int ret = power(a,k/2);
    ret = (ret*(i64)ret) % MOD;
    if(k & 1){
        ret = (a*(i64)ret) % MOD;
    }
    return ret;
}

int main () {

	int t;
	inp(t);

	while (t--) {
		int n;
		inp(n);

		int arr[n];

		for (int i = 0; i < n; i++) {
			inp(arr[i]);
		}

		int ans = 0;
		for (int d = -99; d < 100; d++) {

			int sum[101];
			memset(sum,0,sizeof(sum));
			int dp[n];
			for (int i = 0; i < n; i++) {
				dp[i] = 1;
			}

			int cur = 0;	
			for (int j = 0; j < n; j++) {
				if (arr[j] - d >= 1 && arr[j] - d <= 100) {
					dp[j] = (sum[arr[j] - d] + 1)%MOD;
				}
				sum[arr[j]] = (sum[arr[j]] + dp[j])%MOD;
				cur = (cur + dp[j])%MOD;
			}
			ans = (ans + cur)%MOD;
			ans -= n;	
			ans = (ans + MOD)%MOD;
		}

		ans = (ans + n)%MOD;
		ans = power(2,n) - 1 - ans;
		ans = (ans + MOD)%MOD;
		printf("%d\n",ans);
	}
}