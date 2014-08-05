#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <cctype>
#include <list>
#include <stack>
#include <fstream>
#include <utility>
#include <iomanip>
#include <climits>

using namespace std;
#define pb push_back
#define all(s) s.begin(),s.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define F(i,a,b) for(int i=a;i>=b;i--)
#define PI 3.1415926535897932384626433832795
#define BIG_INF 7000000000000000000LL
#define mp make_pair
#define eps 1e-9
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define mod 1000000007
#define mm 10000000
#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define EPS 1e-9
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)


typedef long long int LL;

string inttostring(int n)
{
  stringstream a;
  a<<n;
  string A;
  a>>A;
  return A;
}

int stringtoint(string A)
{
  stringstream a;
  a<<A;
  int p;
  a>>p;
  return p;
}

inline void inp(int &n ) {//fast input function
    n=0;
    int ch=getchar(),sign=1;
    while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar();}
    while( ch >= '0' && ch <= '9' )
        n=(n<<3)+(n<<1)+ ch-'0', ch=getchar();
    n=n*sign;
}

///////////////////////////////////////////////////////////////////////////////////////////


int main () {
  int n, m;
  inp(n); inp(m);
  // vector<vector<int> > dirEdges(n+1);
  // vector<vector<int> > undirEdges(n+1);
  vector<vector <pair <int,int> > > edges(n+1);

  for (int i = 0; i < m; i++) {
    int x;
    int y;
    inp(x); inp(y);
    // dirEdges[x].push_back(y);
    // undirEdges[x].push_back(y);
    // undirEdges[y].push_back(x);
    pair <int,int> p(y,1);
    // printf("HERE\n");
    // exit(0);
    
    edges[x].push_back(p);
    p.first = x; p.second = -1;
    edges[y].push_back(p);
    
  }

  int dp[n+1];
  for (int i = 1; i<=n; i++) {
    dp[i] = 1000000;
  }
  dp[1]=0;

  queue <int> q;
  q.push(1);
  
  int visited[n+1];
  for (int i = 1; i <=n ; i++) {
    visited[i] = 0;
  }
  while (!q.empty()) {
    int vertex = q.front();
    q.pop();
    visited[vertex] = 1;
    // printf("%d\n",vertex);
    
    // vector <int> neigh = undirEdges[vertex];
    // vector <int> vec = dirEdges[vertex];
    vector<pair<int,int> > vec = edges[vertex];

    for (int j = 0; j < vec.size(); j++) {
      pair<int,int> neighbour = vec[j];
      if (!visited[neighbour.first]) { 
        // if (find(vec.begin(), vec.end(),neighbour) != vec.end()) {
        //   dp[neighbour] = dp[vertex];
        // }
        // else {
        //   dp[neighbour] = min(dp[vertex] + 1,dp[neighbour]);
        // }
        if (neighbour.second == 1) dp[neighbour.first] = dp[vertex];
        else {
          dp[neighbour.first] = min(dp[vertex] + 1,dp[neighbour.first]);
        }
        // printf("%d %d\n",vertex,dp[neighbour.first]);
        q.push(neighbour.first);
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   printf("%d ",dp[i]);
  // }
  // printf("\n");
  printf("%d\n",dp[n]);
}