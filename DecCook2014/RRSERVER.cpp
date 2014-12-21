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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 222222


int main () {
  int n, m;
  inp(n); inp(m);

  vector<int> graph[n+1];
  for (int i = 0; i < m; i++) {
    int x, y;
    inp(x); inp(y);
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  int visited[n+1];
  memset(visited,0,sizeof visited);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      queue<int> q;
      q.push(i);
      int tmp = 0;
      while (!q.empty()) {
        int top = q.front();
        q.pop();
        visited[top] = 1;
        tmp++;
        for (int j = 0; j < graph[top].size(); j++) {
          if (visited[graph[top][j]] == 0) {
            q.push(graph[top][j]);
          }
        }
      }
      ans += tmp-1;
    }
  }
  printf("%d\n",ans);
}