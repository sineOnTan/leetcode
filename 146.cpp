#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    unordered_map<int, list<int>::iterator> m;
    unordered_map<int, int> k_v;

    list<int> LRU;
    int LRU_capacity;

public:
    LRUCache(int capacity) {
        LRU_capacity = capacity;
    }
    
    int get(int key) {
        if (k_v.find(key) == k_v.end()) return -1;
        LRU.erase(m[key]);
        LRU.push_front(key);
        m[key] = LRU.begin();
        return k_v[key];
    }
    
    void put(int key, int value) {
        if (m.find(key) == m.end()) {
            if (LRU.size() == LRU_capacity) {
                int back = *LRU.rbegin();
                m.erase(back);
                k_v.erase(back);
                LRU.pop_back();
            }

            LRU.push_front(key);
            m[key] = LRU.begin();
            k_v[key] = value;
        } else {
            LRU.erase(m[key]);
            LRU.push_front(key);
            k_v[key] = value;
            m[key] = LRU.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */