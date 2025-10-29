class Solution {
public:
    int smallestNumber(int n) {
        int cur = 1;
        while (cur <= n) cur *= 2;
        return cur - 1;
    }
};