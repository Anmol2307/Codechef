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
typedef long long int lli;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vii;
typedef priority_queue<pii, vpii, greater<pii> > pqii;

#define INF (1<<30)
#define N 1000001



int main () {
  int t;
  inp(t);

  while (t--) {
    int n;
    inp(n);
    int arr[n];
    int ma = -1;
    for (int i = 0; i < n; i++) {
      inp(arr[i]);
      if (arr[i] > ma) ma = arr[i];
    }
    printf("%d\n",ma);
  }
}