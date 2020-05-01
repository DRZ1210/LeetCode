/*************************************************************************
	> File Name: 47.01背包.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月01日 星期五 08时32分51秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 100

int V, n, v[MAX_N + 5], w[MAX_N + 5], ans[MAX_N + 5][10005];

int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i =  1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (j < w[i]) {
                ans[i][j] = ans[i - 1][j];
            } else {
                ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    cout << ans[n][V] << endl;

    return 0;
}
