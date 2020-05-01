/*************************************************************************
	> File Name: 527.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月02日 星期四 12时18分07秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, d;
char mmap[105][105];
int check[105][105][105];
int dir[4][2] = {
    1, 0, 0, 1, -1, 0, 0, -1
};

struct node {
    int x, y, step, D;
};

int main() {
    cin >> m >> n >> d;
    for (int i = 1; i <= m; i++) {
        cin >> &mmap[i][1];
    }



    return 0;
}
