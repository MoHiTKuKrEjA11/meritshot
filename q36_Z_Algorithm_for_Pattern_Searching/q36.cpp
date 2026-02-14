#include <bits/stdc++.h>
using namespace std;

vector<int> buildZ(string &s) {

    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0;

    for(int i = 1; i < n; i++) {

        if(i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }

        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }

        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

vector<int> solve(string &text, string &pattern) {

    string s = pattern + "$" + text;
    vector<int> z = buildZ(s);

    vector<int> ans;
    int m = pattern.length();

    for(int i = 0; i < z.size(); i++) {
        if(z[i] == m) {
            ans.push_back(i - m - 1);
        }
    }

    return ans;
}

int main() {

    string text, pattern;
    cin >> text >> pattern;

    vector<int> res = solve(text, pattern);

    for(int x : res) {
        cout << x << " ";
    }

    return 0;
}
