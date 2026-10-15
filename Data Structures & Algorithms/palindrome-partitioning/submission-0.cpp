class Solution {
    bool isPalindrome(string s){
        int n=s.size();
        int i=0,j=n-1;
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        if(n%2==0 && j<i){
            return true;
        }
        return i==j;
    }
    void computeAllPalindromes(vector<string>v, set<vector<string>> &ans, string s, int index){
        if(index>=s.size()){
            ans.insert(v);
            return;
        }

        for(int i=index;i<s.size();i++){
            string t=s.substr(index,i-index+1);
            if(isPalindrome(t)){
                v.push_back(t);
                computeAllPalindromes(v,ans,s,i+1);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        // Generate all possible palindromes
        int n=s.size();
        // Palindromic substrings

        set<vector<string>>ans;
        vector<string>temp;
        computeAllPalindromes(temp,ans,s,0);
        vector<vector<string>>finalAns;
        for(auto it:ans){
            finalAns.push_back(it);
        }
        return finalAns;
    }
};
