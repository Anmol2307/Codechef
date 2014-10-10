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
    string str;
    cin >> str;
    int sz = str.size();

    for(int i=sz-4;i>=0;i--){
      if(!(str[i  ]=='C' || str[i  ]=='?')) continue;
      if(!(str[i+1]=='H' || str[i+1]=='?')) continue;
      if(!(str[i+2]=='E' || str[i+2]=='?')) continue;
      if(!(str[i+3]=='F' || str[i+3]=='?')) continue;
      str[i  ] = 'C';
      str[i+1] = 'H';
      str[i+2] = 'E';
      str[i+3] = 'F';
    }

    for (int i = 0; i < sz; i++) {
      if (str[i] == '?') str[i] = 'A';
    }
    printf("%s\n",str.c_str());
  }
}