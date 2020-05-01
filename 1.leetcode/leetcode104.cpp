/*************************************************************************
	> File Name: leetcode104.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 16时15分33秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b) {
    return a > b ? a : b;
}

int maxDepth(struct TreeNode* root){
    if (!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
}
