#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x){ val=x; next=random=NULL; }
};

Node* solve(Node* head) {
    unordered_map<Node*,Node*> mp;
    Node* temp=head;

    while(temp) {
        mp[temp]=new Node(temp->val);
        temp=temp->next;
    }

    temp=head;
    while(temp) {
        mp[temp]->next=mp[temp->next];
        mp[temp]->random=mp[temp->random];
        temp=temp->next;
    }

    return mp[head];
}

int main() {
    // Sample Input
    Node* a=new Node(7);
    Node* b=new Node(13);
    Node* c=new Node(11);
    Node* d=new Node(10);
    Node* e=new Node(1);

    a->next=b; b->next=c; c->next=d; d->next=e;

    b->random=a;
    c->random=e;
    d->random=c;
    e->random=a;

    Node* res = solve(a);

    cout << "Copied list values: ";
    while(res){
        cout << res->val << " ";
        res=res->next;
    }
}
