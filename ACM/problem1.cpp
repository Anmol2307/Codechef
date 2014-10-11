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


int counter(vector<int> &number,vector<int> &mod_counter, int mod, int req,int pos){
	if(pos >= number.size())
		return 0;

	vector<int> duplicate = mod_counter;

	for(int i = 0 ; i < duplicate.size(); i++){
		mod_counter[i] = 0;
	}
	for(int i = 0 ; i < duplicate.size(); i++){
		mod_counter[ (i*10 + number[pos])%mod] += duplicate[i];
	}
	mod_counter[number[pos] % mod] ++;
		
	return mod_counter[req] + counter(number,mod_counter,mod,req,pos+1);
}

int main(){	
	string s;
	cin>>s;
	vector<int> v(s.length(),0);
	for(int i = 0 ;i < s.length();i++){
		v[i] = s[i] - '0';
	}
/*
	cout<<"\nNUMBER : ";
	for(int i  = 0 ; i < v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
*/
	int q,m,l;
	inp(q);
	for(int i=0;i <q; i++){
		inp(m);
		inp(l);
		vector<int> mod_counter(m,0);
		cout<<counter(v,mod_counter,m,l,0)<<endl;;
	}

}