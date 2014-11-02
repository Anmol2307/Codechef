#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <stack>
#include <vector>
#include <map>
#include <list>
#include <queue>
#define lli long long int
#define ii pair<int,int>

#define mod 1000000009
#define inf 999999999

using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int t,n,m;
int A[100][100],dp[100][100],ans;

ii B[4];

int dx[]={1,1,-1,-1};
int dy[]={1,-1,1,-1};

bool check(int x,int y) {
	if(x<0 || y<0 || x>=n || y>=m)
		return false;
	return true;
}

int main() {
	inp(t);

	while(t--) {
		inp(n);
		inp(m);

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				inp(A[i][j]);

		ans=A[0][0]+A[0][1]+A[1][0]+A[1][1];

		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int val=A[i][j];

				for(int k=1;;k++) {
					bool ok=true;
					for(int a=0;a<4;a++) {
						int x=i+k*dx[a];
						int y=j+k*dy[a];

						if(!check(x,y)) {
							ok=false;
							break;
						}
						val+=A[x][y];
					}
					if(!ok)
						break;
					// if(i==1 && j==1)
					// 	cout<<val<<" ff\n";
					ans=max(ans,val);
				}

				val=0;
				B[3]=ii(i,j);
				B[1]=ii(i+1,j);
				B[2]=ii(i,j+1);
				B[0]=ii(i+1,j+1);

				for(int k=0;;k++) {
					bool ok=true;
					for(int a=0;a<4;a++) {
						int x=B[a].first+k*dx[a];
						int y=B[a].second+k*dy[a];
						if(!check(x,y)) {
							ok=false;
							break;
						}
						val+=A[x][y];
					}
					if(!ok)
						break;
					ans=max(ans,val);
				}
			}
		}


		printf("%d\n", ans);

	}

	return 0;
}