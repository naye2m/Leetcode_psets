//  32 : 31
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode ln;
ln* mergeTwoLists(ln* list1, ln* list2) {
    if (!list1)
        return list2;
    if (!list2)
        return list1;
    ln* l = list1;
    ln* r = list2;
    ln dummy; 
    ln* res = &dummy; 
    dummy.next = NULL; 
    while (l && r) {
        if (l->val <= r->val) {
            res->next = l;
            l = l->next;
        } else {
            res->next = r;
            r = r->next;
        }
        res = res->next; 
    }
    res->next = (l != NULL) ? l : r;
    return dummy.next; 
}
