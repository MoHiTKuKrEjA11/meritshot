#include <bits/stdc++.h>
using namespace std;

vector<string> solve(string s, vector<string>& wd) {

    int n = s.length();

    unordered_set<string> st;
    for(string x : wd) {
        st.insert(x);
    }

    vector<vector<pair<bool, vector<string>>>> dp(n, vector<pair<bool, vector<string>>>(n, {false, {}}));

    for(int i = 0; i < n; i++) {
        for(int len = 1; len <= n - i; len++) {

            string sub = s.substr(i, len);

            if(st.count(sub)) {
                dp[i][len - 1] = {true, {sub}};
            }
        }
    }

    for(int i = n - 2; i >= 0; i--) {

        for(int len = 1; len <= n - i; len++) {

            if(!dp[i][len - 1].first) continue;

            int nxt = i + len;
            if(nxt >= n) continue;

            if(dp[nxt][n - nxt - 1].first) {

                dp[i][n - i - 1].first = true;

                for(string x : dp[nxt][n - nxt - 1].second) {
                    dp[i][n - i - 1].second.push_back(
                        dp[i][len - 1].second[0] + " " + x
                    );
                }
            }
        }
    }

    return dp[0][n - 1].second;
}

int main() {

    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> wd(n);
    for(int i = 0; i < n; i++) {
        cin >> wd[i];
    }

    vector<string> res = solve(s, wd);

    for(string x : res) {
        cout << x << endl;
    }

    return 0;
}
