/*************************************************************************
	> File Name: leetcode350.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 23时53分17秒
 ************************************************************************/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> h;
        for (int i = 0; i < nums1.size(); i++) {
            h[nums1[i]] += 1;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (h.find(nums2[i]) == h.end()) continue;
            if (h[nums2[i]] == 0) continue;
            ret.push_back(nums2[i]);
            h[nums2[i]] -= 1;
        }
        return ret;
    }
};
