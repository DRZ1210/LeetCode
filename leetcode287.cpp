/*************************************************************************
	> File Name: leetcode287.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 12时27分11秒
 ************************************************************************/
int findDuplicate(int* nums, int numsSize){
    int p = nums[0], q = nums[0];
    do {
        p = nums[p];
        q = nums[nums[q]];
    } while (p != q);
    int cnt = 0;
    do {
        cnt++;
        p = nums[p];
    } while (q != p);
    p = nums[0], q = nums[0];
    while (cnt--) p = nums[p];
    while (p != q) {
        p = nums[p];
        q = nums[q];
    }
    return p;
}
