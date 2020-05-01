/*************************************************************************
	> File Name: 44.最长上升子序列长度_优化.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月01日 星期五 13时15分15秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

int dp[MAX_N + 5];
int a[MAX_N + 5];
int len[MAX_N + 5], ans = 0;

int bs(int *arr, int l, int r, int x) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    if (arr[mid] < x) {
        return bs(arr, mid + 1, r, x);
    } else {
        return bs(arr, l, mid, x);
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i] = 1;
        len[i] = n + 1;
    }
    len[++ans] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = bs(len, 1, ans + 1, a[i]); //第一个大于等于a[i]的值
        len[dp[i]] = a[i];
        ans = max(dp[i], ans);
    }
    cout << ans << endl;

    return 0;
}

