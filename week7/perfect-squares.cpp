//279. 完全平方数
//https://leetcode-cn.com/problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 0; i <= n; i++) {
            if (i * i <= n) {
                squares.push_back(i * i);
            }
        }
        int m = squares.size() - 1;

        //完全平方数看做物品，体积为n，价值为1，用背包DP
        //f[i,j]表示从前i个完全平方数中选出和为j的完全平方数，完全平方数的最少个数：
        //f[i,j] = min( f[i - 1,j],            f[i - 1,j - squares[i]] + 1 )            
        //           不选第i个完全平方数       j>=squares[i]，选第i个完全平方数
        //初值 f[0,0] = 0，其余为正无穷
        //目标 f[i,n]

        vector<int> f(n + 1, 1e9);
        f[0] = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = squares[i]; j <= n; j++) {
                f[j] = min(f[j], f[j - squares[i]] + 1);
            }
        }

        return f[n];
    }
};