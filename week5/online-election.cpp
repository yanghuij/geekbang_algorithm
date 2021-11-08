//911. 在线选举
//https://leetcode-cn.com/problems/online-election/
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int, int> votePerson;
        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < persons.size(); i++) {
            if (votePerson.find(persons[i]) == votePerson.end()) 
                votePerson[persons[i]] = 1;
            else 
                votePerson[persons[i]]++;

            if (!pq.empty() && pq.top().first == votePerson[persons[i]]) {
                pq.push({votePerson[persons[i]], persons[i]});
                maxPerson.push_back(persons[i]);
            } else if (!pq.empty() && pq.top().first > votePerson[persons[i]]) {
                pq.push({votePerson[persons[i]], persons[i]});
                maxPerson.push_back(maxPerson.back());
            } else {
                pq.push({votePerson[persons[i]], persons[i]});
                maxPerson.push_back(pq.top().second);
            }
        }
    }

    int q(int t) {
        int index = getIndex(t);

        return maxPerson[index];
    }

private:
    //找<=time的最大值
    int getIndex(int time) {
        int left = 0, right = times.size() - 1;

        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (times[mid] <= time) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

    vector<int> times;
    vector<int> maxPerson;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
