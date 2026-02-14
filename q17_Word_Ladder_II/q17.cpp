#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> solve(string beginWord, string endWord, vector<string>& wordList) {

    unordered_set<string> st(wordList.begin(), wordList.end());
    vector<vector<string>> res;

    queue<vector<string>> q;
    q.push({beginWord});

    while(!q.empty()) {

        int sz = q.size();
        vector<string> used;

        for(int x = 0; x < sz; x++) {

            auto path = q.front();
            q.pop();

            string last = path.back();

            if(last == endWord) {
                res.push_back(path);
                continue;
            }

            for(int i = 0; i < last.size(); i++) {

                string tmp = last;

                for(char c = 'a'; c <= 'z'; c++) {

                    tmp[i] = c;

                    if(st.count(tmp)) {
                        used.push_back(tmp);
                        path.push_back(tmp);
                        q.push(path);
                        path.pop_back();
                    }
                }
            }
        }

        for(string s : used) {
            st.erase(s);
        }
    }

    return res;
}

int main() {

    string beginWord, endWord;
    cin >> beginWord >> endWord;

    int n;
    cin >> n;

    vector<string> wordList(n);
    for(int i = 0; i < n; i++) {
        cin >> wordList[i];
    }

    vector<vector<string>> res = solve(beginWord, endWord, wordList);

    for(auto &path : res) {
        for(auto &w : path) {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}
