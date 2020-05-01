/*************************************************************************
	> File Name: 47.01背包_滚动数组.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月01日 星期五 08时38分47秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 100

int V, n, val[MAX_N + 5], w[MAX_N + 5], ans[10005];

int main() {
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> val[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = V; j > 0; j--) {
            if (j < w[i]) break;
            ans[j] = max(ans[j], ans[j - w[i]] + val[i]);
        }
    }
    cout << ans[V] << endl;


    return 0;
}
