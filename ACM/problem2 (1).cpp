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



int main(){
	int tstCases;
	inp(tstCases);
	vector<list <int> > tree(100001);
	vector<int> counter(100001,0);

	for(int tst = 0; tst < tstCases; tst++){
		int m,a,b;
		int count = 0;
		inp(m);
		for (int i=0;i<m;i++){
			inp(a);
			inp(b);
			if(a == 0){
				count++;
				tree[b].push_back(count);
			}
			else{
				get_level_count(tree,counter,b,0);
				int even_count = 0,odd_count = 0,square_count = 0;

				for(int i=0;i<=count;i++){
					if(i%2==0){
						even_count += counter[i];
					}else{
						odd_count += counter[i];
					}
					square_count += counter[i];
				}

				int output = (even_count*even_count) + (odd_count*odd_count) - (square_count);
				output /= 2;

				printf("%d\n",output);

				for(int i = 0 ; i < 100001; i++){
					counter[i] = 0;
				}
			}
		}

		list<int> nil;
		for(int i = 0; i<100001;i++){
			tree[i] = nil;
		}
	}	
}