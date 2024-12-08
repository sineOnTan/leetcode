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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head->next;
        ListNode* previous = head;
        
        while (current != nullptr) {
            previous->next = new ListNode(__gcd(current->val, previous->val));
            previous->next->next = current;
            previous = current;
            current = current->next;
        }
        return head;
    }
};