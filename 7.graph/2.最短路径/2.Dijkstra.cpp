/*************************************************************************
	> File Name: 2.Dijkstra.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月26日 星期日 10时11分58秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <vector>
using namespace std;

/*
#define INF 0x3f3f3f3f

struct node {
    int now, dist;
    bool operator<(const node &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, dis[1005][1005], dis[1005][1005];

int main() {
    cin >> n >> m >> s;
    memset(dis, 0x3f, sizeof(dis));
    memset(dis, 0x3f, sizeof(dis));
    for (int i = 0; i < m; i++) {
        int a, b ,c;
        cin >> a >> b >> c;
        dis[a][b] = min(dis[a][b], c);
    }
    priority_queue<node> que;
    que.push({s, 0});
    while (!que.empty()) {
        node t = que.top();
        que.pop();
        if (dis[t.now] != INF) continue;
        dis[t.now] = t.dist;
        for (int i = 1; i <= n; i++) {
            if (dis[t.now][i] != INF) {
                que.push((node){i, t.dist + dis[t.now][i]});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        if (dis[i] != INF) {
            cout <<  dis[i];
        } else {
            cout << INF;
        }
    }
    cout << endl;
    return 0;
}*/

#define MAX_N 100000
#define MAX_M 200000
#define INF 0x3f3f3f3f

struct edge {
    int to, val, next;
};

struct node {
    int now, dist;
    bool operator< (const node &b) const {
        return this->dist > b.dist;
    }
};

int n, m, s, dis[MAX_N + 5], head[MAX_M + 5], edg_cnt;
edge edg[MAX_M + 5];

void add_edge(int a, int b, int c) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].val = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m >> s;
    for (int i = 0; i < m; i++) {
        int a, b ,c;
        cin >> a >> b >> c;
        add_edge(a, b, c);
    }
    priority_queue<node> que;
    que.push({s, 0});
    while (!que.empty()) {
        node tmp = que.top();
        que.pop();
        if (dis[tmp.now] != INF) continue;
        dis[tmp.now] = tmp.dist;
        for (int i = head[tmp.now]; i != -1; i = edg[i].next) {
            if (dis[edg[i].to] == INF) {
                que.push({edg[i].to, tmp.dist + edg[i].val});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << dis[i];
    }
    cout << endl;
    return 0;
}
