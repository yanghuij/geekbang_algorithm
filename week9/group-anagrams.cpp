//49. ×ÖÄ¸ÒìÎ»´Ê·Ö×é
//https://leetcode-cn.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> m;

        for (string& str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());

            if (m.find(copy) == m.end()) {
                m[copy] = {};
            }

            m[copy].push_back(str);
        }

        for (const auto& v : m) {
            ans.push_back(v.second);
        }

        return ans;
    }
};