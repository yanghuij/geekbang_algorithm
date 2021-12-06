//14. 最长公共前缀
//https://leetcode-cn.com/problems/longest-common-prefix/description/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i = 0;

        if (!strs.size()) {
            return "";
        }
        
        while (i < strs[0].length()) {
            bool same = true;

            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                    same  = false;
                }
            }

            if (!same) break;
            i++;
        }

        return (i > 0) ? strs[0].substr(0, i) : "";
    }
};
