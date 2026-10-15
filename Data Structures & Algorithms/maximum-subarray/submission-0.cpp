class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int bestSumSofar=nums[0];
        int currSum = nums[0];
        for(int i=1;i<n;i++){
            //cout<<" array value="<<nums[i]<<"\t";
            //bestSumSofar = max(bestSumSofar, currSum);

            // Including the element 
            currSum = max(nums[i], currSum+nums[i]);
            bestSumSofar = max(bestSumSofar, currSum);
        }
        return bestSumSofar;
    }
};
