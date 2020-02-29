/*************************************************************************
	> File Name: leetcode235.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 19时31分36秒
 ************************************************************************/
typedef struct TreeNode Node;

Node *__lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root->val == p->val) return p;
    if (root->val == q->val) return q;
    if (root->val  > p->val && root->val < q->val) return root;
    if (p->val > root->val) return  __lowestCommonAncestor(root->right, p, q);
    return __lowestCommonAncestor(root->left, p, q);
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) return root;
    if (p->val == q->val) return p;
    if (p->val > q->val) {
        Node *tmp  =p;
        p = q;
        q = tmp;
    }   
    return __lowestCommonAncestor(root, p, q);
}

 /*解法2
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < p->val && root->val < q->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}*/

/*解法3
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (!root) return root;
    if ((root->val - p->val) * (root->val - q->val)  <= 0) return root;
    else if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return lowestCommonAncestor(root->right, p, q);
    }
}*/
