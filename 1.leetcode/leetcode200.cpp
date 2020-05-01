/*************************************************************************
	> File Name: leetcode200.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月07日 星期六 14时30分31秒
 ************************************************************************/
class UnionSet {
public:
    vector<int> fa;
    void init(int size) {
        fa.clear();
        for (int i = 0; i <= size; i++) fa.push_back(i);
    }
    int find_ancestor(int x) {
        return fa[x] = (fa[x] == x ? x : find_ancestor(fa[x]));
    }
    void merge(int x, int y) {
        int fx = find_ancestor(x), fy = find_ancestor(y);
        fa[fy] = fx;
    }
};

class Solution {
public:
    int n, m;
    int ind(int i, int j) {
        return i * m + j + 1;
    }
    UnionSet s;
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) return 0;
        n = grid.size();
        m = grid[0].size();
        s.init(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                if (i && grid[i - 1][j] == '1') s.merge(ind(i, j), ind(i - 1, j));
                if (j && grid[i][j - 1] == '1') s.merge(ind(i, j), ind(i, j - 1));
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') continue;
                ans += (s.fa[ind(i, j)] == ind(i, j));
            }
        }
        return ans;
    }
};
