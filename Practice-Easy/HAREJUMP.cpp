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

typedef unsigned long long llu;
#define MOD 1000000007

int k;
vector <llu> vec;
map<llu,llu> mymap;


llu findWays(llu n) {
	if (n == 0) return 0;
	if (mymap.find(n) != mymap.end()) return mymap[n];
	if (k == 1 && n % vec[0] == 0) return 1;
	else if (k == 1) return 0;
	
	llu ans = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < k; i++) {
		if (vec[i] < n) ans = (ans + findWays(n-vec[i]))%MOD;
		if (vec[i] == n) ans = (ans + 1)%MOD;
	}
	mymap.insert(pair<llu,llu>(n,ans));
	return ans;
}

int main () {

	int t;
	inp(t);

	while (t--) {
		vec.clear();
		mymap.clear();

		llu n;
		scanf("%llu",&n);
		inp(k);
		
		for (int i = 0; i < k; i++) {
			llu x;
			scanf("%llu",&x);
			vec.push_back(x);
		}

		printf("%llu\n",findWays(n));
	}
}