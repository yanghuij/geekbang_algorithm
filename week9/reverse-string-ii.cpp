//541. ·´×ª×Ö·û´® II
//https://leetcode-cn.com/problems/reverse-string-ii/
class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 0;
        while (i * k < s.length()) {
            reverse(s, i * k, (s.length() - i * k >= k) ? (i * k + k - 1) : (s.length() - 1));
            i += 2;
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