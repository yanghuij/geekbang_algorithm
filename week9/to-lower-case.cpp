//709. ×ª»»³ÉÐ¡Ð´×ÖÄ¸
//https://leetcode-cn.com/problems/to-lower-case/
class Solution {
public:
    string toLowerCase(string s) {
        string ans;
        for (char ch : s) {
            if (ch >= 'A' && ch <= 'Z') {
                //ans += ch - ('A' - 'a');
                ans += ch | 32;
            } else {
                ans += ch;
            }
        }

        return ans;
    }
};