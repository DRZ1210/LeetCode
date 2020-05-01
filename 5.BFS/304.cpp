/*************************************************************************
	> File Name: 304.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月01日 星期三 18时24分25秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int dir[8][2] = {
    1, 2, 1, -2, 2, 1, 2, -1,
    -1, 2, -1, -2, -2, 1, -2, -1
};
char mmap[155][155];

struct node {
    int x, y, step;
};

int main() {
    queue<node> que;  
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                mmap[i][j] = 0;
                que.push({i, j, 0});
            }
        }
    }

    while (!que.empty()) {
        node tmp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (x < 1 || y < 1 || x > n || y > m) continue;
            if (mmap[x][y] == 'H') {
                cout << tmp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                que.push({x, y, tmp.step + 1});
                mmap[x][y] = 0;
            }
        }
    }

    return 0;
}
