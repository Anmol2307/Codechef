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

const int MAX = 100005;
vector <int> A,B[MAX],C,D;
int visited1[MAX];
int visited2[MAX];
int n,m;

void DFS1(int u) {
  visited1[u]=1;
  C.push_back(u);
  for(int i=0; i<B[u].size(); i++) {
    int current=B[u][i];
    if(visited1[current]==0)
      DFS1(current); 
  }
}

void DFS2(int u) {
  visited2[u]=1;
  D.push_back(u);
  // printf("I am here %d\n",visited2[A[u-1]]);
  while (!visited2[A[u-1]]) {
    DFS2(A[u-1]); 
  }
}


int main () {

	int t;
	inp(t);

	while(t--) {
		inp(n); inp(m);
		A.clear();

		memset(visited1,0,sizeof(visited1));
		memset(visited2,0,sizeof(visited2));

		for(int i = 1; i <= n; i++) {
			int val;
			inp(val);
			A.push_back(val);
		}

		for(int i=0; i<MAX; i++)
      		B[i].clear();

		for (int i = 0; i < m; i++) {
			int x, y;
			inp(x); inp(y);

			B[x].push_back(y);
			B[y].push_back(x);
		}
		
		bool flag = false;		
		for(int i=1; i<=n; i++) {
	      	C.clear();D.clear();
	      	if(visited1[i]==0) {
	        	DFS1(i);
	    	}
	    	if(visited2[i]==0) {
	        	DFS2(i);
	    	}
	        sort(C.begin(),C.end());
	        sort(D.begin(),D.end());

	        if (C[0] == D[0] && C[C.size()-1] == D[D.size()-1]) {
	        	continue;
	        }
	        else {
	        	flag = true;
	        	printf("Impossible\n");
	        	break;
	        }
	        // if (C.size() != D.size()) {
	        // 	printf("Impossible\n");
	        // 	flag = true;
	        // 	break;
	        // }
	        // else {
	        // 	for (int i = 0; i < C.size(); i++) {
	        // 		if (C[i] == D[i]) continue;
	        // 		else {
	        // 			flag = true;
	        // 			break;
	        // 		}
	        // 	}
	        // 	if (flag) {
	        // 		printf("Impossible\n");
	        // 		break;
	        // 	}
	        // }
    	}
    	if (!flag) printf("Possible\n");

	}
}