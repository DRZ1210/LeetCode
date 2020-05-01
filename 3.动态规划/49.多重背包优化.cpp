/*************************************************************************
	> File Name: 49.多重背包优化.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月01日 星期五 11时15分18秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 100000

int V, n, w[MAX_N + 5], val[MAX_N + 5], ans[MAX_N + 5];
int t[20] = {1};

int main() {
    cin >> V >> n;
    for (int i = 1; i <= 20; i++) {
        t[i] = 2 * t[i - 1];
    }
    int ind = 0;
    for (int i = 1; i <= n; i++) {
        int x, y, z, tmp = 0;
        cin >> x >> y >> z;
        while (z > 0) {
            ind++;
            if (z > t[tmp]) {
                w[ind] = x * t[tmp];
                val[ind] = y * t[tmp];
                z -= t[tmp];
            } else {
                w[ind] = x * z;
                val[ind] = y * z;
                z = 0;
            }
            tmp++;
        }
    }
    for (int i = 1; i <= ind; i++) {
        for (int j = V; j > 0; j--) {
            if (j < w[i]) break;
            ans[j] = max(ans[j], ans[j - w[i]] + val[i]);
        }
    }
    cout << ans[V] << endl;

    return 0;
}



