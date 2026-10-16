#define pii pair<int,int> 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int totalTime =0;
        priority_queue<pii>pq;
        // first count the frequency
        vector<int>freq(26,0);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        int currentTime = 0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],i});
            }
        }

        queue<pii>q;
        while(!pq.empty() || !q.empty()){
            currentTime++;
            while(!q.empty() && q.front().first<currentTime){
                    if(freq[q.front().second]>0)
                    pq.push({freq[q.front().second], q.front().second});
                    q.pop();
            }

            if(!pq.empty()){
                pii p=pq.top();
                //cout<<p.first<<" "<<p.second<<endl;
                pq.pop();
                freq[p.second]--;
                //cout<<currentTime<<endl;
                if(freq[p.second]>0)
                q.push({currentTime+n, p.second});
            }
            
                
        }

        return currentTime;
    }
};
