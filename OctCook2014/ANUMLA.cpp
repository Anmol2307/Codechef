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
    int n;
    inp(n);

    int end = 1<<n;
    int arr[end];
    int sums[end];
    int ans[n];
    multiset<int> s;
    for (int i = 0; i < end; i++) {
      inp(arr[i]);
    }

    sort(arr,arr+end);
    int j = 0, k = 0;
    for (int i = 1; i < end; i++) {
      int val = -1;

      if (!s.empty()) val = *(s.begin());

      if (arr[i] == val) {
        s.erase(s.begin());
      }
      else {
        ans[j] = arr[i];
        int tmp = k;
        for (int l = 0; l < tmp; l++) {
          sums[k++] = sums[l] + ans[j];
          s.insert(sums[k-1]);
        }
        sums[k++] = ans[j++];
      }
    }

    for (int i = 0; i < j; i++) {
      printf("%d ",ans[i]);
    }
    printf("\n");
  }
}