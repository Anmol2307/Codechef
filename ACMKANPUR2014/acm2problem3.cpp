#include <iostream>
#include <cstdio>
#include <string>
// For fstream 			#include <fstream>
// For setprecision 	#include <iomanip>
// For getchar() 		#include <cstdio>
// rand(),atoi			#include <cstdlib>
// For srand(time(NULL)) #include <time.h>
// For Built-in sort	#include <algorithm>
// For Math functions - sqrt, ceil, floor 	#include <cmath>
#include <vector>
//For Binary Tree sets,multisets -  #include<set>
// For lists			#include<list>
//For queues  			#include<queue>
//For stacks  			#include<stack>
//For pairs				#include<utility>
//For maps 				#include<map>
//INCLUDE EVERYTHING #include<bit/stdc++.h>
using namespace std;

void process(vector<long long int> &v,string &s, long long int p){
	for(long long int i = 0 ; i  < 26;i++){
		v[i] = 0;
	}
	for(long long int i = 0; i < s.length(); i ++){
		 v[s[i]-'a']+=p;
	}
	for(long long int i =1 ; i < 26;i++){
		v[i] = v[i] + v[i-1];
	}
}

long long int return_character(vector<long long int> &v,long long int pos){
	for(long long int i = 0 ; i < 26;i++){
		if(pos <= v[i])
			return i;
	}
	return -1;
}

int main(){
	long long int tstCases;
	cin>>tstCases; 
	//t = 1;	
	string s;
	long long int p,q,n;
	vector<long long int> result(26,0);
	for(long long int tst = 0; tst < tstCases; tst++){
		//s,p,q,n
		cin>>s;
		cin>>p>>q;
		process(result,s,p);
		for(long long int i = 0; i<q;i++){
			cin>>n;
			long long int res = return_character(result,n);
			if(res == -1)
				printf("-1\n");
			else{
				char x = 'a' + res;
				printf("%c\n",x);
		}}

	}	
}