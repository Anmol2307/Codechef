#include <iostream>
#include <cmath>
using namespace std;

int main () {

	int n, m, p;
	cin >> n >> m >> p;
	
	int ** valid  = new int*[n+1];
	for (int i = 0; i <= n; i++) {
		valid[i] = new int[m+1];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1 ; j <= m; j++) {
			valid[i][j] = j;
		}
	}

	int ans[n+1];
	for (int i = 1; i <= n; i++){
		ans[i] = m-1;
	}
	bool ok[n+1];
	for (int i = 1; i <= n; i++){
		ok[i] = 1;
	}
	for (int i = 0; i < p; i++) {
		int x, y;
		cin >> x >> y;
		valid[x][y]++;
		if (y > 1 && y < m && valid[x][y] == valid[x][y-1] && valid[x][y] <= valid[x][y+1] && ok[x] == 0) {
			ok[x] = 1;
			ans[x] -=1;
		}
		else if (y > 1 && y < m && valid[x][y] == valid[x][y-1] && valid[x][y] > valid[x][y+1] && ok[x] == 1) {
			ok[x] = 0;
		}
		else if (y > 1 && y < m && valid[x][y] > valid[x][y-1] && valid[x][y] > valid[x][y+1]) {
			ans[x]+=1;
			if (ok[x]) ok[x] = 0;
		}
		else if (y > 1 && y < m && valid[x][y] < valid[x][y-1] && valid[x][y] <= valid[x][y+1]){
			ans[x] -=1;
		}

		if (y==1 && valid[x][y] > valid[x][y+1] && ok[x] == 1) {
			ok[x] =0;
		}
		else if (y==1 && valid[x][y] <= valid[x][y+1]) {
			ans[x] -= 1;
		}

		if (y==m && valid[x][y] > valid[x][y-1]) {
			ans[x] += 1;
		}
		else if (y==m && valid[x][y] == valid[x][y-1] && ok[x] == 0) {
			ok[x] = 1;
		}

	}
	for (int i = 1; i <= n; i++) {
		if (ok[i]) cout << ans[i] << endl;
		else cout << -1 << endl;
	}

}