/*************************************************************************
	> File Name: leetcode111.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 18时29分44秒
 ************************************************************************/
int minDepth(struct TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    if (!root->left || !root->right) {
        return minDepth(root->left ? root->left : root->right) + 1;
    }
    return fmin(minDepth(root->left), minDepth(root->right)) + 1;
}
