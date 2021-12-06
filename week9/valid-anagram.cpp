//242. ��Ч����ĸ��λ��
//https://leetcode-cn.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> count(26, 0);
        for (char ch : s) {
            count[ch - 'a']++;
        }

        for (char ch : t) {
            count[ch - 'a']--;
            if (count[ch - 'a'] < 0) return false;
        }

        return true;
    }
};