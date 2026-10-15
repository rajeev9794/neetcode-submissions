class Solution {
void computeAllCombination(vector<int> &nums, int target, int currentSum, vector<int> &ans, vector<vector<int>> &finalAns, int id){
        if(currentSum==target){
            finalAns.push_back(ans);
            return;
        }
        else if(currentSum>target){
            return;
        }

        for(int index= id;index<nums.size();index++){
            if(index > id && nums[index] == nums[index-1]) continue;
            if(nums[index]+currentSum<=target){
                ans.push_back(nums[index]);
                computeAllCombination(nums, target,currentSum+nums[index], ans, finalAns, index+1);
                ans.pop_back();
            }
        }

    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;

        vector<vector<int>>finalAns;
        computeAllCombination(nums, target,0, ans, finalAns, 0);
        return finalAns;
    }
};
