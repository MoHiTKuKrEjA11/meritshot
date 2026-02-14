#include <bits/stdc++.h>
using namespace std;

bool dfs(map<int,int>& pos, int cur, int jump, int last, map<pair<int,int>, int>& dp) {

    if(dp.count({cur, jump})) {
        return dp[{cur, jump}];
    }

    if(cur > last) {
        return false;
    }

    if(!pos.count(cur)) {
        return false;
    }

    if(cur == last) {
        return true;
    }

    bool check = false;

    if(jump - 1 > 0) {
        check = dfs(pos, cur + jump - 1, jump - 1, last, dp);
    }

    if(!check) {
        check = dfs(pos, cur + jump, jump, last, dp);
    }

    if(!check) {
        check = dfs(pos, cur + jump + 1, jump + 1, last, dp);
    }

    dp[{cur, jump}] = check;
    return check;
}

bool solve(vector<int>& stones) {
    int n = stones.size();

    map<int,int> pos;
    for(int i = 0; i < n; i++) {
        pos[stones[i]] = i;
    }

    map<pair<int,int>, int> dp;

    return dfs(pos, 0, 1, stones[n - 1], dp);
}

int main() {
    int n;
    cin >> n;

    vector<int> stones(n);
    for(int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    
    if(solve(stones)) {
        cout << "true\n"; 
    } else {
        cout << "false\n";
    }

    return 0;
}