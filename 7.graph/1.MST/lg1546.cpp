/*************************************************************************
	> File Name: lg1546.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月08日 星期三 19时38分46秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX_N 5000
#define MAX_M 400000

struct edge {
    int to, val, next;
};

struct node {
    int now, val;
    bool operator< (const node & b) const {
        return this->val > b.val;
    }
};

edge edg[MAX_M + 5];

int n, m, edg_cnt, head[MAX_N + 5], ans, already, visit[MAX_N + 5], arr[105][105];
int dis[MAX_N + 5]; // 表示到这个点的边的权值

void add_edg(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (i < j) {
                add_edg(i, j, arr[i][j]);
                add_edg(j, i, arr[i][j]);
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    while (!que.empty()) {
        node tmp = que.top();
        que.pop();
        if (visit[tmp.now] == 1) {
            continue;
        }
        visit[tmp.now] = 1;
        ans += tmp.val;
        already++;
        if (already == n) break;
        for (int i = head[tmp.now]; i != -1; i = edg[i].next) {
            if (visit[edg[i].to] == 0 && dis[edg[i].to] > edg[i].val) {
                dis[edg[i].to] = edg[i].val;
                que.push((node){edg[i].to, edg[i].val});
            }
        }
    }
    cout << ans << endl;

    return 0;
}
