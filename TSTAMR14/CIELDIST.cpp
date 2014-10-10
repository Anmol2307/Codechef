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
    int ds, dt, d;
    inp(ds); inp(dt); inp(d);
    if (ds + dt >= d && ds + d >= dt && dt + d >= ds) printf("0\n");
    else if (ds + dt < d) {
      printf("%d\n",d-ds-dt);
    }
    else if (ds + d < dt) {
      printf("%d\n",dt - d - ds);
    }
    else if (dt + d < ds){
      printf("%d\n",ds - d - dt); 
    }
  }
}