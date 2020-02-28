/*************************************************************************
	> File Name: leetcode268.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年02月28日 星期五 12时40分44秒
 ************************************************************************/
int missingNumber(int* nums, int numsSize){
    int ans = 0;
    for (int i = 0; i < numsSize; i++) ans += nums[i];
    int tmp =  numsSize* (numsSize + 1) >> 1;
    return tmp - ans;
}
