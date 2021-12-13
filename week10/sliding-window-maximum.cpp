//239. 滑动窗口最大值
//https://leetcode-cn.com/problems/sliding-window-maximum/
/*class Solution {
public:
//堆，懒惰删除，当堆的根的下标不在窗口中时，再删除，而不是每次移动都删移出的值，因为
//如果移出的值不是堆顶，没有直接删除的函数
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
            
            if (i >= k - 1) {
                //[i-k+1, i] 
                while (pq.top().second < (i - k + 1)) {
                    pq.pop();
                }
                ans.push_back(pq.top().first);
            }
        }

        return ans;
    }

private:
    //(关键码,下标)
    priority_queue<pair<int, int>> pq;
};*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multimap<int, int> mm;

        for (int i = 0; i < nums.size(); i++) {
            mm.insert({-nums[i], i});
            
            if (i >= k - 1) {
                //[i-k+1, i] 
                while (mm.begin()->second < (i - k + 1)) {
                    mm.erase(mm.begin());
                }
                ans.push_back(-mm.begin()->first);
            }
        }

        return ans;
    }
};
