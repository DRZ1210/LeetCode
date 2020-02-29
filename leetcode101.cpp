/*************************************************************************
	> File Name: leedcode101.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 16时13分41秒
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

/*
1. 逗号表达式的优先级在所有的运算符中是最低的（注意，比复制表达式的优先级还要低）
2. 逗号表达式中会包含多个子运算表达式，表达式的计算过程是从左到右
3. 逗号表达式 整体的表达式的值 等于 最后一个表达式的值
*/

bool isSameTree(Node *p, Node *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
}


bool isSymmetric(struct TreeNode* root){
    if (!root) return true;
    return isSameTree(root->left, root->right);
}
