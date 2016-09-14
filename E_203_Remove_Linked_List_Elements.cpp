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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return NULL;
        }
        ListNode *p = head, *tofree;
        while (p && p->val == val) {
            tofree = p;
            p = p->next;
            delete tofree;
        }
        head = p;
        while (p && p->next) {
            if (p->next->val == val) {
                tofree = p->next;
                p->next = p->next->next;
                delete tofree;
            } else {
                p = p->next;
            }
        }
        return head;
    }
};