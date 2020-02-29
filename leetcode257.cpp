/*************************************************************************
	> File Name: leetcode257.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月29日 星期六 20时26分54秒
 ************************************************************************/
typedef struct TreeNode Node;

int getLeafNum(Node *root) {
    if (!root) return root;
    if (!root->left && !root->right) return 1;
    return getLeafNum(root->left) + getLeafNum(root->right);
}

int getResult(Node *root, int len, int k, char **ret, char *buffer) {
    if (!root) return 0;
    len += sprintf(buffer + len, "%d", root->val);
    buffer[len] = 0;
    if (!root->left && !root->right) {
        ret[k] = strdup(buffer);
        return 1;
    }
    len += sprintf(buffer + len, "->");
    int cnt = getResult(root->left, len, k , ret, buffer);
    cnt +=getResult(root->right, len, k + cnt, ret, buffer);
    return cnt;
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    int pathCnt = getLeafNum(root);
    char **ret = (char **)malloc(sizeof(char *) * pathCnt);
    int max_len = 1024;
    char *buffer = (char *)malloc(sizeof(char) * max_len);
    getResult(root, 0, 0, ret, buffer);
    *returnSize = pathCnt;
    return ret;
}
