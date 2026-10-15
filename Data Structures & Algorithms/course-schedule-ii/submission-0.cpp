class Solution {
    private:
    // Is graph is DAG then its possible to take else not
    bool isCycle(int node, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &v, stack<int> &s){
        visited[node]=true;
        recPath[node]=true;
        for(auto child: v[node]){
            if(!visited[child]){
                if(isCycle(child, visited, recPath,v, s)){
                    return true;
                }
            }
            else if(recPath[child]){
                return true;
            }
        }
        s.push(node);
        recPath[node]=false;
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        int m = prerequisites.size();
        vector<bool> visited(numCourses, false);
        vector<bool> recPath(numCourses, false);
        for(int i=0;i<m;i++){
            v[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        stack<int>s;

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(isCycle(i, visited, recPath, v, s)){
                    return {};
                }
            }
        }

        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
