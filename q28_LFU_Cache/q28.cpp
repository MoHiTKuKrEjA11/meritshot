#include <bits/stdc++.h>
using namespace std;

class LFU{
public:
    int cap;
    unordered_map<int,int> val,freq;
    LFU(int c){ cap=c; }

    int get(int key){ 
        if(val.count(key)==0) return -1;
        freq[key]++; return val[key]; 
    }

    void put(int key,int value){
        if(cap==0) return;
        if(val.size()==cap && val.count(key)==0){
            int mn=INT_MAX,del=-1;
            for(auto &p:freq){
                if(p.second<mn){ mn=p.second; del=p.first; }
            }
            val.erase(del); freq.erase(del);
        }
        val[key]=value; freq[key]++;
    }
};

int main(){
    // Sample input
    LFU l(2);
    cout << "Operations: put(1,1), put(2,2), get(1), put(3,3)" << endl;

    l.put(1,1); cout<<"null\n";
    l.put(2,2); cout<<"null\n";
    cout<<l.get(1)<<endl;
    l.put(3,3); cout<<"null\n";
}
