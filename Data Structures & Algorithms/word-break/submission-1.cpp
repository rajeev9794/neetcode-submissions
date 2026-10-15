class Solution {
private:
    bool canSentenceFormed(string s, int start, vector<string> &dict, vector<int> &dp){
        if(start>=s.size()){
            dp[s.size()]=1;
            return true;
        }
        if(dp[start]!=-1){
            return dp[start] == 1? true:false;
        }
        for(int i=0;i<dict.size();i++){
            int len=dict[i].size();
            if(dict[i]==s.substr(start,len) && canSentenceFormed(s, start+len, dict,dp)){
                dp[start]=1;
                dp[start+len-1]=1;
                return true;
            }
        }

        dp[start]=0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       // catsincars --> cats, cat, sin, in, car
       // recursion tree
       int n=s.size();
       vector<int>dp(n+1, -1);
       return canSentenceFormed(s, 0, wordDict, dp);
       // 
        
    }
};
