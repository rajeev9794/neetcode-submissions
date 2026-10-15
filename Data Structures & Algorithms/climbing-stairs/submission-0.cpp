class Solution {
public:
    int climbStairs(int n) {
        if(n==0){
            return 0;
        }
        if(n==1 || n==2){
            return n;
        }
        int oneStairs = 1;
        int twoStairs = 2;
        int requiredStairs =0;
        for(int i=3;i<=n;i++){
            requiredStairs = oneStairs+twoStairs;
            oneStairs = twoStairs;
            twoStairs = requiredStairs;
        }
        return requiredStairs;
    }
};
