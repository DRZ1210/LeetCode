/*************************************************************************
	> File Name: leetcode226.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 18时45分54秒
 ************************************************************************/
#define swap(a, b) { \
    __typeof(a) __tmp = a; \
    a = b, b = __tmp; \
}

struct TreeNode* invertTree(struct TreeNode* root){
    if (!root) return root;
    swap(root->left, root->right);
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    return root;
}
