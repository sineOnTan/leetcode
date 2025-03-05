#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
    public:
        ProductOfNumbers() {
            res.push_back(0);
        }
        
        void add(int num) {
            res.push_back(num * max(*res.rbegin(), 1));
        }
        
        int getProduct(int k) {
            return res[res.size() - 1] / res[res.size() - k - 1];
        }

        vector<int> res;
    };
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */