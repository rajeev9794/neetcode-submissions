class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string palindromeString="";
        int ans=0, index=-1;
        
            for(int i=0;i<n;i++){
                int start =i;
                int end =i;

                // Odd length
                while(start>=0 && end<n && s[start]==s[end]){
                    if(end-start+1>ans){
                        ans=end-start+1;
                        index = start;
                    }
                    start--;
                    end++;
                }

                // even length
                start=i;
                end=i+1;
                while(start>=0 && end<n && s[start]==s[end]){
                    if(end-start+1>ans){
                        ans=end-start+1;
                        index = start;
                    }
                    start--;
                    end++;
                }

                
            }
        palindromeString=s.substr(index, ans);

        return palindromeString;
    }
};
