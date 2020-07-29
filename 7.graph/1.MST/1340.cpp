/*************************************************************************
	> File Name: 1340.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月15日 星期三 18时54分42秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


struct edge {
    int from, to, val, mtime;
};

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

edge edg[60005];
int n, m, fa[205];

int find_root(int x) {
    if (fa[x] != x) {
        return fa[x] = find_root(fa[x]);
    }
    return x;
}

void init_union() {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edg[i].from >> edg[i].to >> edg[i].val;
        edg[i].mtime = i;
    }
    sort(edg, edg + m, cmp);
    for (int i = 0; i < m; i++) {
        int ans = 0, already = 1;
        init_union();
        for (int j = 0; j < m; j++) {
            if (edg[j].mtime <= i) {
                int aroot = find_root(edg[j].from);
                int broot = find_root(edg[j].to);
                if (aroot != broot) {
                    fa[aroot] = broot;
                    ans += edg[j].val;
                    already++;
                    if (already == n) break;
                }
            }
        }
        if (already == n) {
            cout << ans << endl;
        } else {
            cout << -1 << endl;
        }
    }
    return 0;
}
