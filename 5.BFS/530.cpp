/*************************************************************************
	> File Name: 530.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月08日 星期三 18时10分42秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

struct node {
    int x, y;
};

int n, m, cnt;
char mmap[55][55];
int check[55][55];
int dir[4][2] = {
    -1, 0, 1, 0, 0, -1, 0, 1
};

int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '*') {
                que.push({i, j});
                mmap[i][j] = '.';
                check[i][j] = 1;
            }
        }
    }
    cin >> cnt;
    while (cnt--) {
        string t;
        cin >> t;
        int dir_num;
        if (t == "NORTH") {
            dir_num = 0;
        } else if (t == "SOUTH") {
            dir_num = 1;
        } else if (t == "WEST") {
            dir_num = 2;
        } else {
            dir_num = 3;
        }
        memset(check, 0, sizeof(check));
        int times = que.size();
        for (int i = 0; i < times; i++) {
            node tmp = que.front();
            que.pop();
            for (int j = 1; 1; j++) {
                int x = tmp.x + j * dir[dir_num][0];
                int y = tmp.y + j * dir[dir_num][1];
                if (mmap[x][y] != '.') break;
                if (!check[x][y]) {
                    que.push({x, y});
                    check[x][y] = 1;
                }
            }
        }
    }
    while (!que.empty()) {
        node tmp = que.front();
        que.pop();
        mmap[tmp.x][tmp.y] = '*';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
        }
        cout << endl;
    }


    return 0;
}
