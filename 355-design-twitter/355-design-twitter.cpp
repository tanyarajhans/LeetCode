class Twitter {
public:
    unordered_map<int, set<int>> userFollows;
    set<pair<int, pair<int, int>>> tweets;
    int t=0;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.insert({t,{tweetId, userId}});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        userFollows[userId].insert(userId);
        int v=10;
        vector<int> ans;
        for(auto it=tweets.rbegin(); it!=tweets.rend() && v>0;it++){
            if(userFollows[userId].count(it->second.second)){
                ans.push_back(it->second.first);
                v--;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        userFollows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        userFollows[followerId].erase(followeeId);
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