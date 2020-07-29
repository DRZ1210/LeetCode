/*************************************************************************
	> File Name: 640.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月29日 星期三 11时52分52秒
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

#define MAX_N 5000
#define MAX_M 500000

struct edge {
    int to, next;
} edg[MAX_M + 5];

int n, m;
int head[MAX_N + 5], in_degree[MAX_N + 5], out_degree[MAX_N + 5], ans[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i <m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b] += 1;
        out_degree[a] += 1;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
            ans[i] = 1;
        }
    }
    while (!que.empty()) {
        int ind = que.front();
        que.pop();
        for (int i = head[ind]; i != -1; i = edg[i].next) {
            int e = edg[i].to;
            in_degree[e]--;
            ans[e] += ans[ind];
            ans[e] %= 100000007;
            if (in_degree[e] == 0) que.push(e);
        }
    }
    int fin = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            fin += ans[i];
            fin %= 100000007;
        }
    }
    cout << fin << endl;
    return 0;
}
