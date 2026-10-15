class Solution {
private:
    // Is graph is DAG then its possible to take else not
    bool isCycle(int node, vector<bool> &visited, vector<bool> &recPath, vector<vector<int>> &v){
        visited[node]=true;
        recPath[node]=true;
        for(auto child: v[node]){
            if(!visited[child]){
                if(isCycle(child, visited, recPath,v)){
                    return true;
                }
            }
            else if(recPath[child]){
                return true;
            }
        }
        recPath[node]=false;
        return false;
    }   
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // create adjacency list;
        vector<vector<int>>v(numCourses);
        int m = prerequisites.size();
        vector<bool> visited(numCourses, false);
        vector<bool> recPath(numCourses, false);
        for(int i=0;i<m;i++){
            v[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(isCycle(i, visited, recPath, v)){
                    return false;
                }
            }
        }
        return true;
        
    }
};
