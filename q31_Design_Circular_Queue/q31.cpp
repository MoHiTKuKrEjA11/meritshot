#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> arr;
    int f, r, size, cap;

    MyCircularQueue(int k) {
        cap = k;
        arr.resize(k);
        f = 0;
        r = -1;
        size = 0;
    }

    bool enQueue(int value) {
        if(size == cap) return false;
        r = (r + 1) % cap;
        arr[r] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if(size == 0) return false;
        f = (f + 1) % cap;
        size--;
        return true;
    }

    int Front() {
        if(size == 0) return -1;
        return arr[f];
    }

    int Rear() {
        if(size == 0) return -1;
        return arr[r];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};

int main() {
    // Sample Input
    cout << "Operations:\n";
    cout << "k = 3\n";
    cout << "enQueue(1), enQueue(2), deQueue(), Front()\n\n";

    MyCircularQueue q(3);

    q.enQueue(1);
    q.enQueue(2);
    q.deQueue();

    cout << q.Front() << endl;   // 2
}
