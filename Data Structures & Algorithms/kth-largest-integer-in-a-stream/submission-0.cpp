class KthLargest {
    int kth;
    priority_queue<int,vector<int>,greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        kth=k;
        while(pq.size()>k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>kth){
            pq.pop();
        }
        return pq.top();
    }
};
