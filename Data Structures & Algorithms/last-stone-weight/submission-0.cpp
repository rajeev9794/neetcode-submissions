class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }

        while(pq.size()>1){
            int firstTop = pq.top();
            pq.pop();
            int secondTop = pq.top();
            pq.pop();
            if(firstTop-secondTop>0){
                pq.push(firstTop-secondTop);
            }
        }
        if(pq.empty()){
            return 0;
        }
        return pq.top();
    }
};
