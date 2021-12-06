//205. Í¬¹¹×Ö·û´®
//https://leetcode-cn.com/problems/isomorphic-strings/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smt;
        unordered_map<char, char> tms;

        if (s.length() != t.length()) {
            return false;
        }
        
        for (int i = 0; i < s.length(); i++) {
            if (tms.find(t[i]) == tms.end()) {
                tms[t[i]] = s[i];
            } else if (tms[t[i]] != s[i]) {
                return false;
            }

            if (smt.find(s[i]) == smt.end()) {
                smt[s[i]] = t[i];
            } else if (smt[s[i]] != t[i]) {
                return false;
            }
        }

        return true;
    }
};