//557. 反转字符串中的单词 III
//https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
class Solution {
public:
    string reverseWords(string s) {
        int start = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (start != -1) {
                    reverse(s, start, i - 1);
                    start = -1;
                }
            } else {
                if (start == -1) {
                    start = i;
                }
            }
        }

        if (start != -1) {
            reverse(s, start, s.length() - 1);
        }

        return s;
    }

private:
    void reverse(string& s, int l, int r) {
        while (l < r) {
            char temp = s[l];
            s[l] = s[r];
            s[r] = temp;
            l++;
            r--;
        }
    }
};