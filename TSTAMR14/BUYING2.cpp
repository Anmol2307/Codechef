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
typedef pair<int,int> pii;


int main () {
  int t;
  inp(t);

  while (t--) {
    int n, x;
    inp(n); inp(x);
    int arr[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
      sum += arr[i];
    }

    sort (arr, arr+n);

    if (sum % x == 0) {
      printf("%d\n",sum/x);
    }
    else if (n == 1) {
      printf("%d\n",sum/x);
    }
    else {
      int s = arr[n-1];
      int i;
      for (i = n-2; i >= 0; i--) {
        s += arr[i];
        if (s >= x) {
          break;
        }
      }
      if (i > 0) {
        printf("-1\n");
      }
      else printf("%d\n",sum/x);
    }
  }
}