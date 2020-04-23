/*************************************************************************
	> File Name: 389.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月23日 星期四 10时31分50秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, num[100005], mmax;

int get_num(int mid) {
    int cnt = 1, now = 0;
    for (int i = 1; i < n; i++) {
        if (num[i] - num[now] < mid) continue;
        cnt++;
        now = i;
    }
    return cnt;
}

int func() {
    int head = 1, tail = mmax;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        int cnt = get_num(mid);
        if (cnt < m) {
            tail = mid - 1;
        } else {
            head = mid;
        }
    }
    return head;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n);
    mmax = num[n - 1] - num[0];

    cout << func() << endl;

    return 0;
}
