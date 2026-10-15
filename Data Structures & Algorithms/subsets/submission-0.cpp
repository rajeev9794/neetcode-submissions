class Solution {
private: 
    void generateAllSubset(int index, vector<int> &nums, vector<int> ans, vector<vector<int>> &finalans){
        if(index >nums.size()){
            return;
        }
        finalans.push_back(ans);
        for(int i=index;i<nums.size();i++){
            ans.push_back(nums[i]);
            generateAllSubset(i+1, nums,ans,finalans);
            ans.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ans;
        vector<vector<int>> finalans;
        generateAllSubset(0, nums, ans, finalans);
        return finalans;
    }
};
