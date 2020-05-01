/*************************************************************************
	> File Name: 48.完全背包_滚动数组.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月01日 星期五 10时37分47秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 10000

int V, n, w[MAX_N + 5], val[MAX_N + 5], ans[MAX_N + 5];

int main() {
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            if (j < w[i])  continue;
            ans[j] = max(ans[j], ans[j - w[i]] + val[i]);
        }
    }
    cout << ans[V] << endl;


    return 0;
}
