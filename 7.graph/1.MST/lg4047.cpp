/*************************************************************************
	> File Name: lg4047.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月15日 星期三 20时01分36秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;

struct edge {
    int from, to;
    double val;
};
edge edg[500005];

int n, k, edg_cnt, xy[1005][2], fa[1005], already = 1;

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

int find_root(int x) {
    if (fa[x] != x) {
        return fa[x] = find_root(fa[x]);
    }
    return x;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int x = xy[i][0] - xy[j][0], y = xy[i][1] - xy[j][1];
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            edg[edg_cnt++].val = sqrt(x * x + y * y);
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    int flag = 0;
    for (int i = 0; i < edg_cnt; i++) {
        int aroot = find_root(edg[i].to);
        int broot = find_root(edg[i].from);
        if (aroot != broot) {
            if (flag == 1) {
                printf("%.2f\n", edg[i].val);
                break;
            }
            fa[aroot] = broot;
            already++;
            if (already == n - k + 1) {
                flag = 1;
            }
        }
    }
    return 0;
}
