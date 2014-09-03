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

int gcd(int a, int b) {
  while(b) b ^= a ^= b ^= a %= b;
  return a;
}

int find (int a, int b, int c) {
  int moves = 1, A=a, B=0, pour;
  while (A != c && B != c) {
    pour = min(A,b-B);
    A -= pour;
    B += pour;
    moves++;
    if (A==c || B==c) break;
    if (A== 0) {
      A= a;
      moves++;
    }
    else if (B= b) {
      B= 0;
      moves++;
    }
  }
  return moves;
}

int main () {
  int t;
  inp(t);

  while (t--) {
    int a, b, c;
    inp(a); inp(b); inp(c);
    if (c > max(a,b)) printf("%d\n",-1);
    else if (c==0) printf("%d\n",0);
    else if (c==a || c==b) printf("%d\n",1);
    else if (c%gcd(a,b) != 0) printf("%d\n",-1);
    else printf("%d\n",min(find(a,b,c), find(b,a,c))); 
  }
}                                                                                                                                                                                                                                                                                                                                                                                                                                           