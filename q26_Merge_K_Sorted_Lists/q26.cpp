#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x){ val=x; next=NULL; }
};

Node* solve(vector<Node*>& lists) {
    vector<int> temp;
    for(auto l : lists){
        while(l){
            temp.push_back(l->val);
            l = l->next;
        }
    }
    sort(temp.begin(), temp.end());

    Node* head=NULL;
    Node* tail=NULL;
    for(int x : temp){
        Node* n=new Node(x);
        if(!head) head=tail=n;
        else { tail->next=n; tail=n; }
    }
    return head;
}

int main() {
    // Sample input: 3 sorted lists
    Node* a=new Node(1); a->next=new Node(4); a->next->next=new Node(5);
    Node* b=new Node(1); b->next=new Node(3); b->next->next=new Node(4);
    Node* c=new Node(2); c->next=new Node(6);

    vector<Node*> lists = {a, b, c};

    Node* res = solve(lists);
    cout << "Merged sorted list: ";
    while(res){ cout << res->val << " "; res=res->next; }
    cout << endl;
}
