class Solution {
    void computeAllSubset(vector<int> &nums, vector<int> temp, vector<vector<int>> &ans, int id) {
        if(id>nums.size()){
            return;
        }

        ans.push_back(temp);
        for(int i=id;i<nums.size();i++){
            if(i>id && nums[i]==nums[i-1])continue;
            temp.push_back(nums[i]);
            computeAllSubset(nums,temp,ans,i+1);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>temp;
        vector<vector<int>>ans;
        computeAllSubset(nums,temp,ans,0);
        return ans;
    }
};
