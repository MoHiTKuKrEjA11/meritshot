#include <bits/stdc++.h>
using namespace std;

class LRU{
public:
    int cap;
    list<pair<int,int>> dq;
    unordered_map<int,list<pair<int,int>>::iterator> mp;
    LRU(int c){ cap=c; }

    int get(int key){
        if(mp.find(key)==mp.end()) return -1;
        auto it=mp[key];
        int val=it->second;
        dq.erase(it);
        dq.push_front({key,val});
        mp[key]=dq.begin();
        return val;
    }

    void put(int key,int value){
        if(mp.find(key)!=mp.end()) dq.erase(mp[key]);
        else if(dq.size()==cap){ auto last=dq.back(); mp.erase(last.first); dq.pop_back(); }
        dq.push_front({key,value});
        mp[key]=dq.begin();
    }
};

int main(){
    // Sample input
    LRU l(2);
    cout << "Operations: put(1,1), put(2,2), get(1), put(3,3)" << endl;

    l.put(1,1); cout<<"null\n";
    l.put(2,2); cout<<"null\n";
    cout<<l.get(1)<<endl;
    l.put(3,3); cout<<"null\n";
}
