class Solution {
private:
    int findMinimumCoin(int index, vector<int> &coins, int amount, vector<vector<int>>& dp){
        if(coins.size()<=index && amount>0){
            return -1;
        }
        else if(coins.size()<=index || amount<=0){
            return 0;
        }

        if(dp[index][amount]!=-2){
            return dp[index][amount];
        }

        //cout<<coins[index]<<"  amount="<<amount<<endl;
        if(coins[index]<=amount){
            int tempRemainingCoins = findMinimumCoin(index, coins,amount-coins[index], dp);
            dp[index][amount-coins[index]]=tempRemainingCoins;
            int withTakingCoin = -1;
            if(tempRemainingCoins != -1){
                // Means this way ans is not possible
                withTakingCoin = 1+tempRemainingCoins;
            }
            int withOutTakingCoin = findMinimumCoin(index+1, coins, amount, dp);
            dp[index+1][amount]=withOutTakingCoin;
            //cout<<"coins= with="<<withTakingCoin<<"   "<<withOutTakingCoin<<endl;
            int ans =-1;
            if(withOutTakingCoin == -1 && withTakingCoin == -1){
                ans=-1;
            }
            else if(withOutTakingCoin == -1){
                ans= withTakingCoin;
            }
            else if(withTakingCoin ==-1){
                ans= withOutTakingCoin;
            }
            else{
                ans= min(withTakingCoin, withOutTakingCoin);
            }
            return dp[index][amount]=ans;
        }   
        else{
            return dp[index][amount]=-1;
        }
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<vector<int>>dp(coins.size()+1, vector<int>(amount+1,-2));
        return findMinimumCoin(0,coins,amount, dp);
    }
};
