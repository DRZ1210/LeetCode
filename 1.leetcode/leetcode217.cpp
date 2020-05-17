/*************************************************************************
	> File Name: leetcode217.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 22时46分44秒
 ************************************************************************/

class Solution {
public:
    unordered_map<int, int> h;
    bool containsDuplicate(vector<int>& nums) {
        int flag = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(nums[i]) == h.end()) {
                h[nums[i]] = 1;
            } else {
                flag = 1;
            }
        }
        return flag;
    }
};
