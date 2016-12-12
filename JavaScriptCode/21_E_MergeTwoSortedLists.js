/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    
    let result = new ListNode(), node = result;
    let n1 = l1, n2 = l2;
    while (n1 && n2) {
        if (n1.val < n2.val) {
            node = node.next = n1;
            n1 = n1.next;
        } else {
            node = node.next = n2;
            n2 = n2.next;
        }
    }
    if (!n1 && n2) {
        node.next = n2;
    } else if (!n2 && n1) {
        node.next = n1;
    }
    
    return result.next;
};