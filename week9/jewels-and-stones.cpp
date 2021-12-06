//771. 宝石与石头
//https://leetcode-cn.com/problems/jewels-and-stones/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        for (char jewel : jewels) {
            jewelsSet.insert(jewel);
        }

        int ans = 0;
        for (char stone : stones) {
            if (jewelsSet.find(stone) != jewelsSet.end()) {
            //if (jewelsSet.count(stone)) {
                ans++;
            }
        }

        return ans;
    }

private:
    unordered_set<char> jewelsSet;
};
