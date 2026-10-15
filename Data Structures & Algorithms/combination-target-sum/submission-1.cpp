class Solution {
    void computeAllCombination(vector<int> &nums, int target, int currentSum, vector<int> ans, set<vector<int>> &totalAns, int id){
        if(currentSum==target){
            totalAns.insert(ans);
        }
        else if(currentSum>target){
            return;
        }

        for(int index= id;index<nums.size();index++){

            if(nums[index]+currentSum<=target){
                ans.push_back(nums[index]);
                computeAllCombination(nums, target,currentSum+nums[index], ans, totalAns, index);
                ans.pop_back();
            }
            /*
            else{
                computeAllCombination(nums, target,currentSum, ans, totalAns, index+1);
            }
            */
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        set<vector<int>>totalAns;
        computeAllCombination(nums, target,0, ans, totalAns, 0);
        vector<vector<int>>finalAns;
        for(auto it:totalAns){
            finalAns.push_back(it);
        }
        return finalAns;
    }
};
