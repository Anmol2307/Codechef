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
  int n, m;
  inp(n); inp(m);

  int arr[n+1];

  for (int i = 1; i <= n; i++) {
    inp(arr[i]);
  }
  long long int x;
  x = 0;
  for (int i = 0; i < m; i++) {
    char ch;
    int index;
    scanf("%c %d\n",&ch,&index);
    if (ch == 'R') {
      if (x + index <= n) x += n;
      if ((x+index)%n == 0) printf("%d\n",arr[n]);
      else printf("%d\n",arr[(x+index)%n]);
      
    }
    else if (ch == 'C'){
      x += index;
    }
    else if (ch == 'A') {
      x -= index;
    }
  }
}