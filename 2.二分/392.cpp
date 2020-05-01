/*************************************************************************
	> File Name: 392.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月22日 星期三 23时14分36秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, num[100005], mmax;

int get_num(int mid) {
    int now = 0, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (num[i] - num[now] < mid) {
            continue;
        } else {
            cnt++;
            now = i;
        }
    }
    return cnt;
}

int func() {
    int head = 1, tail = mmax;
    while (head < tail) {
        int mid = (head + tail + 1) >> 1;
        int cnt = get_num(mid);
        //printf("cnt = %d\n", cnt);
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
    }
    sort(num, num + n);
    mmax = num[n - 1] - num[0];

    cout << func() << endl;

    return 0;
}
