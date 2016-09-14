#include "lc_header.h"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;

        ListNode *p_fast = head, *p_slow = head;
        while (p_fast && p_fast->next) {
            p_slow = p_slow->next;
            p_fast = p_fast->next->next;
            if (p_fast == p_slow) {
                return true;
            }
        }
        return false;
    }
};