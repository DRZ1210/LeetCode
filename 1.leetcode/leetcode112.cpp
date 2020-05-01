/*************************************************************************
	> File Name: leetcode112.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 18时36分37秒
 ************************************************************************/
bool hasPathSum(struct TreeNode* root, int sum){
    if (!root) return false;
    if (!root->left && !root->right) return root->val == sum;
    return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val); 
}

