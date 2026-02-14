#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k, vector<vector<bool>>& vis) {

    if(k == word.length()) {
        return true;
    }

    if(i < 0 || i >= board.size() ||
       j < 0 || j >= board[0].size() ||
       board[i][j] != word[k] ||
       vis[i][j]) {
        return false;
    }

    vis[i][j] = true;

    bool ok = dfs(board, word, i, j - 1, k + 1, vis) ||
            dfs(board, word, i, j + 1, k + 1, vis) ||
            dfs(board, word, i - 1, j, k + 1, vis) ||
            dfs(board, word, i + 1, j, k + 1, vis);

    vis[i][j] = false;

    return ok;
}

vector<string> solve(vector<vector<char>>& board, vector<string>& words) {

    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<string> res;

    for(string word : words) {

        bool found = false;
        reverse(word.begin(), word.end());

        for(int i = 0; i < n && !found; i++) {
            for(int j = 0; j < m; j++) {

                if(dfs(board, word, i, j, 0, vis)) {
                    found = true;
                    break;
                }
            }
        }

        if(found) {
            reverse(word.begin(), word.end());
            res.push_back(word);
        }
    }

    return res;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int w;
    cin >> w;

    vector<string> words(w);
    for(int i = 0; i < w; i++) {
        cin >> words[i];
    }

    vector<string> res = solve(board, words);

    for(string s : res) {
        cout << s << endl;
    }

    return 0;
}
