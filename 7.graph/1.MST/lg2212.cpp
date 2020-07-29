/*************************************************************************
	> File Name: lg2212.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月15日 星期三 19时08分29秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
    int now;
    int val;
    bool operator< (const node &b) const {
        return this->val > b.val;
    }
};

int n, c, xy[2000005][2], visit[2005], already;
int dis[2005], ans;

int distance(int a, int b) {
    int x = xy[a][0] - xy[b][0];
    int y = xy[a][1] - xy[b][1];
    return x * x + y * y;
}

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        dis[i] = 999999999;
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    while (!que.empty()) {
        node tmp = que.top();
        que.pop();
        if (visit[tmp.now] == 1) continue;
        ans += tmp.val;
        visit[tmp.now] = 1;
        already++;
        if (already == n) break;
        for (int i = 1; i <= n; i++) {
            if (i == tmp.now) continue;
            int t = distance(tmp.now, i);
            if (t < c) continue;
            if (t < dis[i]) {
                dis[i] = t;
                que.push((node){i, t});
            }
        }
    }
    if (already == n) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }



    return 0;
}
