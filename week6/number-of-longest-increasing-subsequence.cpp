//673. 最长递增子序列的个数
//https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    if (f[i] == f[j] + 1) {
                        count[i] += count[j];
                    } else if (f[i] < f[j] + 1) {
                        f[i] = f[j] + 1;
                        count[i] = count[j];
                    }
                }
            }
        }

        int length = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (length == f[i]) {
                ans += count[i];
            } else if (length < f[i]) {
                length = f[i];
                ans = count[i];
            }
        }

        return ans;
    }
};
