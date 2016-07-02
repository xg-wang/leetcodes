class Solution {
public:
    void deleteNode(ListNode* node) {
        if (!node || !node->next) {
            return;
        }
        ListNode *node_to_delete = node->next;
        node->val = node_to_delete->val;
        node->next = node_to_delete->next;
        delete node_to_delete;
    }
};
