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

char ans[1000001];
bool flag = false;

void next(char * ch, int l, int r) {
  
  if (l > r) return;
  if (r-l == 1 && !flag) {
   
  } 
  if (ch[l] == ch[r]) {
    ans[l] = ans[r] = ch[l];
  }
  else {
    if ((ch[l]-'0')  < (ch[r]-'0')) {
      ch[l] = (char)(((ch[l] - '0') + 1) + '0');
      flag = true;
    }
    else if ((ch[l]-'0')  > (ch[r]-'0')) {
      ch[r] = (char)(((ch[r] - '0') + 1) + '0');
      flag = true;
    }
  }
  next(ch,l+1,r-1);
}

int main () {
  int t;
  inp(t);

  while (t--) {
    char ch[1000001];
    scanf("%s",ch);
    int len = strlen(ch);
    next(ch,0,len-1);
    ans[len] = '\0';
    printf("%s\n",ans);
  }
}