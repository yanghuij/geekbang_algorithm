//47. 全排列 II
//https://leetcode-cn.com/problems/permutations-ii/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        used = vector<bool>(nums.size(), false);

        recur(nums, ans);

        return ans;
    }

private:
    void recur(vector<int>& nums, vector<vector<int>>& ans) {
        if (chosen.size() == nums.size()) {
            ans.push_back(chosen);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && used[i - 1] && nums[i] == nums[i - 1]) continue;
            if (!used[i]) {
                used[i] = true;
                chosen.push_back(nums[i]);
                recur(nums, ans);
                chosen.pop_back();
                used[i] = false;
            }
        }
    }

    vector<int> chosen;
    vector<bool> used;
};