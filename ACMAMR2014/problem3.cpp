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

int neg_inf = -1000000000;

int computeR(vector<vector<vector<int > > > &diagonal,int row, int c1, int c2, vector<vector<int> > &values){
	// cout<<"ROW"<<row<<" "<<c1<<" "<<c2<<endl;
	if(diagonal[row][c1][c2] != neg_inf)
		return diagonal[row][c1][c2];

	if(c1 == c2)
		return 0;
	
	if(c2 - c1 == 1){
		diagonal[row][c1][c2] = values[row][c1]  + values[row + 1][c2];
	}
	else{
		diagonal[row][c1][c2] = computeR(diagonal,row,c1,c1+1,values)
									+ computeR(diagonal,row + 1,c1+1,c2,values)
									- values[row+1][c1+1];									
	}
	// cout<<"RIGHT "<<row<<" "<<c1<<" "<<c2<<" "<<diagonal[row][c1][c2]<<endl;
	return diagonal[row][c1][c2];

}
int computeL(vector<vector<vector<int > > > &diagonal,int row, int c1, int c2, vector<vector<int> > &values){

	if(diagonal[row][c1][c2] != neg_inf)
		return diagonal[row][c1][c2];

	if(c1 == c2)
		return 0;
	
	if(c2 - c1 == 1){
		diagonal[row][c1][c2] = values[row][c2]  + values[row + 1][c1];
	}
	
	else{
		diagonal[row][c1][c2] = computeL(diagonal,row,c2-1,c2,values)
									+ computeL(diagonal,row+1,c1,c2-1,values)
									- values[row+1][c2-1];
	}
	// cout<<"LEFT "<<row<<" "<<c1<<" "<<c2<<" "<<diagonal[row][c1][c2]<<endl;
	return diagonal[row][c1][c2];

}

int main(){
	int tstCases;
	inp(tstCases);

	int m,n,x;

	for(int tst = 0; tst < tstCases; tst++){
		inp(m);
		inp(n);

		vector<int> ht(n,neg_inf);
		vector<vector<int> > sqr(m,ht);

		vector<vector<int> > row(n,ht);
		vector<vector<vector<int> > > right(m,row);
		vector<vector<vector<int> > > left(m,row);

		for(int i = 0 ; i<m; i++){
			for(int j = 0 ; j<n; j++){
				inp(x);
				sqr[i][j] = x;
			}	
		}

		int max_cross = neg_inf;

		for(int row = 0 ; row < m; row++){
			for(int c1 = 0 ; c1 < n; c1 ++ ){
				for(int c2 = c1+1 ; c2 < n; c2 ++ ){
					if(c2 - c1 + row >= m)
						break;
					
					int sum = computeR(right,row,c1,c2,sqr) + computeL(left,row,c1,c2,sqr);
					if((c2-c1)%2==0)
						sum -= sqr[row+(c2-c1)/2][c1+(c2-c1)/2];
//					cout<<"SUM : "<<row<<" "<<c1<<" "<<c2<<" : "<<sum<<endl;
					if(sum > max_cross)
						max_cross = sum;
				}	
			}
		}

		cout<<max_cross<<endl;

	}	
}
