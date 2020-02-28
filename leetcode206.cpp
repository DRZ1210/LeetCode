/*************************************************************************
	> File Name: leedcode206.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 11时20分38秒
 ************************************************************************/
typedef struct ListNode Node;

struct ListNode* reverseList(struct ListNode* head){
    Node ret, *p, *q;
    ret.next = NULL;
    p = head;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
