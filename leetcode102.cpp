/*************************************************************************
	> File Name: leedcode102.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 15时55分50秒
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

 *returnSize 表示第一位的大小
 */

int getTreeDepth(Node *root) {
    if (!root) return 0;
    int l = getTreeDepth(root->left);
    int r = getTreeDepth(root->right);
    return (l> r ? l : r) + 1;
}

void getCnt(Node *root, int k, int *cnt) {
    if (!root) return ;
    cnt[k]++;
    getCnt(root->left, k  + 1, cnt);
    getCnt(root->right, k + 1, cnt);
}

void getResult(Node *root, int k, int *cnt, int **ret) {
    if (!root) return root;
    ret[k][cnt[k]++] = root->val;
    getResult(root->left, k + 1, cnt, ret);
    getResult(root->right, k + 1, cnt, ret);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int depth = getTreeDepth(root);
    int **ret = (int **)malloc(sizeof(int *) * depth); 
    int *cnt = (int *)calloc(depth, sizeof(int));
    getCnt(root, 0, cnt); //cnt[i]数组中存储的是第i层数拥有的结点的个数
    for (int i = 0; i < depth; i++) {
        ret[i] = (int *)malloc(sizeof(int) * cnt[i]);
        cnt[i] = 0;
    }
    getResult(root, 0, cnt, ret);
    *returnSize = depth;
    *returnColumnSizes = cnt;
    return ret;
}




