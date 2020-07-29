/*************************************************************************
	> File Name: 636.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年07月29日 星期三 15时23分30秒
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
#include <vector>
using namespace std;

#define MAX_N 100000
#define MAX_M 200000

struct edge {
    int to, next;
} edg[MAX_M + 5];

int n, m;
int head[MAX_N + 5], in_degree[MAX_N + 5], ans[MAX_N + 5];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].to = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b] += 1;
    }
    ans[1] = 1;
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        
    }


    return 0;
}
