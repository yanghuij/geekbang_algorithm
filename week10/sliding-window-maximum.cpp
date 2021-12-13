//239. �����������ֵ
//https://leetcode-cn.com/problems/sliding-window-maximum/
/*class Solution {
public:
//�ѣ�����ɾ�������ѵĸ����±겻�ڴ�����ʱ����ɾ����������ÿ���ƶ���ɾ�Ƴ���ֵ����Ϊ
//����Ƴ���ֵ���ǶѶ���û��ֱ��ɾ���ĺ���
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
    //(�ؼ���,�±�)
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
