#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st, mini;

    void push(int x) {
        st.push(x);
        if(mini.empty() || x <= mini.top())
            mini.push(x);
    }

    void pop() {
        if(st.top() == mini.top())
            mini.pop();
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return mini.top();
    }
};

int main() {
    // Sample Input Operations
    cout << "Operations:\n";
    cout << "push(2), push(0), push(3), push(0), getMin(), pop(), getMin()\n\n";

    MinStack s;

    s.push(2);
    s.push(0);
    s.push(3);
    s.push(0);

    cout << s.getMin() << endl;  // 0
    s.pop();
    cout << s.getMin() << endl;  // 0
}
