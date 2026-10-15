class Solution {
private:
    bool ComputeSubSetSum(int sum, int totalSum, vector<int> &nums, int index){
        if(index>=nums.size()){
            return false;
        }
        int temp=sum;
        sum =sum+nums[index];
        if(sum*2 == totalSum){
            return true;
        }

        return ComputeSubSetSum(sum, totalSum,nums, index+1) || ComputeSubSetSum(temp, totalSum, nums, index+1);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total =0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }

        return ComputeSubSetSum(0, total, nums, 0);
    }
};
