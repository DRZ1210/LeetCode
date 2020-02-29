/*************************************************************************
	> File Name: leetcode110.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 16时55分09秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int getDepth(struct TreeNode *root) {
    if (!root) return 0;
    int l = getDepth(root->left), r = getDepth(root->right);
    return (l > r ? l  : r) + 1;
}

bool isBalanced(struct TreeNode* root){
    if (!root) return true;
    int l = getDepth(root->left), r = getDepth(root->right);
    if (abs(l - r) > 1) return false;
    return isBalanced(root->left) && isBalanced(root->right);
}
