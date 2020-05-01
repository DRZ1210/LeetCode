/*************************************************************************
	> File Name: leetcode547.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月07日 星期六 14时31分16秒
 ************************************************************************/
class UnionSet {
public:
    vector<int> fa;
    void init(int size) {
        fa.clear();
        for (int i = 0; i < size; i++) fa.push_back(i);
    }
    int find_ancestor(int x) {
        return fa[x] = (fa[x] == x ? x : find_ancestor(fa[x]));
    }
    void merge(int x, int y) {
        fa[find_ancestor(x)] = find_ancestor(y);
    }
    int get_ans() {
        int ans = 0;
        for (int i = 0; i < fa.size(); i++) {
            if (fa[i] == i) ++ans;
        }
        return ans;
    }
};

class Solution {
public:
    UnionSet s;
    int findCircleNum(vector<vector<int>>& M) {
        if (M.size() == 0 || M[0].size() == 0) return 0;
        int n = M.size();
        s.init(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (M[i][j]) s.merge(i, j);
            }
        }
        return s.get_ans();
    }
};
