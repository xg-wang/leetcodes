// https://leetcode.com/problems/reverse-linked-list/
#include "lc_header.h"

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *post = NULL;
        while (head != NULL) {
            post = head->next;
            head->next = pre;
            pre = head;
            head = post;
        }
        return pre;
    }
};