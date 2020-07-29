/*************************************************************************
	> File Name: 635.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月29日 星期三 14时59分28秒
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define MAX_N 100
#define MAX_M 10000 

struct edge {
    int to, val, next;
} edg[MAX_M + 5];

int n, m, head[MAX_N + 5], in_degree[MAX_N + 5], out_degree[MAX_N + 5];
int c[MAX_N + 5], u[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        if (c[i]) que.push(i);
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].to = b;
        edg[i].val = c;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b] += 1;
        out_degree[a] += 1;
    }

    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].to, v = edg[i].val;
            if (c[t] > 0) {
                c[e] += v * c[t];
            }
            in_degree[e] -= 1;
            if (in_degree == 0) { 
                que.push(e);
                c[e] -= u[e];
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0 && c[i] > 0) {
            cout << i << " " << c[i] << endl;
            flag = 1;
        }
    }
    if (flag == 0) {
        cout << "NULL" << endl;
    }
    return 0;
}
