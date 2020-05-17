/*************************************************************************
	> File Name: leetcode38.cpp
	> Author: DRZ 
	> Mail: 1927157164@qq.com
	> Created Time: 2020年05月17日 星期日 22时31分11秒
 ************************************************************************/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        string ret;
        char num = str[0];
        int cnt = 1;
        for (int i = 1; i < str.length(); i++) {
            if (str[i] == num) {
                cnt++;
                continue;
            } else {
                ret.append(to_string(cnt));
                ret = ret + num;
                num = str[i];
                cnt = 1;
            }
        }
        ret.append(to_string(cnt));
        ret = ret + str[str.length() - 1];
        return ret;
    }
};
