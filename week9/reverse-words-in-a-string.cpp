//151. ��ת�ַ�����ĵ���
//https://leetcode-cn.com/problems/reverse-words-in-a-string/
class Solution {
public:
    /*string reverseWords(string s) {
        string ans;
        int subLen;
        int i = s.length() - 1;

        while (i >= 0) {
            if (s[i] == ' ') {
                if (subLen) {
                    if (ans.length() > 0) {
                        ans += " " + s.substr(i + 1, subLen);
                    } else {
                        ans = s.substr(i + 1, subLen);
                    }
                    subLen = 0;
                }
            } else {
                subLen++;
            }
            i--;
        }

        if (subLen) {
            if (ans.length() > 0) {
                ans += " " + s.substr(0, subLen);
            } else {
                ans = s.substr(0, subLen);
            }
        }

        return ans;
    }*/

    string reverseWords(string s) {
        int i = 0;
        int len = 0;

        //ɾ��ͷ���Ŀո�
        while (s[i] == ' ') {
            len++;
            i++;
        }
        s.erase(s.begin(), s.begin() + len);

        //ɾ��β���Ŀո�
        i = s.length() - 1;
        len = 0;
        while (s[i] == ' ') {
            len++;
            i--;
        }
        s.erase(s.end() - len, s.end());

        //��ת�ַ���
        reverseString(s, 0, s.length() - 1);

        //ɾ���м�Ķ���ո�,��ת����
        int start = 0;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverseString(s, start, i - 1);

                len = 0;
                int j = i + 1;
                while (j < s.length() && s[j] == ' ') {
                    len++;
                    j++;
                }

                if (len) {
                    s.erase(s.begin() + i, s.begin() + i + len);                 
                }

                start = i + 1;
            }
        }

        /*int start = 0;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                reverseString(s, start, i - 1);
                start = i + 1;
            }
        }*/

        reverseString(s, start, i - 1);

        return s;
    }

private:
    void reverseString(string& s, int start, int end) {
         while (start < end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }

};
