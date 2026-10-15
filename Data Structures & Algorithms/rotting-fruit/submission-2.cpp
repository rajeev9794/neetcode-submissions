#define pii pair<pair<int,int>, int>
class Solution {
private:
    void bfs(int x, int y, int n, int m, vector<vector<int>> &grid, vector<vector<bool>> &visited, int &ans, queue<pii> &q){
        while(!q.empty()){
            pii p = q.front();
            //cout<<p.first.first<<" "<<p.first.second<<endl;
            q.pop();
            x=p.first.first;
            y= p.first.second;
        ans = max(ans,p.second);
        if(x<0 || y<0 || x>=n || y>=m){
            return;
        }
        
        
        if(x>0 && visited[x-1][y] == false && grid[x-1][y]==1){
            //cout<<"inserted index x-1 ="<<x-1<<" "<<y<<endl;
            q.push({{x-1,y},p.second+1});
            visited[x-1][y]=true;
        }
        if(y>0 && visited[x][y-1] == false && grid[x][y-1]==1){
            //cout<<"inserted index y-1 ="<<x<<" "<<y-1<<endl;

            q.push({{x,y-1},p.second+1});
            visited[x][y-1]=true;
        }
        if(x+1<n && visited[x+1][y] == false && grid[x+1][y]==1){
            //cout<<"inserted index x+1 ="<<x+1<<" "<<y<<endl;

            q.push({{x+1,y},p.second+1});
            visited[x+1][y]=true;
        }
        if(y+1<m && visited[x][y+1] == false && grid[x][y+1]==1){
            //cout<<"inserted index y+1 ="<<x<<" "<<y+1<<endl;

            q.push({{x,y+1},p.second+1});
            visited[x][y+1]=true;
        }
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // BFS Traversal level order the number of levels got answer is that one 
        int n= grid.size();
        int m= grid[0].size();
        queue<pii>q;

        int timeToRot = 0;
        // If there is single rotten fruit than its ok to find the element.
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        // if not than please find the valid fruits.
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2 && !visited[i][j])
                {
                    q.push({{i,j}, 0});
                    visited[i][j]=true;
                }
            }
        }
        if(!q.empty()){
            pii p=q.front();
            bfs(p.first.first, p.first.second, n, m, grid, visited, timeToRot, q);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j])
                return -1;
            }
        }

        return timeToRot;
    }
};
