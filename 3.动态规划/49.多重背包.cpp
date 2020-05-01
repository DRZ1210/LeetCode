/*************************************************************************
	> File Name: 49.多重背包.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月01日 星期五 10时46分57秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int V, n, val[MAX_N + 5], w[MAX_N + 5], ans[100005];

int main() {
    cin >> V >> n;
    int ind = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        while (z--) {
            w[++ind] = x;
            val[ind] = y;
        }
    }
    for (int i = 1; i <= ind; i++) {
        for (int j = V; j >= 1; j--) {
            if (j < w[i]) break;
            ans[j] = max(ans[j], ans[j - w[i]] + val[i]);
        }
    }
    cout << ans[V] << endl;
    return 0;
}
