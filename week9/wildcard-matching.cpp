//44. 通配符匹配
//https://leetcode-cn.com/problems/wildcard-matching/
class Solution {
public:
    bool isMatch(string s, string p) {
        /*f[i][j] 表示s的前i个字符，p的前j个字符，是否匹配
        *p[j]是a-z 的小写字母时，f[i][j] = f[i - 1][j - 1] && (s[i] == s[j])
        *p[j]是?，f[i][j] = f[i - 1][j - 1]
        *p[j]是*，f[i][j] = f[i][j - 1]   * 空字符串
        *                   f[i - 1][j]       * 任意字符串
        *f[0][0] = true, f[0][j] = true j前全是*
        *f[n][m]
        */

        int n = s.length();
        int m = p.length();

        s = " " + s;
        p = " " + p;

        vector<vector<bool>> f = vector(n + 1, vector(m + 1, false));
        f[0][0] = true;
        for (int j = 1; j <= m && (p[j] == '*'); j++) {
            f[0][j] = true;
        }

        for (int i = 1; i <= n; i++)
             for (int j = 1; j <= m; j++) {
                 if (p[j] == '?') {
                    f[i][j] = f[i - 1][j - 1];
                 } else if (p[j] == '*') {
                     f[i][j] = f[i][j - 1] || f[i - 1][j];
                 } else if (s[i] == p[j]) {
                     f[i][j] = f[i - 1][j - 1];
                 }
             }

        return f[n][m];
    }
};