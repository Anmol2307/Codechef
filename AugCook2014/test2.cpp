//Template
 
// By Anudeep :)
//Includes
#include <vector> 
#include <queue>
#include <map> 
#include <set>
#include <utility> //Pair
#include <algorithm>
#include <sstream> // istringstream>> ostring stream<<
#include <iostream> 
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
using namespace std;
 
//M lazy ;)
typedef long long ll;
typedef vector <int> vi;
typedef pair< int ,int > pii;
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
#define pl(n) cout << n
#define ps printf(" ")
#define pn printf("\n")
#define dg(n,s); printf("%s %d",s,n)
#define imax numeric_limits<int>::max()
#define imin numeric_limits<int>::min()
#define lmax numeric_limits<ll>::max()
#define lmin numeric_limits<ll>::min()
 
char grid[55][55];
int id[55][55];
int col[55];
 
int main()
{
	int t;
	gi(t);
 
	while(t--)
	{
		int n, m;
		gi(n); gi(m);
 
		rep(i, n)
			scanf("%s", grid[i]);
 
		bool can = false;
 
		memset(id, -1, sizeof id);
		int idc = 0;
		rep(i, n)
			rep(j, m)
			if(grid[i][j] == 'L')
			{
				id[i][j] = idc++;
			}
 
		rep(mask, (1<<idc))
		{
			rep(i, m)
				col[i] = 0;
 
			int ok = true;
			fd(i, n-1, 0)
			{
				int leftmost = 200;
				int rightmost = -200;
				int count = 0;
				int loc = -1;
				int ecount = 0;
 
				rep(j, m)
				if(grid[i][j] == 'E' && col[j] == 0)
				{
					leftmost = min(leftmost, j);
					rightmost = max(rightmost, j);
					ecount++;
				}
				else if(grid[i][j] == 'L')
				{
					if((mask >> id[i][j])&1)
					{
						col[j] = 1;
					} else
					{
						count++;
						loc = j;
					}
				}
 
				if(ecount == 0)
					continue;
				if(count > 1)
					continue;
				if(count == 0)
				{
					ok = false;
					break;
				}
				//turn left
				if(rightmost < loc)
					continue;
				//turn right
				if(leftmost > loc)
					continue;
 
				ok = false;
				break;
			}
 
			if(ok)
			{
				can = true;
				break;
			}
		}
 
		if(can)
			puts("Possible");
		else
			puts("Impossible");
	}
	return 0;
} 