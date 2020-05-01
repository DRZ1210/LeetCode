/*************************************************************************
	> File Name: 390.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月23日 星期四 10时56分30秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, num[100005], mmax;

int get_num(int mid) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += num[i] / mid;
    }
    return cnt;
}

int func() {
    int head = 0, tail = mmax;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        int cnt = get_num(mid);
        if (cnt >= m) {
            head = mid;
        } else {
            tail = mid - 1;
        }
    }
    return head;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax = num[i];
    }

    cout << func() << endl;

    return 0;
}
