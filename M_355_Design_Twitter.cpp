#include "lc_header.h"
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time_stamp = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow_map[userId].insert(userId);
        tweets_map[userId].emplace_back(make_pair(time_stamp++, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        cout << "userId: " << userId << endl;
        vector<int> feeds;
        unordered_set<int>& followees = follow_map[userId];
        vector<int> idxs(followees.size());
        int i = 0;
        for (auto it = followees.begin(); it != followees.end(); it++) {
            idxs[i] = tweets_map[*it].size() - 1;
            i++;
        }
        
        for (i = 0; i < 10; i++) {
            auto recent_it = followees.begin();
            int recent_j = 0;
            int j = 0;
            int recent_t = -1;
            for (auto it = followees.begin(); it != followees.end(); it++, j++) {
                if (idxs[j] < 0) {
                    continue;
                }
                if (tweets_map[*it][idxs[j]].first > recent_t) {
                    recent_t = tweets_map[*it][idxs[j]].first;
                    recent_it = it;
                    recent_j = j;
                }
            }
            if (recent_t > -1) {
                feeds.push_back(tweets_map[*recent_it][idxs[recent_j]].second);
                idxs[recent_j]--;
            }
        }
        
        return feeds;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            follow_map[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId!=followeeId && follow_map.find(followerId)!=follow_map.end()) {
            follow_map[followerId].erase(followeeId);
        }
    }
    
private:
    unordered_map<int, unordered_set<int>> follow_map; // userId=>[userId]
    unordered_map<int, vector<pair<int, int>>> tweets_map; // userId=>[tweetId]
    int time_stamp;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */