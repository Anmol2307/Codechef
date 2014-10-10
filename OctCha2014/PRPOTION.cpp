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
int arr[3];

int findmax () {
  if (arr[0] < arr[1]) {
    if (arr[1] < arr[2]) return 2;
    else return 1;
  }
  else {
    if (arr[0] > arr[2]) return 0;
    else return 2;
  }
}

int main () {
  int t;
  inp(t);

  while (t--) {
    int r, g, b, m;
    inp(r); inp(g); inp(b); inp(m);
    int ma = -1;
    for (int i = 0; i < r; i++) {
      int x; inp(x);
      if (x > ma) ma = x;
    }
    arr[0] = ma;

    ma = -1;
    for (int i = 0; i < g; i++) {
      int x; inp(x);
      if (x > ma) ma = x;
    }
    arr[1] = ma;

    ma = -1;
    for (int i = 0; i < b; i++) {
      int x; inp(x);
      if (x > ma) ma = x;
    }
    arr[2] = ma;
    
    int ind = findmax();

    for (int i = 0; i < m; i++) {
      arr[ind] /= 2;
      ind = findmax();
    }
    printf("%d\n",arr[ind]);
  }
}