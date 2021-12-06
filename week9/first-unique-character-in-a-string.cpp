//387. 字符串中的第一个唯一字符
//https://leetcode-cn.com/problems/first-unique-character-in-a-string/
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> sMap;

        for (char ch : s) {
            sMap[ch]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (sMap[s[i]] == 1) return i;
        }

        return -1;
    }
};