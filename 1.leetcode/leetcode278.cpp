/*************************************************************************
	> File Name: leetcode278.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 23时27分28秒
 ************************************************************************/


// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int head = 1, tail = n, mid = 0;
        while (head < tail) {
            mid = ((head ^ tail) >> 1) + (head & tail);
            bool tmp = isBadVersion(mid);
            if (!tmp) head = mid + 1;
            else tail = mid;
        }
        return head;
    }
};
