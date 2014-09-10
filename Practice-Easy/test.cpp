 
long long mulmod(long long a,long long b,long long m)
{
  #define C 1000000000
  if(a==0 || b==0) return 0;
  if(a<C && b<C) return (a*b)%m;
  
  long long x=0;
  while(b)
  {
    if(b & 1) {
      x+=a;
      if(x>=m) x-=m;
    }
    a<<=1;
    if(a>=m) a-=m;
    b>>=1;
  }
  return x;
}
  
long long expmod(long long a,long long b,long long m)
{
  long long x=1,y=a;
  while(b>0)
  {
    if(b & 1) x=mulmod(x,y,m);
    y=mulmod(y,y,m);
    b>>=1;
  }
  return x;
}
 
bool rabin_miller(long long n,int times)
{
  //Any n till 10^18 , if <10^9 ignore mulmod and do direct
  if(n==2 || n==3) return true;
  if(n < 5) return false;
  if(!(n & 1)) return false;
  
  long long a,x,d=n-1;
  int s=0;
  
  while(!(d & 1))
  {
    d>>=1;
    s++;
  }
  
  while(times--)
  {
    a=(((long long)rand())%(n-1))+1;
    x=expmod(a,d,n);
    if( x!=1 && x!=(n-1))
    {
      int flag=1;
      for(int i=1;i<=s && flag;i++)
      {
        x=mulmod(x,x,n);
        if(x==1) return false;
        if(x == n-1) flag=0;
      }
      if(flag) return false;
    }
  }
  return true;
}
 
int main() {
  int t;
  ll n;
  scanf("%d",&t);
  while(t--) {
    scanf("%lld",&n);
    if(n%2==0 && n>2) n--;
    while(!rabin_miller(n,10)) n-=2;
    printf("%lld\n",n);
  }
  return 0;
}