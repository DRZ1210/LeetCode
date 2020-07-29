/*************************************************************************
	> File Name: lg2330.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月08日 星期三 19时11分27秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 300
#define MAX_M 100000

struct edge {
    int from, to, val;
};

edge edg[MAX_M + 5];

int n, m, already = 1, fa[MAX_N + 5], ans; 

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

int find_root(int x) {
    if (x != fa[x]) {
        return fa[x] = find_root(fa[x]);
    }
    return x;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> edg[i].from >> edg[i].to >> edg[i].val;
    }
    sort(edg, edg + m, cmp);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int aroot = find_root(edg[i].from);
        int broot = find_root(edg[i].to);
        if (aroot == broot) continue;
        fa[aroot] = broot;
        ans  = ans > edg[i].val ? ans : edg[i].val;
        if (already == n) break;
    }
    cout << n - 1 << " " << ans << endl;

    return 0;
}
