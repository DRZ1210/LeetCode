/*************************************************************************
	> File Name: leedcode160.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月26日 星期三 09时50分52秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 若p存在，那就不要担心p->next的情况
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p = headA, *q = headB;
    while (p != q) {
        p = p ? p->next : headB;
        q = q ? q->next : headA;
    }
    return p;
}
