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
#include <iterator>

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

string* arr;
int* tree;
int n;


void build_tree(int node, int a, int b) {
    if(a > b) return;
    
    if(a == b) {
      tree[node] =  stringtoint(arr[a]);
      return;
    }
  
  build_tree(node*2, a, (a+b)/2);
  build_tree(node*2+1, 1+(a+b)/2, b);
  
  tree[node] = max(tree[node*2], tree[node*2+1]);
}

void update_tree(int node, int a, int b, int i, int j, int val) {
    

  if(a > b || a > j || b < i) 
    return;
    
    if(a == b) {
        string s = arr[a];
        // if (val == 2) printf("HERE %s\n",s.c_str());
        rotate(s.begin(), s.begin()+val, s.end());
        // if (val == 2) printf("HERE %s\n",s.c_str());
        tree[node] = stringtoint(s);
        arr[a] = s;
        return;
    }
 
  update_tree(node*2, a, (a+b)/2, i, j,val); // Updating left child
  update_tree(1+node*2, 1+(a+b)/2, b, i, j,val); // Updating right child
 
  tree[node] = max(tree[node*2],tree[node*2+1]); // Updating root with max value
}

// void update_tree_lazy(int node, int a, int b, int i, int j) {
  
//     if(lazy[node] != 0) { // This node needs to be updated
//       tree[node] += lazy[node]; // Update it
 
//     if(a != b) {
//       lazy[node*2] += lazy[node]; // Mark child as lazy
//         lazy[node*2+1] += lazy[node]; // Mark child as lazy
//     }
 
//       lazy[node] = 0; // Reset it
//     }
  
//   if(a > b || a > j || b < i) // Current segment is not within range [i, j]
//     return;
//     long long value = sqrt(tree[node]);
//     if(a >= i && b <= j) { // Segment is fully within range
//         tree[node] = value;
 
//     if(a != b) { // Not leaf node
//       lazy[node*2] = value;
//       lazy[node*2+1] = value;
//     }
 
//         return;
//   }
 
//   update_tree(node*2, a, (a+b)/2, i, j); // Updating left child
//   update_tree(1+node*2, 1+(a+b)/2, b, i, j); // Updating right child
 
//   tree[node] = tree[node*2] + tree[node*2+1]; // Updating root with max value
// }

int query_tree(int node, int a, int b, int i, int j) {
  
  if (a==i && b==j) return tree[node];
  int mid = (a+b)/2;
    if (j <= mid) {
        return query_tree((node<<1), a, mid, i, j);
    }
    if (i > mid) {
        return query_tree((node<<1) + 1, mid+1,b,i,j);
    }
    int l = query_tree((node<<1), a, mid, i, mid);
    int r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
    return max(l,r);

}

// int query_tree_lazy(int node, int a, int b, int i, int j) {
  
//   if(a > b || a > j || b < i) return 0; // Out of range
 
//   if(lazy[node] != 0) { // This node needs to be updated
//     tree[node] += lazy[node]; // Update it
 
//     if(a != b) {
//       lazy[node*2] += lazy[node]; // Mark child as lazy
//       lazy[node*2+1] += lazy[node]; // Mark child as lazy
//     }
 
//     lazy[node] = 0; // Reset it
//   }
 
//   if(a >= i && b <= j) // Current segment is totally within range [i, j]
//     return tree[node];

//   int mid = (a+b)/2;
//     if (j <= mid) {
//         return query_tree((node<<1), a, mid, i, j);
//     }
//     if (i > mid) {
//         return query_tree((node<<1) + 1, mid+1,b,i,j);
//     }
//     long long l = query_tree((node<<1), a, mid, i, mid);
//     long long r = query_tree((node<<1) + 1, mid+1,b ,mid+1,j);
//     return l+r;
// }



int main () {
  inp(n);
  arr = new string[n+1];
  tree = new int[2*n+2];

  char A[10];
  for (int i = 0; i < n ; i++) {
    scanf("%s",A);
    arr[i] = A;
  }

  build_tree(1, 0, n-1);
  int m;
  inp(m);

  for (int i = 0; i < m; i++) {
    int x;
    inp(x);

    if (x==0) {
      int L, R, H;
      inp(L); inp(R); inp(H);
      // Update Tree here
      update_tree(1,0,n-1,L,R,H);

    }
    else if (x==1) {
      int L, R;
      inp(L); inp(R);
      // Query Tree here
      printf("%d\n",query_tree(1, 0, n-1, L, R));
    }
  }
} 