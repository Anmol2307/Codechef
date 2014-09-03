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
  long long int n,m,k;
  scanf("%lli %lli %lli",&n,&m,&k);
  long long int sum = 0;
  vector <pair <long long int,long long int> > vec;
  for (int i = 0 ; i < k; i++) {
    long long int tk, ck;
    scanf("%lli %lli",&tk,&ck);
    sum += tk;
    vec.push_back(pair<int,int>(ck,tk));
  }
  long long int val = n*m;
  // printf("%lli\n",sum);
  // exit(0);
  if (sum < val) {
    printf("%s\n","Impossible");
  }
  else {
    sort (vec.begin(),vec.end());
    int i = 0;
    long long int ans = 0;
    while (val > 0 && val >= vec[i].second){
      val -= vec[i].second;
      ans += vec[i].second*vec[i].first;
      i++;
    }
    ans += val*vec[i].first;
    printf("%lli\n",ans);
  }
}