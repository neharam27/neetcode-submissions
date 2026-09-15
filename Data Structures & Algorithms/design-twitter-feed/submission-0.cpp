class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int time = 0;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        time++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;

        following[userId].insert(userId);

        for(int user : following[userId]) {
            for(auto tweet : tweets[user]) {
                pq.push(tweet);
            }
        }

        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};