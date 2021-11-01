//355. 设计推特
//https://leetcode-cn.com/problems/design-twitter/
class Twitter {
public:
    Twitter() {
        timestamp = 0;
        maxNewsNum = 10;
    }
    
    void postTweet(int userId, int tweetId) {
        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = new User(userId);
        }

        timestamp++;
        TweetNode* tn = new TweetNode(tweetId, timestamp);

        tn->next = userMap[userId]->head.next;
        userMap[userId]->head.next = tn;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        vector<TweetNode*> lists;

        if (userMap.find(userId) == userMap.end()) return ans;

        if (userMap[userId]->head.next) 
            lists.push_back(userMap[userId]->head.next);

        for (int followee : userMap[userId]->followees) {
            if (followee == userId || userMap.find(followee) == userMap.end()) continue;
            if (userMap[followee]->head.next) 
                lists.push_back(userMap[followee]->head.next);
        }

        priority_queue<pair<int, TweetNode*>> pq;

        for (TweetNode* tweetNode : lists) {
            if (tweetNode == nullptr) continue;
            pq.push({tweetNode->time, tweetNode});
        }

        while (!pq.empty()) {
            TweetNode* tweetNode = pq.top().second;
            pq.pop();

            ans.push_back(tweetNode->tweetId);
            if (ans.size() >= maxNewsNum) {
                break;
            }

            if (tweetNode->next) {
                pq.push({tweetNode->next->time, tweetNode->next});
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = new User(followerId);
        }

        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = new User(followeeId);
        }

        userMap[followerId]->followees.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userMap.find(followerId) != userMap.end()) {
             userMap[followerId]->followees.erase(followeeId);
        }
    }

private:
    struct TweetNode {
        int tweetId;
        int time;
        TweetNode *next;
        TweetNode() : tweetId(0), time(0), next(nullptr) {}
        TweetNode(int x, int t) : tweetId(x), time(t), next(nullptr) {}
        TweetNode(int x, int t, TweetNode *next) : tweetId(x), time(t), next(next) {}
    };
    struct User {
        int userId;
        TweetNode head;
        unordered_set<int> followees;
        User(int userId) : userId(userId) {
            head.next = nullptr;
        };
    };
    int timestamp;
    int maxNewsNum;
    unordered_map<int, User*> userMap;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
