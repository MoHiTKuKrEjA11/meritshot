#include <bits/stdc++.h>
using namespace std;

vector<int> buildLPS(string &p) {

    int m = p.length();
    vector<int> lps(m, 0);

    int len = 0;
    int i = 1;

    while(i < m) {

        if(p[i] == p[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

int solve(string &text, string &pattern) {

    int n = text.length();
    int m = pattern.length();

    if(m > n) return -1;

    vector<int> lps = buildLPS(pattern);

    int i = 0, j = 0;

    while(i < n) {

        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == m) {
            return i - j;
        }
        else if(i < n && text[i] != pattern[j]) {

            if(j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    return -1;
}

int main() {

    string text, pattern;
    cin >> text >> pattern;

    cout << solve(text, pattern) << endl;

    return 0;
}
