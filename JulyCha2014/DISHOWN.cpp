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
 
 
 
 
 
typedef long long LL;
 
 
 
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
 
 
 
const int maxn = 10003;
 
int rank[maxn];
 
int p[maxn];
 
// int n;
 
int arr[maxn];
 
 
 
 
 
// Create Set 
 
void createSet(int _n) {
 
  int n = _n;
 
  // fill(rank, rank + n+1, 0);
 
    for (int i = 1; i <= n; i++) {
 
        p[i] = i;
 
        rank[i]=arr[i];
 
    }
 
}
 
 
 
int findSet(int x) {
 
    if (x != p[x]) p[x] = findSet(p[x]);
 
    return p[x];
 
}
 
// int findRank(int x) {
 
//     if (x != rank[x]) rank[x] = findRank(rank[x]);
 
//     return rank[x];
 
// }
 
 
 
void mergeSets(int x, int y) {
 
    int PX = findSet(x);
 
    int PY = findSet(y);
 
    if (PX == PY) printf("%s\n", "Invalid query!");
 
    // if (arr[x] > arr[y]) p[PY]=PX;
 
    // else if (arr[x] < arr[y]) p[PX]=PY;
 
    // int RX = findRank(arr[PX]);
 
    // int RY = findRank(arr[PY]);
 
    int RX = rank[PX];
 
    int RY = rank[PY];
 
    if (RX > RY) {
 
        p[PY] = PX;
 
        rank[PY] = rank[PX];
 
    }
 
    else if (RX < RY) {
 
        p[PX] = PY;
 
        rank[PX] = rank[PY];
 
    }
 
    // if (rank[PX] == rank[PY]) rank[PY] = rank[PY] + 1;
 
}
 
 
 
 
 
// int root(int x) {
 
//   return x == p[x] ? x : (p[x] = root(p[x]));
 
// }
 
 
 
// void unite(int a, int b) {
 
//   a = root(a);
 
//   b = root(b);
 
//   if (a == b) return;
 
//   if (Rank[a] < Rank[b]) swap(a, b);
 
//   if (Rank[a] == Rank[b]) ++Rank[a];
 
//   p[b] = a;
 
// }
 
 
 
int main () {
 
    int t;
 
    inp(t);
 
 
 
    while (t--) {
 
        int n;
 
        inp(n);
 
        
 
        // int arr[n+1];
 
        for (int i =1;i <= n;i++) {
 
            inp(arr[i]);
 
        }
 
        createSet(n);
 
        int m;
 
        inp(m);
 
 
 
        while (m--) {
 
            int q, x, y;
 
            inp(q);
 
 
 
            if (q==0) {
 
                inp(x);inp(y);
 
                mergeSets(x,y);
 
            }
 
            else if (q==1) {
 
                inp(x);
 
                printf("%d\n",findSet(x));
 
            }
 
        }
 
    }
 
} 
