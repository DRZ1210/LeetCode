/*************************************************************************
	> File Name: leetcode128.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年03月07日 星期六 14时29分30秒
 ************************************************************************/
class UnionSet {
public: 
    vector<int> fa, cnt;
    void init(int size) {
        for (int i = 0; i < size; i++) {
            fa.push_back(i);
            cnt.push_back(1);
        }
    }
    int find_ancestor(int x) {
        return fa[x] = (fa[x] == x ? x : find_ancestor(fa[x]));
    }
    void merge(int x, int y) {
        int fx = find_ancestor(x), fy = find_ancestor(y);
        if (fx == fy) return ;
        if (cnt[fx] < cnt[fy]) swap(fx, fy);
        fa[fy] = fx;
        cnt[fx] += cnt[fy];
    }
};


class Solution {
public:
    UnionSet s;
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        s.init(nums.size());
        unordered_map<int, int> kv;
        for (int i = 0; i < nums.size(); i++) {
            int tmp = nums[i];
            if (kv.find(tmp) != kv.end()) continue;
            if (kv.find(tmp - 1) != kv.end()) {
                s.merge(i, kv[tmp - 1]);
            }
            if (kv.find(tmp + 1) != kv.end()) {
                s.merge(i, kv[tmp + 1]);
            }
            kv[tmp] = i;
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, s.cnt[i]);
        }
        return ans;
    }
};
