/*************************************************************************
	> File Name: leedcode142.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月26日 星期三 09时50分22秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next; 
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if (!head) return NULL;
    struct ListNode *p, *q;
    p = head, q = head;
    do {
        p = p->next;
        q = q->next;
        if (!q || !q->next) return NULL;
        q = q->next;
    } while (p != q);
    int cnt = 0;
    do {
        cnt++;
        p = p->next;
    } while (p != q);
    p = head, q = head;
    while (cnt--) p = p->next;
    while (p != q) {
        p = p->next;
        q = q->next;
    }
    return p;
}
