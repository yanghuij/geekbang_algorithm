//1011. 在 D 天内送达包裹的能力
//https://leetcode-cn.com/problems/capacity-to-ship-packages-within-d-days/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = 0;
        int right = 0;

        for (int weight : weights) {
            left = max(left, weight);
            right += weight;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(weights, mid, days)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

    bool valid(vector<int>& weights, int boat, int days) {
        int day = 0;
        int sum = 0;
        for (int weight : weights) {
            if (sum + weight <= boat) {
                if (sum == 0) day++;
                sum += weight;
            } else {
                day++;
                sum = weight;
            }
        }

        return (day <= days) ? true : false;
    }
};