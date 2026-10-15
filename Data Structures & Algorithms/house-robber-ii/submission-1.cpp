// Circular House - First House and last House are circular.
//2->9->8->3->6->2
//6->2

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        else if(n==2){
            return max(nums[0],nums[1]);
        }
        else if(n==3){
            return max(nums[0], max(nums[1], nums[2]));
        }
        vector<int>dp(n);
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=nums[2]+nums[0];
        for(int i=3;i<n-1;i++){
            dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
        }
        /*
        for(int i=0;i<n;i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        */
        int currMax= max(dp[n-2],dp[n-3]);
        dp[1]=nums[1];
        dp[2]=nums[2];
        dp[3] = nums[3]+nums[1];
        for(int i=4;i<n;i++){
            dp[i]=nums[i]+max(dp[i-2],dp[i-3]);
        }
        int tempMax=max(dp[n-1], dp[n-2]);
        return max(currMax,tempMax);



        /*
        // Circular House rotation 
        int rob1=nums[0], rob2=nums[1];
        int rob3=0;
        int temp=0;
        for(int i=2;i<n-1;i++){
            temp=max(nums[i]+rob1, rob2);
            rob1=rob2;
            rob2=temp;
        }

        int currentMax=rob2;
        rob1=nums[1];
        rob2=nums[2];
        for(int i=3;i<n;i++){
            temp=max(nums[i]+rob1, rob2);
            rob1=rob2;
            rob2=temp;
        }
        return max(rob2, currentMax);
        */
    }
};
