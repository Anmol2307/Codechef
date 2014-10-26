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
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
typedef pair< int, ll > pil;
typedef istringstream iss;
typedef ostringstream oss;
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define ln length()
#define rep(i,n) for(int i=0;i<n;i++)
#define fu(i,a,n) for(int i=a;i<=n;i++)
#define fd(i,n,a) for(int i=n;i>=a;i--)
#define all(a)  a.begin(),a.end() 
#define ESP (1e-9)
 
#define gi(n) scanf("%d",&n)
#define gl(n) cin >> n
#define pi(n) printf("%d",n)
#define pl(n) printf("%lld",n)
#define ps printf(" ")
#define pn printf("\n")
#define N 90
#define MOD 1000000007
#define mx 100005
#define mn -100005



int main () {
  int t;
  inp(t);

  while (t--) {
    int n, m;
    inp(n); inp(m);

    int arr[m];

    for (int i = 0; i < m; i++) {
      inp(arr[i]);
    }

   sort(arr,arr+m);

   if (m == 1) {
      int v = arr[0];
      for (int i = 0;i < v; i++) {
        printf("%d ",v-i);
      }
      for (int i = v;i < n; i++) {
        printf("%d ",i-v);
      }
      printf("\n");
   }
   else {
      int v1 = arr[0];
      int v2 = arr[m-1];

      for (int i = 0; i < v1; i++) {
        printf("%d ",v2-i);
      }

      for (int i = v1; i < v2; i++) {
        printf("%d ",max(i-v1,v2-i));
      }
      for (int i = v2; i < n; i++) {
        printf("%d ",i-v1);
      }
      printf("\n");
   }
  }
}