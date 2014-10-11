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

bool ispalindrome (string str) {
  int sz = str.size();
  for (int i = 0; i < sz/2; i++) {
    if (str[i] != str[sz - i - 1]) {
      return false;
    }
  }
  return true;
}

int main () {
  string str;
  cin >> str;
  int sz = str.size();

  for (int i = 0; i < sz;i++) {
    if (str[i] != str[sz-i-1]) {
      char ch = str[sz-i-1];
      char ch2 = str[i];
      bool flag = false;
      for (int j = i+1; j < sz - i - 1; j++) {
        if (str[j] == ch) {
          string sc = str;
          reverse(sc.begin() + i, sc.begin() + j + 1);
          if (ispalindrome(sc)) {
            flag = true;
            break;
          }
        }
      }

      if (!flag) {
        for (int j = sz - i - 2; j > i; j--) {
          if (str[j] == ch2) {
            string sc = str;
            reverse(sc.begin() + j, sc.begin() + sz - i);
            if (ispalindrome(sc)) {
              flag = true;
              break;
            }
          }
        }
      }

      if (flag) {
        printf("Yes\n");
        break;
      }
      else {
        printf("No\n");
        break;
      }
    }
  }
}