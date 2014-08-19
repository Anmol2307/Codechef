
#include <iostream>
#include <stdio.h>
using namespace std;
 
 
 
inline void in(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
  for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked()); 
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    } 
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    } 
    if(neg)
        x = -x;
}
 
 
 
 
int main(){
  
  int T;
  in(T);
  
  int count[51];
  int A[51];
  int N,K,C;
  long double probabilities[51][101]; //[K][Colour]
  long double expectations[51];
  
  while(T-->0){
    in(N);
    in(C);
    in(K);
    
    for(int i=0;i<N;i++)
      count[i] = 0;
      
    for(int i=0;i<K;i++){
      int L,R;
      in(L); 
      in(R);
      for(int j=L-1; j<=R-1; j++)
        count[j]++;
    }
    
    //turn is maxturn
    
    for(int i=0;i<C;i++)
      probabilities[0][i] = 0;
    
    probabilities[0][1] = 1;
    
    for(int turn=1; turn<=K; turn++){
      
      for(int temp=0;temp<C;temp++)
        probabilities[turn][temp] = probabilities[turn-1][temp]/2;
      
      for(int colour = 0; colour<C; colour++){
        for(int itcolour = 0; itcolour<C; itcolour++){
          probabilities[turn][(colour * itcolour)%C] += (probabilities[turn-1][itcolour])/(2*C);
        }
      }
    }
    
    for(int turn=0; turn<=K; turn++){
      expectations[turn] = 0;
      for(int i=0;i<C;i++)
        expectations[turn] += probabilities[turn][i] * i;
    }
    
    long double ans = 0;
    for(int i=0;i<N;i++)
      ans += expectations[count[i]];
      
      
    printf("%Lf\n", ans); 
  }
  
  return 0;
  
}