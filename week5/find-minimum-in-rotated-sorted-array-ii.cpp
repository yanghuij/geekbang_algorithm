//154. 寻找旋转排序数组中的最小值 II
//https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while(left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[right]) {              
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right--;
            }
        }

        return nums[right];
    }
};