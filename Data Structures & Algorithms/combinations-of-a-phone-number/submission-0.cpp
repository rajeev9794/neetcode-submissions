class Solution {
    void computeAllCombination(string digits, vector<string> &v, int digitIndex, vector<string> &ans, string temp){
        // base condition
        if(digitIndex>=digits.size() || temp.size()==digits.size()){
            ans.push_back(temp);
            return;
        }

        int index = digits[digitIndex]-'0';
        for(int i=0;i<v[index].size();i++){
            temp.push_back(v[index][i]);
            computeAllCombination(digits, v,digitIndex+1, ans, temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string>v(10);
        v[2]="abc";
        v[3]="def";
        v[4]="ghi";
        v[5]="jkl";
        v[6]="mno";
        v[7]="pqrs";
        v[8]="tuv";
        v[9]="wxyz";
        vector<string>ans;
        if(digits.size()<=0){
            return ans;
        }
        computeAllCombination(digits,v, 0, ans, "");
        return ans;
    }
};
