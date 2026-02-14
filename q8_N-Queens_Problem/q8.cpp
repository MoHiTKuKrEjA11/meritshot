#include <bits/stdc++.h>
using namespace std;

void dfs(int col, vector<string>& board, vector<vector<string>>& res, int n, vector<int>& row, vector<int>& low, vector<int>& up) {

    if(col == n) {
        res.push_back(board);
        return;
    }

    for(int r = 0; r < n; r++) {

        if(row[r] == 0 &&
           low[r + col] == 0 &&
           up[n - 1 + col - r] == 0) {

            board[r][col] = 'Q';
            row[r] = 1;
            low[r + col] = 1;
            up[n - 1 + col - r] = 1;

            dfs(col + 1, board, res, n, row, low, up);

            board[r][col] = '.';
            row[r] = 0;
            low[r + col] = 0;
            up[n - 1 + col - r] = 0;
        }
    }
}

vector<vector<string>> solve(int n) {

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));

    vector<int> row(n, 0);
    vector<int> low(2 * n - 1, 0);
    vector<int> up(2 * n - 1, 0);

    dfs(0, board, res, n, row, low, up);

    return res;
}

int main() {

    int n;
    cin >> n;

    vector<vector<string>> ans = solve(n);

    for(auto board : ans) {
        for(auto row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
