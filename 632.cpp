#include <bits/stdc++.h>
using namespace std;

struct datas {
    int cur;
    int next;
    int index;
    int array_index;

    bool operator<(const datas& other) const {
    if (cur != other.cur)
        return cur > other.cur;
    if (next != other.next)
        return next > other.next;
    else return true;
    }   
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<datas> pq;

        int maxv = INT_MIN;
        int minv = INT_MAX;

        int index = 0;
        for (auto i : nums) {
            if(i.size() >= 2) pq.emplace(i[0], i[1], 0, index);
            else pq.emplace(i[0], INT_MAX, 0, index);

            minv = min(minv, i[0]);
            maxv = max(maxv, i[0]);
            index++;
        }

        int resmin = minv;
        int resmax = maxv;

        while(1) {
            datas t = pq.top();
            pq.pop();
            cout << t.cur << endl;

            if (t.next == INT_MAX) break;

            if (nums[t.array_index].size() - 2 == t.index) {
                pq.emplace(nums[t.array_index][t.index + 1], INT_MAX, t.index + 1, t.array_index);
            } else {
                pq.emplace(nums[t.array_index][t.index + 1], nums[t.array_index][t.index + 2], t.index + 1, t.array_index);
            }


            minv = pq.top().cur;
            maxv = max(t.next, maxv);

            if (maxv - minv < resmax - resmin) {
                resmax = maxv;
                resmin = minv;
            }
        }

        vector<int> res;
        res.push_back(resmin);
        res.push_back(resmax);
        return res;
    }
};