class Solution {
    // Apply bfs to find minimum till the point DFS won't solve ap
    #define pii pair<int,pair<int,int>>
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, queue<pii> &q){
        if(q.empty()){
            return;
        }

        pii p=q.front();
        int i=p.second.first;
        int j=p.second.second;
        int step=p.first;
        q.pop();
        //cout<<"i="<<i<<" j="<<j<<" step="<<step<<endl;
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] ==-1 || visited[i][j]){
            if(!q.empty())
            dfs(grid,visited,q);
            return;
        }

        grid[i][j]= min(grid[i][j], step);

        visited[i][j]=true;
        int n=grid.size();
        int m=grid[0].size();
        if(i+1<n && grid[i+1][j]!=-1 && visited[i+1][j]==false)
        q.push({step+1,{i+1,j}});

        if(i-1>=0 && grid[i-1][j]!=-1 && visited[i-1][j]==false)
        q.push({step+1,{i-1,j}});

        if(j+1<m && grid[i][j+1]!=-1 && visited[i][j+1]==false)
        q.push({step+1,{i,j+1}});

        if(j-1>=0 && grid[i][j-1]!=-1 && visited[i][j-1]==false)
        q.push({step+1,{i,j-1}});

        dfs(grid,visited,q);
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        queue<pii>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({0,{i,j}});
                }
            }
        }

        dfs(grid, visited, q);
        return;
    }
};
