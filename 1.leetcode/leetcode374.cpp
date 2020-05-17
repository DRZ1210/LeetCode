/*************************************************************************
	> File Name: leetcode374.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 23时56分18秒
 ************************************************************************/

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int bs(int n) {
        int head = 1, tail = n, mid;
        while (head <= tail) {
            mid = ((head ^ tail) >> 1) + (head & tail);
            int tmp = guess(mid);
            if (tmp == 0) return mid;
            else if (tmp == 1) head = mid + 1;
            else tail = mid - 1;
        }
        return -1;
    }

    int guessNumber(int n) {
        return bs(n);
    }
};
