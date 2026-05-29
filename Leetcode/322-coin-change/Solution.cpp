class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long long> dp(amount+1,-1);
        dp[0]=0;
        for(int i=0;i<coins.size();i+=1){
            for(int j=coins[i];j<=amount;j+=1){
                if(dp[j-coins[i]]!=-1){
                    long long val=1+dp[j-coins[i]];
                    if(dp[j]==-1)   dp[j]=val;
                    else dp[j]=min(dp[j],val);
                }
            }
        }
        return dp[amount];
    }
};