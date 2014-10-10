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

int main () {
  int t;
  inp(t);

  while (t--) {
    int n, m;
    inp(n); inp(m);
    int arr[n];
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
    }
    sort(arr,arr+n);
    int val = 0;
    int h = arr[n-1];
    for (int i = 0; i < n-1; i++) {
      val += h - arr[i];
    }
    if (val == m) printf("Yes\n");
    else if (val < m && (m - val)%n == 0) printf("Yes\n");
    else printf("No\n");
  }
}