//516. �����������
//https://leetcode-cn.com/problems/longest-palindromic-subsequence/
class Solution {
public:
    /*���� DP �Ļ�������Ϊ��
    ��С����ö�������С len
    ö��������˵� l��ͬʱ���������С len����˵����������Ҷ˵� r = l + len - 1
    ͨ��״̬ת�Ʒ����� f[l][r]��ֵ
    */
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> f(n, vector<int>(n, 0));

        //�ο����
        //f[i][j]Ϊ��i��j����Ļ��������еĳ��ȣ���ת�Ʒ���Ϊ
        //f[i][j] = f[i - 1][j - 1]  s[i]=s[j]
        //f[i][j] = max(f[i][j - 1], f[i + 1][j])  s[i]������s[j]          
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
