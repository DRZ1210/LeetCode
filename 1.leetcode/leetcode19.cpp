/*************************************************************************
	> File Name: leedcode19.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月26日 星期三 09时47分29秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode H, *p, *q;
    H.next = head;
    p = &H;
    q = &H;
    while (n--) p = p->next;
    p = p->next;
    while (p) {
        p = p->next;
        q = q->next;
    }
    p = q->next;
    q->next = p->next;
    free(p);
    return H.next;
}

