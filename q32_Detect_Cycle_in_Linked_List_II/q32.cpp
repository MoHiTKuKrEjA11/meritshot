#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x){ val=x; next=NULL; }
};

Node* detectCycle(Node* head) {
    Node *slow=head, *fast=head;

    while(fast && fast->next) {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) {
            slow=head;
            while(slow!=fast) {
                slow=slow->next;
                fast=fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main() {
    // Sample Input: [3,2,0,-4], pos = 1
    Node* head=new Node(3);
    Node* n1=new Node(2);
    Node* n2=new Node(0);
    Node* n3=new Node(-4);

    head->next=n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n1;   // cycle at node with value 2

    Node* res = detectCycle(head);

    if(res)
        cout << "Cycle starts at node with value: " << res->val << endl;
    else
        cout << "No cycle\n";
}
