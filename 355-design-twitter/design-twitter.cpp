class Twitter {
public:

    struct Tweet{
        int id;
        int time;
    };


    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int timeStamp = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timeStamp++});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        using T = tuple<int,int,int>;
        priority_queue<T>pq;
        unordered_set<int> users = following[userId];
        users.insert(userId);
        for(int uid: users){
            if(!tweets[uid].empty()){
                int idx = tweets[uid].size()-1;
                pq.push({tweets[uid][idx].time, uid, idx});
            }
        }
        while(!pq.empty() && feed.size() < 10){
            auto [time, uid, idx] = pq.top();
            pq.pop();
            feed.push_back(tweets[uid][idx].id);
            if(idx > 0){
                int newIdx = idx-1;
                pq.push({tweets[uid][newIdx].time, uid, newIdx});
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            following[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */