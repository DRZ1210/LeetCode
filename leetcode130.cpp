/*************************************************************************
	> File Name: leetcode130.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月07日 星期六 14时30分05秒
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
        fa[find_ancestor(x)] = find_ancestor(y);
    }
};

class Solution {
public:
    int n, m;
    int ind(int i, int j) {
        return i * m + j + 1;
    }
    UnionSet s;
    void solve(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return ;
        n = board.size();
        m = board[0].size();
        s.init(n * m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') continue;
                if (i == 0 || i == n - 1) s.merge(ind(i, j), 0);
                if (j == 0 || j == m - 1) s.merge(ind(i, j), 0);
                if (i && board[i - 1][j] == 'O') {
                    s.merge(ind(i, j), ind(i - 1, j));
                }
                if (j && board[i][j - 1] == 'O') {
                    s.merge(ind(i, j), ind(i, j - 1));
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') continue;
                if (s.find_ancestor(ind(i, j)) == s.find_ancestor(0)) continue;
                board[i][j] = 'X';
            }
        }
    }
};
