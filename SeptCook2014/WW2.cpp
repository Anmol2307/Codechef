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

#define MOD 1000000007
#define rep(i,b) for(int i=0;i<b;i++)
typedef long long int lli;
typedef vector <vector <lli> > matrix;
matrix I;

matrix multiply(matrix A, matrix B)
{
    int K=(int)A.size();
    matrix C(K, vector<lli>(K));
    rep(i, K) rep(j, K) rep(k, K)
    {
        C[i][j] = C[i][j] + (A[i][k] * B[k][j]) % MOD;
        if(C[i][j]>=MOD)
            C[i][j]-=MOD;
    }
    return C;
}

//find N'th power of matrix T 
matrix mpow(matrix T, lli N)
{
    if(N==0)return I;
    if(N==1)return T;
    matrix ret=mpow(T,N/2);
    matrix ret1=multiply(ret,ret);
    if(N%2==0)return ret1;
    else return multiply(ret1,T);
}

int main () {
  int t;
  inp(t);
  while (t--) {
    lli n, m;
    scanf("%lli %lli", &n, &m);
    matrix even(m,vector<lli>(m));
    matrix odd(m,vector<lli>(m));


    I.resize(m);

    for (int i = 0; i < m; i++) {
      I[i].resize(m);
      I[i][i] = 1;
    }

    for (int i = 0; i < m; i++) {
      even[i][i] = 1;
      if (i >= 1) {
        even[i][i-1] = 1;
        odd[i][i-1] = 1;
      }
      if (i + 1  < m) {
        even[i][i+1] = 1;
        odd[i][i+1] = 1;
      }
    }
    
    n -= 1;
    matrix mult = multiply(odd,even);
    
    matrix ans = mpow(mult,n/2);

    if (n%2 == 1) {
      ans = multiply(ans,odd);
    }


    lli val = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        val = (val + ans[i][j]) % MOD;
      }
    }
    
    printf("%lli\n",val);
  }
}