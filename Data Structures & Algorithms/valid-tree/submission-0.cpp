class Solution {
    bool detectCycle(vector<vector<int>> &v, vector<bool> &visited, int root, int parent){
        visited[root]=true;
        for(int i=0;i<v[root].size();i++){
            if(v[root][i] == root){
                continue;
            }

            if(!visited[v[root][i]]){
                if(detectCycle(v,visited,v[root][i], root)){
                    return true;
                }
            }
            else if(v[root][i] != parent){
                return true;
            }

            }

        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // for a valid tree no of edges should be n-1
        if(edges.size() != n-1){
            return false; // Elimination of forest.
        }

        vector<vector<int>>v(n);
        for(int i=0;i<edges.size();i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool>visited(n+1,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                if(detectCycle(v, visited, i, -1)){
                    return false;
                }
            }
        }
        return true;
    }
};
