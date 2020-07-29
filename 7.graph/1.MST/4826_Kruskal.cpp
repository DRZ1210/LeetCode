/*************************************************************************
	> File Name: 4826_Kruskal.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月15日 星期三 20时33分42秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;


struct edge {
    int from, to;
    long long val;
};
edge edg[2000005];
long long n, edg_cnt, num[2005], fa[2005], ans, already = 1;

bool cmp(edge a, edge b) {
    return a.val > b.val;
}

int find_root(int x) {
    if (fa[x] != x) {
        return fa[x] = find_root(fa[x]);
    }
    return x;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edg[edg_cnt].from = i;
            edg[edg_cnt].to = j;
            edg[edg_cnt++].val = num[i] ^ num[j];
        }
    }
    sort(edg, edg + edg_cnt, cmp);
    for (int i = 0; i < edg_cnt; i++) {
        int aroot = find_root(edg[i].from);
        int broot = find_root(edg[i].to);
        if (aroot != broot) {
            fa[aroot] = broot;
        }
        already++;
        ans += edg[i].val;
        if (already == n) break;
    }
    cout << ans << endl;

    return 0;
}
 
