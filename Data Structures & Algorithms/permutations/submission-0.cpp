class Solution {
    void computeAllPermutation(vector<int> &nums, vector<int> ans, vector<vector<int>> &finalAns, vector<bool> &visited){
        if(nums.size()==ans.size()){
            finalAns.push_back(ans);
        }

        for(int i = 0;i<nums.size();i++){
            if(visited[i]==false){
                ans.push_back(nums[i]);
                visited[i]=true;
                computeAllPermutation(nums, ans, finalAns, visited);
                visited[i]=false;
                ans.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<bool>visited(n, false);
        vector<int>ans;
        vector<vector<int>>finalAns;
        computeAllPermutation(nums, ans, finalAns, visited);
        return finalAns;

    }
};
