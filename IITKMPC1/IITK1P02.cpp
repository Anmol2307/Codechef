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
  string str;
  getline(cin, str);

  int sz = str.size();
  map<char, int> m;
  int count = 0;
  for (int i = 0; i < sz; i++) {
    char ch = str[i];
    int j = i;
    while (j < sz && str[j] == ch) j++;
    if (m.find(ch) != m.end() && m[ch] < (j-i)) m[ch] = j-i;
    else m.insert(pair<char,int>(ch,j-i));
  }

  map<char, int>::iterator it;
  // for (it = m.begin(); it != m.end(); it++) {
  //   printf("%c %d\n",it->first, it->second);
  // }
  int ma = -1;
  char mc = 'z';
  for (it = m.begin(); it != m.end(); it++) {
    if (it->second > ma) {
      ma = it->second;
      mc = it->first;
    }
    else if (it->second == ma && it->first < mc) {
      mc = it->first;
    }
  }

  printf("%c\n%d\n",mc,ma);
}