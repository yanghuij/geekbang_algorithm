//120. 三角形最小路径和
//https://leetcode-cn.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //贪心，出现负数时错误
        /*int j = 0;
        int ans = 0;

        if (triangle.size() == 0 || triangle[0].size() == 0)
            return ans;

        ans = triangle[0][0];
        for (int i = 1; i < triangle.size(); i++) {
            if (triangle[i][j] <= triangle[i][j + 1]) {
                ans += triangle[i][j];
            } else {
                ans += triangle[i][j + 1];
                j += 1;
            }
        }*/

        /*int n = triangle.size();
        vector<vector<int>> f(n, vector<int>(n, 0));

        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            f[i][0] = f[i - 1][0] + triangle[i][0];
            for (int j = 1; j < i; j++) {
                f[i][j] = min(f[i - 1][j], f[i - 1][j - 1]) + triangle[i][j];
            }
            f[i][i] = f[i - 1][i - 1] + triangle[i][i];
        }

        int ans = f[n - 1][0];
        for (int i = 1; i < n; i++) {
            ans = min(ans, f[n - 1][i]);
        }*/

        /*int n = triangle.size();

        if (triangle.size() == 0 || triangle[0].size() == 0)
            return 0;

        vector<vector<int>> f(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[i][j] = min(f[i + 1][j], f[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return f[0][0];*/

        int n = triangle.size();
        vector<int> f(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[j] = min(f[j], f[j + 1]) + triangle[i][j];
            }
        }

        return f[0];
    }
};
