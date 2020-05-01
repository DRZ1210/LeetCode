/*************************************************************************
	> File Name: leedcode234.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 12时17分29秒
 ************************************************************************/
typedef struct ListNode Node;

int get_length(Node *head) {
    int cnt = 0;
    while (head) {
        cnt++; head = head->next;
    }
    return cnt;
}

Node *reverse_half_list(Node *head, int n) {
    while (n--) head = head->next;
    Node ret, *p = head, *q;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}

bool isPalindrome(struct ListNode* head){
    if (!head) return true;
    int len = get_length(head);
    Node *p = head, *q = reverse_half_list(head, (len + 1) >> 1);
    while (q) {
        if (p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
