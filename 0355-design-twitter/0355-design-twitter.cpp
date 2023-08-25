class Twitter {
public:
    vector<pair<int,int>> tweets;
    unordered_map<int,set<int>> follows;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> ans;
        for(int i = tweets.size()-1; i>=0;i--){
            if(tweets[i].first == userId || follows[userId].find(tweets[i].first)!=follows[userId].end())
                ans.push_back(tweets[i].second);
            if(ans.size()==10)
                break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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