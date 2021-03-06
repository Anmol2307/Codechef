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
#define MAX 50005
vector <int> graph[MAX];
int draught[MAX];
bool visited[MAX];
bool newvisited[MAX];
int sum[MAX];
int parent[MAX];
int n, m;
long long int size;
int baap;

void dfs (int i) {
	visited[i] = true;
	sum[i] = draught[i];
	if (draught[i] == 1) size++;
	for(int j = 0; j < graph[i].size(); j++) {
		int val = graph[i][j];
		if (visited[val]) continue;
		parent[val] = i;
		dfs(val);
		sum[i] += sum[val];
	}
}

int check () {

	queue<int> q;
	q.push(baap);
	int ans = 0;

	while (q.size()) {
		int node = q.front();
		q.pop();
		newvisited[node] = true;
		int x = 0;
		for (int i = 0; i < graph[node].size(); i++) {
			int val = graph[node][i];
			if (!newvisited[val]) {
				q.push(val);
				if (sum[val] > 0) x++;
			}
		}
		if (sum[node] > 0 && sum[node] < sum[baap]) ans++;
		else if (draught[node] == 1 && sum[node] > 1) ans++;
		else if (x >= 2) ans++;
	}
	return ans;
}


int main () {

	inp(n); inp(m);

	for (int i = 1; i <= n; i++) {
		inp(draught[i]);
	}

	for (int i = 1; i <= m; i++) {
		int x, y;
		inp(x); inp(y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	long long int pairs = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			size = 0;
			baap = i;
			dfs(i);
			pairs += (size * (size -1))/2; 
			ans += check();
			
		}
	}
	printf("%lli %d\n",pairs,ans);
	// for (int i = 1; i <= n; i++) {
	// 	printf("%d ",sum[i]);
	// }
	// printf("\n");
}