//438. 找到字符串中所有字母异位词
//https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
class Solution {
public:
    //超时
    /*vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int pLen = p.length();
        if (pLen > s.length()) return ans;

        string pOrder = p;
        sort(pOrder.begin(), pOrder.end());

        for (int i = 0; i < s.length() - pLen + 1; i++) {
            string subS = s.substr(i, pLen);
            sort(subS.begin(), subS.end());

            if (subS == pOrder) {
                ans.push_back(i);
            }
        }

        return ans;
    }*/

    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int sLen = s.length();
        int pLen = p.length();

        if (pLen > sLen) return ans;

        vector<int> sCount(26, 0);
        vector<int> pCount(26, 0);
        for (int i = 0; i < pLen; i++) {
            sCount[s[i] - 'a']++;
            pCount[p[i] - 'a']++;
        }

        if (sCount == pCount) {
            ans.push_back(0);
        }

        for (int i = 1; i < s.length() - pLen + 1; i++) {
            sCount[s[i - 1] - 'a']--;
            sCount[s[i + pLen - 1] - 'a']++;
            if (sCount == pCount) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};