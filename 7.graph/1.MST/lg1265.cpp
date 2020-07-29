/*************************************************************************
	> File Name: lg1265.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月15日 星期三 18时05分58秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

#define MAX_N 5000

struct node {
    int now;
    double val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
}; 

int n, xy[MAX_N + 5][2], vis[MAX_N + 5];
double dis[MAX_N + 5];

double distance(int a, int b) {
    long long x = xy[a][0] - xy[b][0];
    long long y = xy[a][1] - xy[b][1];
    return sqrt(x * x + y * y);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dis[i] = 999999999;
    }
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    dis[1] = 0;
    double ans = 0;
    int already = 0;
    while (!que.empty()) {
        node tmp = que.top();
        que.pop();
        if (vis[tmp.now] == 1) {
            continue;
        }
        vis[tmp.now] = 1;
        ans += tmp.val;
        already++;
        if (already == n) break;
        for (int i = 1; i <= n; i++) {
            if (i == tmp.now) continue;
            double t = distance(tmp.now, i);
            if (t < dis[i]) {
                dis[i] = t;
                que.push((node){i, t});
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
