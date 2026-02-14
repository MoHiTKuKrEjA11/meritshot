#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& g, vector<int>& vis, vector<int>& rec, vector<char>& ans) {

    vis[u] = 1;
    rec[u] = 1;

    for(int v = 0; v < 26; v++) {

        if(g[u][v]) {

            if(!vis[v]) {
                if(!dfs(v, g, vis, rec, ans)) {
                    return false;
                }
            }
            else if(rec[v]) {
                return false;
            }
        }
    }

    ans.push_back(char('a' + u));
    rec[u] = 0;

    return true;
}

string solve(vector<string>& words) {

    vector<vector<int>> g(26, vector<int>(26, 0));
    vector<int> exist(26, 0);
    vector<int> vis(26, 0);
    vector<int> rec(26, 0);
    vector<char> ans;

    for(auto &w : words) {
        for(char c : w) {
            exist[c - 'a'] = 1;
        }
    }

    for(int i = 0; i + 1 < words.size(); i++) {

        string a = words[i];
        string b = words[i + 1];

        int n = a.size();
        int m = b.size();
        int idx = 0;

        while(idx < n && idx < m && a[idx] == b[idx]) {
            idx++;
        }

        if(idx < n && idx == m) {
            return "";
        }

        if(idx < n && idx < m) {
            g[a[idx] - 'a'][b[idx] - 'a'] = 1;
        }
    }

    for(int i = 0; i < 26; i++) {
        if(exist[i] && !vis[i]) {
            if(!dfs(i, g, vis, rec, ans)) {
                return "";
            }
        }
    }

    reverse(ans.begin(), ans.end());

    return string(ans.begin(), ans.end());
}

int main() {

    int n;
    cin >> n;

    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    cout << solve(words) << endl;

    return 0;
}
