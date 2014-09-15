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
typedef long long int lli;

int arr[105];
int n; 

int numSwaps () {
    int ans = 0;
    for (int j = n-1; j > 0; j--) {
      for (int i = 0; i < j; i++) {
        if (arr[i] > arr[i+1]) ans++;
      }
    }
    return ans;
}

double val[101];

void pre () {
  val[1] = 0;
  for (int i = 2; i <= 100; i++) {
    val[i] = val[i-1] + (double)(i-1)/(double)2;
  }
}

int main () {
  int t;
  inp(t);
  pre();
  while (t--) {
    inp(n);
    lli k; scanf("%lli",&k);
    
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
    }
    int count = numSwaps();
    if (k >= count) {
      printf("%.6lf\n",0.0);
    }
    else {
      printf("%.6lf\n",val[n]);
    }
  }
}