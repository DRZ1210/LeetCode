/*************************************************************************
	> File Name: 391.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月23日 星期四 10时03分43秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;

int n, m, num[100005];
ll mmax, x;

int get_num(ll mid) {
    int cnt = 0;
    ll sum = num[0];
    for (int i = 1; i < n; i++) {
        sum += num[i];
        if (sum < mid) {
            continue;
        } else if (sum == mid) {
            cnt++;
            sum = 0;
        } else {
            cnt++;
            sum = num[i];
        }
    }
    if (sum) cnt++;
    return cnt;
}

int func() {
    ll head = x, tail = mmax;
    while (head < tail) {
        ll mid = (head + tail) >> 1;
        int cnt = get_num(mid);
        if (cnt <= m) {
            tail = mid;
        } else {
            head =  mid + 1;
        }
    }
    return head;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        mmax += num[i];
        x = x < num[i] ? num[i] : x;
    }

    cout << func() << endl;

    return 0;
}
