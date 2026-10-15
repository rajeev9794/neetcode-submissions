class Solution {
    void generateAllParenthesis(string temp, vector<string> &s, int open, int close, int n){
        if(open ==n && close ==n){
            s.push_back(temp);
            return;
        }

            if(open<n){
                temp.push_back('(');
                open++;
                generateAllParenthesis(temp,s,open,close,n);
                temp.pop_back();
                open--;
            }

            if(close<open){
                temp.push_back(')');
                close++;
                generateAllParenthesis(temp,s,open,close,n);
                temp.pop_back();
                close--;
            }
        
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string>s;
        generateAllParenthesis("", s, 0, 0, n);
        return s;
    }
};
