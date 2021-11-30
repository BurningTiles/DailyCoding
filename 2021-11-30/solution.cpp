#include <bits/stdc++.h>
#define d3d vector<vector<vector<double>>>
#define d2d vector<vector<double>>
#define i2d vector<vector<int>>
using namespace std;

double probability(int x, int y, int k, i2d &dirs, d3d &memo){
	if(x<0 || x>7 || y<0 || y>7) return 0;
	if(k==0) return 1;
	if(memo[x][y][k]!=-1)
		return memo[x][y][k];
	
	double ans = 0.0;
	for(auto &dir:dirs){
		int i=dir[0], j=dir[1];
		ans += probability(x+i, y+j, k-1, dirs, memo);
	}
	return memo[x][y][k]=ans;
}

double is_knight_on_board(int x, int y, int k){
	i2d dirs = {
		{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}
	};
	d3d memo(8, d2d(8, vector<double>(k+1, -1)));
	return pow(1.0/8, k)*probability(x, y, k, dirs, memo);
}

signed main() {
	cout << is_knight_on_board(0, 0, 1) << endl;
	cout << is_knight_on_board(3, 3, 2) << endl;
	return 0;
}