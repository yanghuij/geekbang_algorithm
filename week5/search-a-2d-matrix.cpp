//74. ËÑË÷¶þÎ¬¾ØÕó
//https://leetcode-cn.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int x = mid / n;
            int y = mid % n;

            if (matrix[x][y] == target)
                return true;

            if (matrix[x][y] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};