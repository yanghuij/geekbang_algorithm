//560. ��Ϊ K ��������
class Solution {
public:
    //�����⣬��ʱ O(n^3)
    /*int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j <= i; j++) {
                int sum = 0;

                for (int l = j; l <= i; l++) {
                    sum += nums[l];
                }

                if (sum == k) ans++;
            }
        }

        return ans;
    }*/

    //�����⣬�Ż���ͣ���ʱ  O(n^2)
    /*int subarraySum(vector<int>& nums, int k) {
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j >= 0; j--) {
                sum += nums[j];

                if (sum == k) ans++;
            }
        }

        return ans;
    }*/

    //ǰ׺�ͣ���ʱ  O(n^2)
    /*int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> preSum(nums.size() + 1, 0);

        for (int i = 1; i <= nums.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= i; j++) {
                int sum = preSum[i] - preSum[j - 1];

                if (sum == k) ans++;
            }
        }

        return ans;
    }*/

    //ǰ׺�� + hash map   O(n)
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> preSum(nums.size() + 1, 0);
        unordered_map<int, int> m;

        for (int i = 1; i <= nums.size(); i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        for (int i = 1; i < preSum.size(); i++) {
            if (preSum[i] == k) {
                ans++;
            } 
            
            if (m.find(preSum[i] - k) != m.end()) {
                ans += m[preSum[i] - k];
            }
            
            m[preSum[i]]++;
        }

        return ans;
    }

    //ǰ׺�� + hash map  �ٷ�  O(n)
    /*int subarraySum(vector<int>& nums, int k) {
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
    }*/
};