class Solution {
    void dfs(vector<vector<bool>> &ocean, vector<vector<int>> &heights, int i, int j, vector<vector<bool>> &visited){
        int n=heights.size();
        int m=heights[0].size();

        if(i<0 || j<0 || i>n || j>m || visited[i][j]){
            return;
        }
        ocean[i][j]=true;
        visited[i][j]=true;
        
        if(i+1<n && visited[i+1][j]==false && heights[i+1][j]>=heights[i][j])
        dfs(ocean, heights, i+1, j, visited);

        if(j+1<m && visited[i][j+1]==false && heights[i][j+1]>=heights[i][j])
        dfs(ocean, heights, i, j+1, visited);

        if(i-1>=0 && visited[i-1][j]==false && heights[i-1][j]>=heights[i][j])
        dfs(ocean, heights, i-1, j, visited);

        if(j-1>=0 && visited[i][j-1]==false && heights[i][j-1]>=heights[i][j])
        dfs(ocean, heights, i, j-1, visited);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        // Always devide the problem into subproblem and than solve

        vector<vector<bool>>pac(n, vector<bool>(m, false));
        vector<vector<bool>>atl(n, vector<bool>(m, false));

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<vector<bool>> visited2(n, vector<bool>(m, false));

        for(int i=0;i<m;i++){
            dfs(pac,heights, 0, i, visited);
            dfs(atl, heights, n-1, i, visited2);
        }

        for(int i=0;i<n;i++){
            dfs(pac, heights, i,0,visited);
            dfs(atl, heights, i, m-1, visited2);
        }

        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atl[i][j] && pac[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;



    }
};
