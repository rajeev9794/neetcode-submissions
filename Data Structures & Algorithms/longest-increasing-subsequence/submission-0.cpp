class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        int finalAns=0;
        for(int i=n-1;i>=0;i--){
            int j=i+1;
            int ans =0;
            while(j<n){
                if(nums[j]>nums[i]){
                    ans =max(ans, dp[j]);
                }
                j++;
            }
            dp[i]=ans+1;
            finalAns=max(finalAns,dp[i]);
        }

        return finalAns;
    }
};
