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

lli tree[2100000];
lli n;

lli read(lli idx){
    lli sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
  
void update(lli idx, lli val){
    while(idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}


int main () {
  lli m, c;
  scanf("%lli",&n); scanf("%lli",&m); scanf("%lli\n",&c);

  for (int i = 0; i < m; i++) {
    char ch;
    scanf("%c",&ch);
    if (ch == 'Q') {
      lli x; scanf("%lli\n",&x);
      lli ans = read(x);
      printf("%lli\n",ans + c);
    }
    else if (ch == 'S') {
      lli x, y, z;
      scanf("%lli",&x); scanf("%lli",&y); scanf("%lli\n",&z);
      update(x,z);
      update(y+1,-z);
    }
  }
}