class Solution {
    bool computeWordExist(vector<vector<char>>& board, string word, int currentWordIndex, int row, int column,int n, int m, vector<vector<bool>> &visited){
        if(currentWordIndex >= word.size()){
            return true;
        }


        if(row<0 || column<0 || row>=n || column>=m || board[row][column]!=word[currentWordIndex] || visited[row][column]){
            return false;
        }
        
        visited[row][column]=true;
        int res = computeWordExist(board, word, currentWordIndex+1, row+1,column, n,m, visited)|| computeWordExist(board, word, currentWordIndex+1, row-1,column, n,m, visited) ||
        computeWordExist(board, word, currentWordIndex+1, row,column+1, n,m, visited)|| computeWordExist(board, word, currentWordIndex+1, row,column-1, n,m, visited);
        visited[row][column]=false;

        return res;

    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int l =board.size();
        int m = board[0].size();

        vector<vector<bool>>visited(l,vector<bool>(m,false));
        bool res = false;
        for(int i=0;i<l;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    res=computeWordExist(board,word, 0, i,j,l,m, visited);
                    if(res){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
