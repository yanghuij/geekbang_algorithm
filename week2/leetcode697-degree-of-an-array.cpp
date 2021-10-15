//697. 数组的度
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int ans = nums.size();
        int maxDegree = 0;
        unordered_map<int, array<int,3>> m;

        for (int i = 0; i < nums.size(); i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]][0] = 1;
                m[nums[i]][1] = i;
                m[nums[i]][2] = i;
            } else {
                m[nums[i]][0] += 1;
                m[nums[i]][2] = i;
            }

            if (m[nums[i]][0] > maxDegree) {
                maxDegree = m[nums[i]][0];
            }
        }

        for (const pair<int, array<int,3>>& p : m) {
            if (p.second[0] == maxDegree && ans > (p.second[2] - p.second[1] + 1)) {
                ans = p.second[2] - p.second[1] + 1;
            }
        }

        return ans;
    }
};