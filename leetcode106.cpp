/*************************************************************************
	> File Name: leetcode106.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月03日 星期二 22时09分34秒
 ************************************************************************/
typedef struct TreeNode Node;

Node *getNewNode(int val) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int *reverse(int *arr, int n) {
    int *ret = (int *)malloc(sizeof(int) * n);
    for (int  i = 0; i  < n; i++) {
        ret[i] = arr[n - 1- i];
    }
    free(arr);
    return ret;
}

int getIndex(int *arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

Node *solve(int* post_order, int postorderSize, int* in_order, int inorderSize) {
    if (!inorderSize || !postorderSize) return NULL;
    Node *root = getNewNode(post_order[0]);
    int pos = getIndex(in_order, inorderSize, post_order[0]);
    if (pos > 0) {  //右子树存在
        root->right = solve(post_order + 1, pos, in_order, pos);
    }
    if (inorderSize - pos - 1) {  //左子树存在
        root->left = solve(post_order + pos + 1, inorderSize - pos - 1, in_order + pos + 1, inorderSize - pos - 1);
    }
    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize){
    int *in_order = reverse(inorder, inorderSize);
    int *post_order = reverse(postorder, postorderSize);
    return solve(post_order, postorderSize, in_order, inorderSize);
}
