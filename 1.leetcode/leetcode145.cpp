/*************************************************************************
	> File Name: leetcode145.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月05日 星期四 11时48分01秒
 ************************************************************************/
typedef struct TreeNode Node;

void post_order(Node *root, int *ret, int *cnt) {
    if (!root) return ;
    post_order(root->left, ret, cnt);
    post_order(root->right, ret, cnt);
    ret[(*cnt)++] = root->val;
}


int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int max_len = 1024, cnt = 0;
    int *ret = (int *)malloc(sizeof(int) * max_len);
    post_order(root, ret, &cnt);
    *returnSize = cnt;
    return ret;
}
