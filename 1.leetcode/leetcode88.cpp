/*************************************************************************
	> File Name: leetcode88.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 22时43分21秒
 ************************************************************************/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind = m + n - 1;
        int x = m - 1, y = n - 1;
        while (x >= 0 || y >= 0) {
            if (y < 0 || (x >= 0 && nums1[x] >= nums2[y])) {
                nums1[ind--] = nums1[x--];
            } else {
                nums1[ind--] = nums2[y--];
            }
        }
    }
};
