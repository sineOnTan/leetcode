#include <bits/stdc++.h>
using namespace std;
#define space << " "

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        auto cur = head;
        int size = 0;

        while (cur != NULL) {
            size++;
            cur = cur->next;
        }

        cur = head;
        if (size == 0) return head;
        k %= size;

        if (k == 0) return head;

        for (int i = 0; i < size - k - 1; i++) {
            cur = cur->next;
        }

        auto res = cur->next;
        cur->next = NULL;

        cur = res;

        while (cur->next != NULL) cur = cur->next;
        cur->next = head;
        return res;
    }
};