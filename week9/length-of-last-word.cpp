//58. ���һ�����ʵĳ���
//https://leetcode-cn.com/problems/length-of-last-word/
class Solution {
public:
    //����
    /*int lengthOfLastWord(string s) {
        int ans = 0;
        int len = 0;

        for (char ch : s) {
            if (ch == ' ') {
                if (len > 0) {
                    ans = len;
                    len = 0;
                }              
                
                continue;
            }

            len++;
        }

        if (len > 0) {
            ans = len;
        }

        return ans;
    }*/

    //����
    int lengthOfLastWord(string s) {
        int len = 0;
        int pos = s.length() - 1;

        while (s[pos] == ' ') {
            pos--;
        }

        while (pos >= 0 && s[pos--] != ' ') {
            len++;
        }

        return len;
    }
};