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

void get_level_count(vector<list <int> > &tree,vector<int> &counts, int b,int level){
	counts[level] += 1;
//	cout<<"NODE "<<b<<" HAS "<<level<<endl;
	int new_level = level + 1;
	for(list<int>::iterator li = tree[b].begin(); li!=tree[b].end();li++){
//		cout<<"CHILD "<<*li<<" OF "<<b<<"CALLED WITH"<<new_level<<endl;
		get_level_count(tree,counts,*li, new_level);
	}
}


vector< map<int,int> > tree_count(100001);
vector<int> parent(100001);

void backtrace(int node,int level){
	// cout<<"NODE"<<node<<level<<endl;
	if(tree_count[node].find(level) != tree_count[node].end())
		tree_count[node][level] = tree_count[node][level] + 1;
	else
		tree_count[node][level] = 1;
	// cout<<tree_count[node][level]<<endl;
	if(node != 0)
		backtrace(parent[node],1 - level);
}

int main(){
	int tstCases;
	inp(tstCases);
	// vector<list <int> > tree(100001);
	vector<int> counter(100001,0);

	for(int tst = 0; tst < tstCases; tst++){
		int m,a,b;
		int count = 0;
		inp(m);
		tree_count[0][0] = 1;
		for (int i=0;i<m;i++){
			inp(a);
			inp(b);
			if(a == 0){
				count++;
				// cout<<"ADDING "<<count<<" in "<<b<<endl;; 
				parent[count] = b;
				backtrace(count,0);
			}else{
				int even_count = 0,odd_count = 0,square_count = 0;
				map<int,int> mp = tree_count[b];
				even_count = mp[0];
				odd_count = mp[1];
				// cout<<odd_count<<" "<<even_count<<endl;
				square_count = even_count + odd_count;

				int output = (even_count*even_count) + (odd_count*odd_count) - (square_count);
				output /= 2;
				// output += odd_count*(count + 1 - square_count);
				printf("%d\n",output);

				for(int i = 0 ; i < 100001; i++){
					counter[i] = 0;
				}
			}
		}

		for(int i = 0; i<100001;i++){
			tree_count[i].clear();
		}
	}	
}
