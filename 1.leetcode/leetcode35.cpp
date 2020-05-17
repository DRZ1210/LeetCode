/*************************************************************************
	> File Name: leetcode35.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 22时16分10秒
 ************************************************************************/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int head = 0, tail = nums.size();
        while (head < tail) {
            int mid = (head + tail) >> 1;
            if (nums[mid] < target) head = mid + 1;
            else tail = mid;
        }
        return head;
    }
};
