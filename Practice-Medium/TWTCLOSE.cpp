#include <bits/stdc++.h>

using namespace std;
int arr[1001];
  
int main () {
  int n, k;
  scanf("%d %d",&n,&k);
  int open = 0;
  for (int i = 0; i < k; i++) {
    char ch[15];
    scanf("%s",ch);
    if (strcmp(ch,"CLICK") == 0) {
      int x;
      scanf("%d",&x);
      if (arr[x] == 0) {
        open+=1;
        arr[x] = 1;
      }
      else {
        open-=1;
        arr[x] = 0;
      }
    }
    else {
      memset(arr,0,sizeof(arr));
      open = 0;
    }
    printf("%d\n",open);
  }
}