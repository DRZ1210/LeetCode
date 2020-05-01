/*************************************************************************
	> File Name: 44.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月01日 星期五 12时10分47秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX_N 1000000

int arr[MAX_N + 5], len[MAX_N + 5];

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        len[i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        int val = arr[i];
        for (int j = 1; j < i; j++) {
            if (arr[j] >= val) continue;
            len[i] = max(len[i], len[j] + 1);
        }
        ans = max(ans, len[i]);
    }
    cout << ans << endl;

    return 0;
}
