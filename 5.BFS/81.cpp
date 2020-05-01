/*************************************************************************
	> File Name: 81.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月02日 星期四 11时28分18秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char mmap[2005][2005];
int check[2005][2005];
int dir[4][2] = {
    1, 0, 0, 1, -1, 0, 0, -1
};

struct node {
    int x, y, step, flag;
};

int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                check[i][j] = 1;
                que.push({i, j, 0, 0});
            }
        }
    }

    while (!que.empty()) {
        node tmp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = tmp.x + dir[i][0];
            int y = tmp.y + dir[i][1];
            if (check[x][y] & 1 && !tmp.flag) continue;
            if (check[x][y] & 2 && tmp.flag) continue;
            
            if (tmp.flag == 1 && mmap[x][y] == 'T') {
                cout << tmp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.' || mmap[x][y] == 'T' || mmap[x][y] == 'S') {
                check[x][y] += tmp.flag + 1;
                que.push({x, y, tmp.step + 1, tmp.flag});
            }
            if (mmap[x][y] == 'P') {
                check[x][y] = 3;
                que.push({x, y, tmp.step + 1, 1});
            }
        }
    }

    return 0;
}
