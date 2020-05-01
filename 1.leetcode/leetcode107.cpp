/*************************************************************************
	> File Name: leetcode107.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 16时31分08秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int getDepth(Node *root) {
    if (!root) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l : r) + 1;
}

void getCnt(Node *root, int c, int *cnt) {
    if (!root) return ;
    cnt[c]++;
    getCnt(root->left, c  - 1, cnt);
    getCnt(root->right, c  - 1, cnt);
}

void getResult(Node *root, int k, int *cnt, int **ret) {
    if (!root) return ;
    ret[k][cnt[k]++] = root->val;
    getResult(root->left, k - 1, cnt, ret);
    getResult(root->right, k - 1, cnt, ret);
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * depth);
    int *cnt = (int *)calloc(depth, sizeof(int));
    getCnt(root, depth - 1, cnt);
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root, depth - 1, cnt, ret);
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;
}
