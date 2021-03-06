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

#define N 10005

vector <vector <int> > vec(N);
int d[N];

void dfs (int cur, int prev, int depth) {
	d[cur] = depth;

	for (int i = 0; i < vec[cur].size(); i++) {
		if (vec[cur][i] != prev) dfs(vec[cur][i],cur,depth+1);
	}
}

int main () {
	int t;
	inp(t);

	while (t--) {
		int n;
		inp(n);

		for (int i = 0; i < n + 5; i++) {
			vec[i].clear();
		}


		for (int i = 1; i < n; i++) {
			int x, y;
			inp(x); inp(y);
			vec[x].push_back(y);
			vec[y].push_back(x);
		}

		memset(d,0,sizeof(d));
		dfs(1,0,0);

		sort(d+1,d+n+1);
		// for (int i = 1; i <= n; i++) {
		// 	printf("%d %d\n",i,d[i]);
		// }
		// exit(0);
		int i = 1, j = n;
		int steps = 0;
		while (1) {
			if (i > j) break;
			steps++;
			int val = d[i];
			while (i <= j && d[i] == val) {
				i++;
			}
			// printf("Alice %d %d\n",i,steps);
			if (i > j) break;
			steps++;
			j--;
			// printf("Bob %d %d\n",j,steps);
		}

		printf("%d\n",steps);
	}
}