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

string solve(Node* root) {
    
    if(root == NULL)
        return "";
    
    queue<Node*> qu;
    qu.push(root);
    
    string res = "";
    
    while(!qu.empty()) {
        
        Node* temp = qu.front();
        qu.pop();
        
        if(temp == NULL) {
            res += "-1 ";
            continue;
        }
        
        res += to_string(temp->val) + " ";
        
        qu.push(temp->left);
        qu.push(temp->right);
    }
    
    return res;
}

Node* deserialize(string data) {
    
    if(data.size() == 0)
        return NULL;
    
    stringstream ss(data);
    vector<int> arr;
    int x;
    
    while(ss >> x) {
        arr.push_back(x);
    }
    
    int n = arr.size();
    
    if(n == 0 || arr[0] == -1)
        return NULL;
    
    Node* root = new Node(arr[0]);
    
    queue<Node*> qu;
    qu.push(root);
    
    int i = 1;
    
    while(!qu.empty() && i < n) {
        
        Node* temp = qu.front();
        qu.pop();
        
        if(arr[i] != -1) {
            temp->left = new Node(arr[i]);
            qu.push(temp->left);
        }
        i++;
        
        if(i < n && arr[i] != -1) {
            temp->right = new Node(arr[i]);
            qu.push(temp->right);
        }
        i++;
    }
    
    return root;
}

int main() {
    
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    for(int i = 0; i < n; i++) {
        cin >> arr[i];   // use -1 for null
    }
    
    // Build tree first (level order)
    if(n == 0 || arr[0] == -1) {
        cout << "" << endl;
        return 0;
    }
    
    Node* root = new Node(arr[0]);
    queue<Node*> qu;
    qu.push(root);
    
    int i = 1;
    
    while(!qu.empty() && i < n) {
        
        Node* temp = qu.front();
        qu.pop();
        
        if(arr[i] != -1) {
            temp->left = new Node(arr[i]);
            qu.push(temp->left);
        }
        i++;
        
        if(i < n && arr[i] != -1) {
            temp->right = new Node(arr[i]);
            qu.push(temp->right);
        }
        i++;
    }
    
    string res = solve(root);
    
    Node* newRoot = deserialize(res);
    
    string check = solve(newRoot);
    
    cout << check << endl;
    
    return 0;
}
