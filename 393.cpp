/*************************************************************************
	> File Name: 393.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月22日 星期三 22时24分09秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int n, k;
double num[10005], mmax;

int func1(double mid) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += num[i] / mid;
    }
    return ans;
}

double func() {
    double head = 0, tail = mmax;
    while (tail - head > 0.001) {
        double mid = (head + tail) / 2;
        int cnt = func1(mid);
        if (cnt < k) {
            tail = mid;
        } else {
            head = mid;
        }
    }
    return head;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        mmax = max(mmax, num[i]);
    }
    double ans = func();
    printf("%d.%d%d\n", (int)ans, (int)(ans * 10) % 10, (int)(ans * 100) % 10);
    return 0;
}
