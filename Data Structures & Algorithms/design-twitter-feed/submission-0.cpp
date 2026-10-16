class Twitter {
    using Tweet = pair<int,int>; // {timestamp, tweetId}
    
    // Timestamp to track unique tweetId
    int timestamp;

    // Unordered Map to track tweet posted by user
    unordered_map<int,vector<Tweet>> tweets;

    unordered_map<int, unordered_set<int>> followings;
public:
    Twitter() {
        timestamp=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timestamp++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> latestTweets;
        priority_queue<Tweet>pq;

        // Tweets posted by user
        for(int i=0;i<tweets[userId].size();i++){
            pq.push(tweets[userId][i]);
        }

        // Tweet posted by followers
        for(auto it:followings[userId]){
            for(int i=0;i<tweets[it].size();i++){
                pq.push(tweets[it][i]);
            }
        }

        int temp=0;
        while(!pq.empty() && temp<10){
            Tweet t=pq.top();
            pq.pop();
            latestTweets.push_back(t.second);
            temp++;
        }

        return latestTweets;
        

    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followings[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followings[followerId].erase(followeeId);
    }
};
