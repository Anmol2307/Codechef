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

string x, y;
int sx, sy;
int a, b, k;

int EditDistanceRecursion(int m, int n )
{ 
    
    if( m == 0 && n == 0 )
      return 0;
 
    if( m == 0 ) {
      if (n*a <= k) return n*a;
      else return -1;
    }
 
    if( n == 0 ){
      if (m*a <= k) return m*a;
      else return -1;
    }

    int left, right, corner;
    int val1 = EditDistanceRecursion(m-1, n);
    int val2 = EditDistanceRecursion(m, n-1);
    int val3 = EditDistanceRecursion(m-1, n-1);
 
    if (val1 >= 0) left = val1 + a;
    else left = -1;

    if (val2 >= 0) right = val2 + a;
    else right = -1;
    
    if (val3 >= 0) corner = val3  + (x[m-1] != y[n-1])? b : 0;
    else corner = -1;
      
    int ret = min(left, min(right, corner));
    if (ret >= 0 && ret <= k) return ret;
    else return -1; 
}

int main () {
  int t;
  inp(t);

  while (t--) {
    cin >> x >> y;
    sx = x.size();
    sy = y.size();
    
    inp(a); inp(b); inp(k);
    int ans = EditDistanceRecursion(x.size(), y.size());
    printf("%d\n",ans);
  }
}