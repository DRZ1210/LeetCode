/*************************************************************************
	> File Name: leetcode21.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 22时12分29秒
 ************************************************************************/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode H, *p = &H;
        while (l1 || l2) {
            if (l2 == NULL || (l1 && l1->val < l2->val)) {
                p->next = l1;
                l1 = l1->next;
                p = p->next;
                p->next = NULL;
            } else {
                p->next = l2;
                l2 = l2->next;
                p = p->next;
                p->next = NULL;
            }
        }
        return H.next;
    }
};
