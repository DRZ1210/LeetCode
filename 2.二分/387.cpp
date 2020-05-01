/*************************************************************************
	> File Name: 387.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年04月23日 星期四 12时10分31秒
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

typedef struct Node {
    int num, id;
} Node;

int n, m, people[100005];
Node apple[100005];

bool cmp(Node x, Node y) {
    return x.num < y.num;
}

int binarySearch(int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (apple[mid].num < x) {
            //当前的值为0
            head = mid + 1;
        } else {
            tail = mid;
        }
    }
    return head == n ? -1 : head;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> apple[i].num;
        apple[i].id = i + 1;
    }
    sort(apple, apple + n, cmp);

    int tmp;
    for (int i = 0; i < m; i++) {
        cin >> tmp;
        int ind = binarySearch(tmp);
        if (ind == -1) cout << 0 << endl;
        else cout << apple[ind].id << endl;
    }

    return 0;
}
