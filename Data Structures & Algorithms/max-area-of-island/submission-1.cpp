class Solution {
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int &temp, int &ans){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || visited[i][j] || grid[i][j]==0){
            ans= max(ans, temp);
            return;
        }
        temp++;
        ans= max(ans, temp);
        visited[i][j]=true;
        dfs(grid, i+1,j, visited, temp, ans);
        dfs(grid, i-1,j, visited, temp, ans);
        dfs(grid, i,j-1, visited, temp, ans);
        dfs(grid, i,j+1, visited, temp, ans);
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        int temp=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] ==1 && !visited[i][j]){
                    temp=0;
                    dfs(grid, i, j, visited, temp, ans);
                }
            }
        }

        return ans;
    }
};
