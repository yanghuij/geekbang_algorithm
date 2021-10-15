//811. 子域名访问计数
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> mDomain;

        for (string& domain : cpdomains) {
            int count = 0;
            size_t index = domain.find_first_of(" ", 0);
            if (index == domain.npos)
                continue;

            count = atoi(domain.substr(0, index).c_str());
            index++;
            if (mDomain.find(domain.substr(index)) == mDomain.end()) {
                mDomain[domain.substr(index)] = count;
            } else {
                mDomain[domain.substr(index)] += count;
            }

            index = domain.find_first_of(".", index);
            while (index != domain.npos) {
                index++;
                if (mDomain.find(domain.substr(index)) == mDomain.end()) {
                    mDomain[domain.substr(index)] = count;
                } else {
                    mDomain[domain.substr(index)] += count;
                }
                index = domain.find_first_of(".", index);
            }
        }

        for (const pair<string, int>& stat : mDomain) {
            ans.push_back(to_string(stat.second) + " " + stat.first);
        }

        return ans;
    }
};
