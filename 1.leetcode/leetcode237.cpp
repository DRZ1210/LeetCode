/*************************************************************************
	> File Name: leedcode237.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 12时21分32秒
 ************************************************************************/
void deleteNode(struct ListNode* node) {
    struct ListNode *delete_node = node->next;
    *(node) = *(node->next);
    free(delete_node);
}
