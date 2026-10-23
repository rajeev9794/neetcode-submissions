class Solution {
    void dfs(int root, vector<bool> &visited, vector<vector<int>> &v){
        visited[root]=true;
        for(int child:v[root]){
            if(!visited[child]){
                dfs(child, visited,v);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n);
        vector<bool>visited(n, false);
        int ans=0;
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }

        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans++;
                dfs(i, visited, v);
            }
        }
        return ans;
    }
};
