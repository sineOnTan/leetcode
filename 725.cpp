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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> result;
        int counter = 0;
        ListNode* current = head;
        while (current != nullptr) {
            counter++;
            current = current->next;
        }
        int remainder = counter % k;
        counter/=k;
        current = head;

        result.push_back(current);
        int count = 0;
        while (current != nullptr) {
            count++;
            if (remainder != 0) {
                if (count == counter + 1) {
                    ListNode* temp = current->next;
                    current->next = nullptr;
                    current = temp;
                    if (current != nullptr) {
                        result.push_back(current);
                    }
                    remainder--;
                    count = 0;
                } else {
                    current = current->next;
                }
            } else {
                if (count == counter) {
                    ListNode* temp = current->next;
                    current->next = nullptr;
                    current = temp;
                    if (current != nullptr) {
                        result.push_back(current);
                    }
                    count = 0;
                } else {
                    current = current->next;
                }
            }
            
        }
        while(result.size() < k) {
            result.push_back(nullptr);
        }
        return result;
    }
};