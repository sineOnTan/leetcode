class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int neg = 0;
            int pos = 0;
            for (auto i : nums) {
                if (i > 0) pos++;
                else if (i < 0) neg++;
            }
            return max(pos,neg);
        }
    };