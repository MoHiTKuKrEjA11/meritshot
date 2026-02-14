#include <bits/stdc++.h>
using namespace std;

string solve(string s, string t) {

    if(s.empty() || t.empty()) {
        return "";
    }

    unordered_map<char, int> need;
    for(char c : t) {
        need[c]++;
    }

    int req = need.size();
    int formed = 0;

    unordered_map<char, int> win;

    int l = 0, r = 0;
    int len = -1, start = 0;

    while(r < s.length()) {

        char c = s[r];
        win[c]++;

        if(need.count(c) && win[c] == need[c]) {
            formed++;
        }

        while(l <= r && formed == req) {

            if(len == -1 || r - l + 1 < len) {
                len = r - l + 1;
                start = l;
            }

            char ch = s[l];
            win[ch]--;

            if(need.count(ch) && win[ch] < need[ch]) {
                formed--;
            }

            l++;
        }

        r++;
    }

    if(len == -1) return "";

    return s.substr(start, len);
}

int main() {

    string s, t;
    cin >> s >> t;

    cout << solve(s, t) << endl;

    return 0;
}
