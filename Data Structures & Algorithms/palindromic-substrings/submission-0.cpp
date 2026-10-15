class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans =0;
        for(int i=0;i<n;i++){
            int start =i-1;
            int end =i+1;
            int temp=1;
            while(end<n && start>=0 && s[start]==s[end]){
                temp++;
                start--;
                end++;
            }

            //even size string
            start = i;
            end=i+1;
            while(end<n && start>=0 && s[start]==s[end]){
                start--;
                end++;
                temp++;
            }

            ans+=temp;
        }
        return ans;
    }
};
