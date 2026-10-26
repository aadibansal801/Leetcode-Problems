class Twitter {
public:

    vector<pair<int,int>> tweets;
    unordered_map<int, unordered_set<int>> following;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>feed;
        for(int i = tweets.size() - 1; i >= 0 && feed.size() < 10; i--){
            int author = tweets[i].first;
            int tweet = tweets[i].second;
            if(author == userId || following[userId].count(author)){
                feed.push_back(tweet);
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