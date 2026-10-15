class Solution {
private:
    void dfs(int x, int y,int n, int m, vector<vector<char>> &grid, vector<vector<bool>> &visited){
        if(x>=n || y>=m || x<0 || y<0){
            return;
        }
        if(x>0 && grid[x-1][y] =='1' && visited[x-1][y]== false){
            visited[x-1][y]=true;
            dfs(x-1,y,n,m,grid,visited);
        }
        if(y>0 && grid[x][y-1] =='1' && visited[x][y-1]== false){
            visited[x][y-1]=true;
            dfs(x,y-1,n,m,grid,visited);
        }
        if(x+1<n && grid[x+1][y] =='1' && visited[x+1][y]== false){
            visited[x+1][y]=true;
            dfs(x+1,y,n,m,grid,visited);
        }
        if(y+1<m && grid[x][y+1] =='1' && visited[x][y+1]== false){
            visited[x][y+1]=true;
            dfs(x,y+1,n,m,grid,visited);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // itrate  the connection
        int numOfIsland =0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    //cout<<"i="<<i<<" j="<<j<<endl;
                    numOfIsland++;
                    visited[i][j]=true;
                    dfs(i,j,n,m, grid, visited);
                }
            }
        }
        return numOfIsland;

    }
};
