/*************************************************************************
	> File Name: leedcode141.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月26日 星期三 09时49分51秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if (!head) return false;
    struct ListNode *p, *q;
    p = head, q = head;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return false;
        q = q->next;
    } while (p != q);
    return true;
}
