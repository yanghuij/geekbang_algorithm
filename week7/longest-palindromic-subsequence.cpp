//516. 最长回文子序列
//https://leetcode-cn.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    /*区间 DP 的基本流程为：
    从小到大枚举区间大小 len
    枚举区间左端点 l，同时根据区间大小 len和左端点计算出区间右端点 r = l + len - 1
    通过状态转移方程求 f[l][r]的值
    */
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> f(n, vector<int>(n, 0));

        //参考题解
        //f[i][j]为从i到j的最长的回文子序列的长度，则转移方程为
        //f[i][j] = f[i - 1][j - 1]  s[i]=s[j]
        //f[i][j] = max(f[i][j - 1], f[i + 1][j])  s[i]不等于s[j]          
        for (int i = 0; i < n; i++) f[i][i] = 1;

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < n - len + 1; l++) {
                int r = l + len - 1;

                if (s[l] == s[r]) {
                    f[l][r] = f[l + 1][r - 1] + 2;
                } else {
                    f[l][r] = max(f[l + 1][r], f[l][r - 1]);
                }
            }
        }

        return f[0][n - 1];
    }
};
