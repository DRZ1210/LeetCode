/*************************************************************************
	> File Name: leetcode684.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月07日 星期六 14时29分03秒
 ************************************************************************/
class UnionSet {
public:
    vector<int> fa;
    void init(int size) {
        //fa.clear();
        for (int i = 0; i <= size; i++) fa.push_back(i);
    }
    int find_ancestor(int x) {
        return fa[x] = (fa[x] == x ? x : find_ancestor(fa[x]));
    }
    int merge(int x, int y) {
        int fx = find_ancestor(x), fy = find_ancestor(y);
        if (fx == fy) return 1;
        fa[fx] = fy;
        return 0;
    }
};


class Solution {
public:
    UnionSet s;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        s.init(edges.size());
        vector<int> ans;
        for (int i = 0; i < edges.size(); i++) {
            if (!s.merge(edges[i][0], edges[i][1])) continue;
            ans.clear();
            ans.push_back(edges[i][0]);
            ans.push_back(edges[i][1]);
        }
        return ans;
    }
};
