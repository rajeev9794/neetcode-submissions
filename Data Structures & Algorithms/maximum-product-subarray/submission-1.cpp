class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // [2,4,-3,5]
        int n=nums.size();
        int maxProductSofar =nums[0];
        int prefix=0, suffix=0;
        int globalMaxProductSofar =nums[0];
        for(int i=0;i<n;i++){
            prefix=nums[i]*(prefix==0?1:prefix);
            suffix =nums[n-i-1]*(suffix==0?1:suffix);
            globalMaxProductSofar =max(globalMaxProductSofar, max(prefix,suffix));
        }        

        return globalMaxProductSofar;

    }
};
