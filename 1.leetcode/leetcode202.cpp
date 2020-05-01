/*************************************************************************
	> File Name: leedcode202.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月27日 星期四 21时09分11秒
 ************************************************************************/
int get_next(int n) {
    int ans = 0;
    while (n) {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}

bool isHappy(int n){
    int p = n, q = n;
    do {
        p = get_next(p);
        q = get_next(get_next(q));
        if (q == p) break;
    } while (p - 1);
    return p == 1;
}
