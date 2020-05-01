/*************************************************************************
	> File Name: leedcode83.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月26日 星期三 09时48分53秒
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode *p = head, *q;
    while (p && p->next) {
        if (p->val == p->next->val) {
            q = p->next;
            p->next = q->next;
            free(q);
        }
        else p = p->next;
    }
    return head;
}
