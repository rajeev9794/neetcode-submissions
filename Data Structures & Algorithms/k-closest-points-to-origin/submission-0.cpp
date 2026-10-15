class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n= points.size();

        // Max Heap will be applied
        priority_queue<pair<int, int>>pq;
        for(int i=0;i<n;i++){
            int dis = (points[i][0]*points[i][0])+(points[i][1]*points[i][1]);
            //cout<<"dis="<<dis<<endl;
            pq.push({dis,i});
            if(pq.size()>k){
                //cout<<pq.top().first<<endl;
               pq.pop();
            }
        }

        vector<vector<int>>ans;
        for(int i=0;i<k;i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};
