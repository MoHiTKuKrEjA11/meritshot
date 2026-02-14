#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    
    Node(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(vector<int>& arr, int i, int n) {
    if(i >= n || arr[i] == -1)
        return NULL;
    
    Node* root = new Node(arr[i]);
    
    root->left = buildTree(arr, 2*i + 1, n);
    root->right = buildTree(arr, 2*i + 2, n);
    
    return root;
}

int res;

int solve(Node* root) {
    if(root == NULL)
        return 0;
    
    int left = max(0, solve(root->left));
    int right = max(0, solve(root->right));
    
    res = max(res, root->val + left + right);
    
    return root->val + max(left, right);
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];   // use -1 for null
    }
    
    Node* root = buildTree(arr, 0, n);
    
    res = INT_MIN;
    
    solve(root);
    
    cout << res << endl;
    
    return 0;
}
