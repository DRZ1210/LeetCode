/*************************************************************************
	> File Name: leetcode1.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 09时53分27秒
 ************************************************************************/

class Solution {
public:
    typedef pair<int, int> PII;

    int binarySearch(vector<PII>& arr, int x, int l, int r) {
        int mid = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (arr[mid].first == x) return arr[mid].second;
            else if (arr[mid].first < x) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<PII> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(PII(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            int x = target - arr[i].first;
            int ind = binarySearch(arr, x, i + 1, nums.size() - 1);
            if (ind == -1) continue;
            int ind1 = arr[i].second;
            if (ind1 > ind) swap(ind1, ind);
            ret.push_back(ind1);
            ret.push_back(ind);
            break;   
        }
        return ret;
    }
};


class Solution {
public:
    typedef pair<int, int> PII;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<PII> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(PII(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        int p = 0, q = nums.size() - 1;
        while (1) {
            int tmp = arr[p].first + arr[q].first;
            if (tmp == target) break;
            else if (tmp < target) p += 1;
            else q -= 1;
        }
        int ind1 = arr[p].second, ind2 = arr[q].second;
        if (ind1 > ind2) swap(ind1, ind2);
        ret.push_back(ind1);
        ret.push_back(ind2);
        return ret;
    }
};

class Solution {
public:
    unordered_map<int, int> h;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(target - nums[i]) == h.end()) {
                h[nums[i]] = i;
                continue;
            }
            ret.push_back(h[target - nums[i]]);
            ret.push_back(i);
            break;
        }
        return ret;
    }
};
