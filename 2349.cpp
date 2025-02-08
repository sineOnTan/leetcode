#include <bits/stdc++.h>
using namespace std;

class NumberContainers {
    public:
        NumberContainers() {
        }
        
        void change(int index, int number) {
            if (vec[index] != 0) {
                positions[vec[index]].erase(index);
            }
            vec[index] = number;
            positions[number].insert(index);
        }
        
        int find(int number) {
            if(positions[number].size() == 0)
            return *positions[number].begin();
        }

        map<int,int> vec;
        map<int,set<int>> positions;
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */