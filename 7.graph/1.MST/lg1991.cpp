/*************************************************************************
	> File Name: lg1991.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月08日 星期三 20时45分20秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

struct edge {
    int from, to;
    double val;
};

edge edg[250005];

int n, m, already = 1, my_union[5005], xy[505][2], edg_cnt;
double ans;

bool cmp(edge a, edge b) {
    return a.val < b.val;
}

int find_root(int x) {
    if (x != my_union[x]) {
        return my_union[x] = find_root(my_union[x]);
    }
    return x;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            double x = xy[i][0] - xy[j][0], y = xy[i][1] - xy[j][1];
            double t = sqrt(x * x + y * y);
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            edg[edg_cnt].val = t;
            edg_cnt++;
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    for (int i = 0; i < m; i++) {
        int aroot = find_root(edg[i].from);
        int broot = find_root(edg[i].to);
        if (aroot != broot) {
            // 不会成环，该边可以加入
            already++;
            ans = max(ans, edg[i].val);
            my_union[aroot] = broot;
            if (already == m - n + 1) break;
        }
    }
    // cout << ans << endl;
    printf("%.2f\n", ans);
    return 0;
}


