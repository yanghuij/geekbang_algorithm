//1074. 元素和为目标值的子矩阵数量
class Solution {
public:
    //超时
    /*int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> preSum(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preSum[i][j] = preSum[i - 1][j] + preSum[i][j - 1] - preSum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= i; k++) {
                    for (int l = 1; l <= j; l++) {
                        int sum = preSum[i][j] - preSum[i][l - 1] - preSum[k - 1][j] + preSum[k - 1][l - 1];
                        if (sum == target) ans++;
                    }
                }
            }
        }

        return ans;
    }*/

    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 0; i < m; i++) {
            vector<int> sumCol(n, 0);
            for (int j = i; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    sumCol[k] += matrix[j][k];
                }

                ans += subarraySum(sumCol, target);
            }
        }

        return ans;
    }

private:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int preSum = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++) {
            preSum += nums[i];

            if (preSum == k) {
                ans++;
            }
            
            if (m.find(preSum - k) != m.end()) {
                ans += m[preSum - k];
            }
            
            m[preSum]++;
        }

        return ans;
    }
};