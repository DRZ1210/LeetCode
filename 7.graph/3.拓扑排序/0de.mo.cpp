/*************************************************************************
	> File Name: 0de.mo.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月29日 星期三 12时24分32秒
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
#define TMP 100000007

struct edge {
    int to, next;
} edg[MAX_M + 5];

int n, m;
int head[MAX_N + 5], in_degree[MAX_N + 5], out_degree[MAX_N + 5], cnt[MAX_N + 5];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
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
            cnt[i] = 1;
        }
    }
    while (!que.empty()) {
        int tmp = que.front();
        que.pop();
        for (int i = head[tmp]; i != -1; i = edg[i].next) {
            int ind = edg[i].to;
            in_degree[ind]--;
            cnt[ind] += cnt[tmp];
            cnt[ind] %= TMP;
            if (in_degree[ind] == 0) {
                que.push(ind);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            ans += cnt[i];
            ans %= TMP;
        }
    }
    cout << ans << endl;


    return 0;
}
