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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA, *b = headB, *p_short, *p_long;
        if (!a || !b) {
            return NULL;
        }
        while (a && b) {
            a = a->next;
            b = b->next;
        }
        if (!a) {
            p_short = headB;
            p_long = headA;
            while (b) {
                b = b->next;
                p_short = p_short->next;
            }
        } else {
            p_short = headA;
            p_long = headB;
            while (a) {
                a = a->next;
                p_short = p_short->next;
            }
        }
        while (p_short && p_long) {
            if (p_short->val == p_long->val) {
                return p_short;
            } else {
                p_short = p_short->next;
                p_long = p_long->next;
            }
        }
        return NULL;
    }
};