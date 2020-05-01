/*************************************************************************
	> File Name: 305.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月02日 星期四 10时55分40秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x, y;
char mmap[105][105];
int dir[8][2] = {
    1, 0, 0, 1, -1, 0, 0, -1,
    1, 1, 1, -1, -1, 1, -1, -1
};

struct node {
    int x, y, step;
};

int main() {
    cin >> m >> n >> y >> x;
    queue<node> que;
    que.push({n - x + 1, y, 0});

    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    mmap[n - x + 1][y] = '*';

    int ans = 0;
    while (!que.empty()) {
        node tmp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m) continue;
            if (mmap[x][y] == '.') {
                ans = tmp.step + 1;
                mmap[x][y] = '*';
                que.push({x, y, tmp.step + 1});
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
