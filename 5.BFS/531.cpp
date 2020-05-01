/*************************************************************************
	> File Name: 531.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月08日 星期三 19时04分31秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int status, step;
};

int n, num[25], arr[25][25], check[2200000];

void init() {
    int t = 1;
    for (int i = 0; i < 21; i++) {
        num[i] = t;
        t *= 2;
    }
}

int main() {
    init();
    cin >> n;
    int start_status = 0;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1) start_status += num[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0];
        for (int j = 1; j <= arr[i][0]; j++) {
            cin >> arr[i][j];
            arr[i][24] += num[arr[i][j]];
        }
    }

    queue<node> que;
    que.push({start_status, 0});
    check[start_status] = 1;
    while (!que.empty()) {
        node tmp = que.front();
        que.pop();
        if (tmp.status == 8) {
            cout << tmp.step << endl;
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if ((tmp.status & num[i]) == 0) {
                int status_tmp =  tmp.status + num[i];
                status_tmp &= ~(arr[i][24]);
                if (check[status_tmp] == 0) {
                    check[status_tmp] = 1;
                    que.push({status_tmp, tmp.step + 1});
                }
            }
        }
    }


    return 0;
}
