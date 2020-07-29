/*************************************************************************
	> File Name: 641.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月29日 星期三 11时22分12秒
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

#define MAX_N 2000
#define MAX_M 400000

struct edge {
    int to, next;
} edg[MAX_M + 5];

struct MyInt {
    int now;
    bool operator< (const MyInt &b) const {
        return this->now > b.now;
    }
};

int head[MAX_N + 5], in_degree[MAX_N + 5], edg_cnt;

void add_edge(int a, int b) {
    edg[edg_cnt].to = b;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b);
        in_degree[b] += 1;
    }
    priority_queue<MyInt> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push((MyInt){i});
        }
    }
    int flag = 0;
    while (!que.empty()) {
        int ind = que.top().now;
        que.pop();
        if (flag != 0) cout << " ";
        flag = 1;
        cout << ind;
        for (int i = head[ind]; i != -1; i = edg[i].next) {
            in_degree[edg[i].to] -= 1;
            if (in_degree[edg[i].to] == 0) {
                que.push((MyInt){edg[i].to});
            }
        }
    }
    cout << endl;
    return 0;
}
