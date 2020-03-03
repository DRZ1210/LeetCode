/*************************************************************************
	> File Name: leetcode105.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月03日 星期二 22时08分50秒
 ************************************************************************/
typedef struct TreeNode Node;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int getPos(int *arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    //int len = inorderSize;
    //if (!preorder || !inorder) return NULL;
    if (!preorderSize || !inorderSize) return NULL; 
    Node *root = getNewNode(preorder[0]);
    int pos = getPos(inorder, inorderSize, preorder[0]);
    if (pos > 0) {
        root->left = buildTree(preorder + 1, pos, inorder, pos);
    } 
    if (inorderSize - pos - 1> 0) {
        root->right = buildTree(preorder + pos + 1, inorderSize - pos - 1, inorder + pos + 1, inorderSize - pos - 1);
    }
    return root;
}
