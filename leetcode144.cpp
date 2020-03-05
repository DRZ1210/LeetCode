/*************************************************************************
	> File Name: leetcode144.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月05日 星期四 11时47分20秒
 ************************************************************************/
typedef struct TreeNode Node;

void pre_order(Node *root, int *ret, int *cnt) {
    if (!root) return ;
    ret[(*cnt)++] = root->val;
    pre_order(root->left, ret, cnt);
    pre_order(root->right, ret, cnt);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int max_len = 1024, cnt = 0;
    int *ret = (int *)malloc(sizeof(int) * max_len);
    pre_order(root, ret, &cnt);
    *returnSize = cnt;
    return ret;
}
