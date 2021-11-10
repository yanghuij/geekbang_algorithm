//875. 爱吃香蕉的珂珂
//https://leetcode-cn.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;

        for (int pile : piles) {
            right = max(right, pile);
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return right;
    }

private:
    bool valid(vector<int>& piles, int h, int speed) {
        int time = 0;

        //以speed速度吃完香蕉需要多久
        for (int pile : piles) {
            time += ((pile + (speed - 1)) / speed);
        }

        return time <= h;
    }
};