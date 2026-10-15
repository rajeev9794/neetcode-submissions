class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();

        bool isValidSudoko = true; 
        int currentValue = -1;
        // Duplicate checking in square boxes completes;       
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                vector<bool>v(9, false);
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y] >='1' && board[x][y]<='9'){
                            currentValue = board[x][y]-'0';
                            if(v[currentValue-1]){
                                return false;
                            }
                            v[currentValue-1]=true;
                        }
                    }
                }
            }
        }

        // Now checking in the row
        for(int i=0;i<9;i++){
            vector<bool>row(9, false);
            vector<bool>col(9,false);
            for(int j=0;j<9;j++){
                if(board[i][j] >='1' && board[i][j]<='9')
                {
                    currentValue = board[i][j]-'0';
                    if(row[currentValue-1]){
                        return false;
                    }
                    row[currentValue-1]=true;
                }

                if(board[j][i] >='1' && board[j][i]<='9')
                {
                    currentValue = board[j][i]-'0';
                    if(col[currentValue-1]){
                        return false;
                    }
                    col[currentValue-1]=true;
                }
            }
        }

        return true;
    }
};
