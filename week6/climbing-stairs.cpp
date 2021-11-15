//70. ÅÀÂ¥ÌÝ
//https://leetcode-cn.com/problems/climbing-stairs/
class Solution {
public:
    //f(n) = f(n - 1) + f(n - 2)
    /*int climbStairs(int n) {
        vector<int> f(n + 1);
        f[0] = 1; 
        f[1] = 1;

        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }

        return f[n];
    }*/

    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;

        for (int i = 1; i <= n; i++) {
            p = q;
            q = r;
            r = p + q;
        }

        return r;
    }
};