/*************************************************************************
	> File Name: leedcode203.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 11时16分33秒
 ************************************************************************/
typedef struct ListNode Node;

struct ListNode* removeElements(struct ListNode* head, int val){
    if (!head) return head;
    Node ret, *current_node, *next_node;
    ret.next = head;
    current_node = &ret, next_node = head;
    while (next_node) {
        if (next_node->val - val) {
            current_node = next_node;
            next_node = next_node->next;
        } else {
            current_node->next = next_node->next;
            free(next_node);
            next_node = current_node->next;
        }
    }
    return ret.next;
}
