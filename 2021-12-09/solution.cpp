#include <bits/stdc++.h>
#define i2d vector<vector<int>>
using namespace std;

int min_diff(vector<int> v, int k){
	sort(v.begin(), v.end());
	int ans = INT_MAX; k--;
	for(int i=k; i<v.size(); i++)
		ans = min(ans, v[i]-v[i-k]);
	return ans;
}

signed main() {
	cout << min_diff({90}, 1) << endl;
	cout << min_diff({9, 4, 1, 7}, 2) << endl;
	return 0;
}