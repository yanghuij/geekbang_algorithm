//55. 跳跃游戏
//https://leetcode-cn.com/problems/jump-game/
class Solution {
public:
    /*暴力
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n, false);
        f[0] = true;

        for (int i = 0; i < n; i++) {
            if (f[i]) { //i可达，从i出发可到哪里
                for (int j = 1; j <= nums[i] && j < (n - i); j++) {
                    f[i + j] = true;
                }
            }
        }

        return f[n - 1];
    }*/

    //贪心，最远能到的位置
    /*bool canJump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0;

        for (int i = 0; i < n; i++) {
            if (farthest < i) return false;
            farthest = max(farthest, i + nums[i]);
        }

        return true;
    }*/

    //动规，当前点可走的最远位置 f[i] = max(f[i - 1] - 1, nums[i])
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 0);
        //vector<int> f(n + 1, 0);
        //f[0] = 1;
        int f = 1;

        for (int i = 1; i <= n; i++) {
            //if (f[i - 1] < 1) return false;
            //f[i] = max(f[i - 1] - 1, nums[i]);
            if (f < 1) return false;
            f = max(f - 1, nums[i]);
        }

        return true;
    }
};