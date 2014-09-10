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

// BIT query and update functions
typedef long long int lli;
const int maxn = 200010;

int tree[maxn];
int n;
int read(int idx){
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
  
void update(int idx, int val){
    while(idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int main () {
  int m;
  inp(n); inp(m);
  int arr[n];
  for (int i = 0; i < n; i++) {
    inp(arr[i]);
    arr[i]++;
  }

  int ans = 0;
  for (int i = n-1; i >= 0; i--) {
    ans += read(arr[i] -1);
    update(arr[i],1);
  }
  printf("%d\n",ans);
}