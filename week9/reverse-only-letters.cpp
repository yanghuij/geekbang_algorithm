//917. 仅仅反转字母
//https://leetcode-cn.com/problems/reverse-only-letters/
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i < j) {
            if (!isAlpha(s[i])) {
                i++;
            } else if (!isAlpha(s[j])) {
                j--;
            } else {
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;
                i++;
                j--;
            }
        }

        return s;
    }

private:
    bool isAlpha(char c) {
        if ((c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z'))
            return true;

        return false;
    }
};
