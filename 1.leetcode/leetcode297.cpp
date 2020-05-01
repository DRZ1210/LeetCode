/*************************************************************************
	> File Name: leetcode297.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月05日 星期四 11时50分08秒
 ************************************************************************/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "[]";
        string ans = "[";
        queue<TreeNode *> q;
        q.push(root);

        char str[100];

        while (!q.empty()) {
            TreeNode *top = q.front();
            q.pop();

            if (top) {
                q.push(top->left);
                q.push(top->right);
                sprintf(str, "%d", top->val);
                ans += str;
            } else {
                ans += "null";
            }
            ans += ",";
        }

        int end = ans.length() - 1;
        while (!(ans[end] >= '0' && ans[end] <= '9')) end--;
        string ret = ans.substr(0, end + 1);
        ret += "]";
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int len = data.size();
        if (len <= 2) return NULL;
        vector<TreeNode *> v;

        string word = "";
        for (int i = 1; i <= len - 2; i++) {
            if (data[i] == ',') {
                TreeNode *tmp = NULL;
                if (word == "null") {
                    v.push_back(tmp);
                } else {
                    int num = atoi(word.c_str());
                    tmp = new TreeNode(num);
                    v.push_back(tmp);
                }
                word = "";
            } else {
                word += data[i];
            }
        }
        
        int num = atoi(word.c_str());
        TreeNode *tmp = new TreeNode(num);
        v.push_back(tmp);

        int cnt = v.size();
        int p = 0, q = 1;
        while (q < cnt) {
            if (!v[p]) p++;
            else {
                v[p]->left = v[q];
                if (q + 1 < cnt) {
                    v[p]->right = v[q + 1];
                }
                p++;
                q += 2;
            }
        }

        return v[0];
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
