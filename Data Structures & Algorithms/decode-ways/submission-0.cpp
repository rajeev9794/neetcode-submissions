class Solution {
private:
    int ComputeTheValidResult(int i, string &s, vector<int> &dp){
        if(i == s.size()){
            return 1;
        }
        if(s[i] == '0'){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }

        int ans = ComputeTheValidResult(i + 1, s, dp);
        if(i + 1 < s.size()){
            int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if(twoDigit >= 10 && twoDigit <= 26){
                ans += ComputeTheValidResult(i + 2, s, dp);
            }
        }

        return dp[i] = ans;
    }

public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return ComputeTheValidResult(0, s, dp);
    }
};
