#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<char>>& vec) {
	int m = vec.size();
	int n = vec[0].size();

	vector<vector<int>> dp(m, vector<int>(n, 0));
	for(int i=m-1; i>=0; i--) {
		for(int j=n-1; j>=0; j--) {
			if(vec[i][j]=='0') continue;
			else if(i!=m-1) {
				dp[i][j] = 1 + dp[i+1][j];
			} else {
				dp[i][j] = 1;
			}
		}
	}

	int ans = INT_MIN;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			int md = INT_MAX;
			for(int k=j; k<n && md>0; k++) {
				md = min(md, dp[i][k]);
				ans = max(ans, md*(k-j+1));
			}
		}
	}
	return ans;
}

int main()
{
	int m,n;
	cin >> m >> n;
	vector<vector<char>> vec(m);

	char ch;
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> ch;
			vec[i].push_back(ch);
		}
	}

	int res = solve(vec);
	cout << res << endl;

	return 0;
}