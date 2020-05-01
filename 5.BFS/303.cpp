/*************************************************************************
	> File Name: 303.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月02日 星期四 10时27分46秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char mmap[1005][1005];
int ans[1005][1005];
int dir[4][2] = {
    1, 0, 0, 1, -1, 0, 0, -1
};

struct node {
    int x, y, step;
};

int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                ans[i][j] = -1;
                que.push({i, j, 0});
            }
        }
    }

    while (!que.empty()) {
        node tmp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m || ans[x][y]) continue;
            ans[x][y] = tmp.step + 1;
            que.push({x, y, tmp.step + 1});
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j - 1) cout << " ";
            if (ans[i][j] == -1) cout << 0;
            else cout << ans[i][j];
        }
        cout << endl;
    }


    return 0;
}
