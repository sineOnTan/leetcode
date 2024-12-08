#include <bits/stdc++.h>
#include <numeric>


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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> result;
        int previous = -1;
        ListNode* current = head;

        while (current != nullptr) {
            if (previous != -1) {
                result.push_back(__gcd(previous, current->val));
            }
            result.push_back(current->val);
            previous = current->val;
            current = current->next;
        }
        return result;
    }
};