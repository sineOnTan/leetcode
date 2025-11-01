#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> nums_set;

        for (auto i : nums) nums_set.insert(i);

        while (head != nullptr and nums_set.contains(head->val)) head = head->next;

        auto cur = head;

        while (cur != nullptr and cur->next != nullptr) {
            while(cur->next != nullptr and nums_set.contains(cur->next->val)) cur->next = cur->next->next;

            cur = cur->next;
        }
    }
};