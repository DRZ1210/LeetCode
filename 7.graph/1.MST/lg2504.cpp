/*************************************************************************
	> File Name: lg2504.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月08日 星期三 20时08分39秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX_N 1000
#define MAX_M 2000000

struct edge {
    int from, to;
    double val;
};

edge edg[1000005];

int n, m, already = 1, my_union[5005], monkey[505], xy[1005][2], edg_cnt;
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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> monkey[i];
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            double x = xy[i][0] - xy[j][0], y = xy[i][1] - xy[j][1];
            edg[edg_cnt].val = sqrt(x * x + y * y);
            edg_cnt++;
        }
    }
    sort(edg, edg + m, cmp);
    for (int i = 1; i <= m; i++) {
        int aroot = find_root(edg[i].from);
        int broot = find_root(edg[i].to);
        if (aroot != broot) {
            // 不会成环，该边可以加入
            already++;
            ans = max(ans, edg[i].val);
            my_union[aroot] = broot;
            if (already == m) break;
        }
    }
    int fin = 0;
    for (int i  = 1; i <= n; i++) {
        if (monkey[i] >= ans) {
            fin++;
        }
    }
    cout << fin << endl;

    return 0;
}

