class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<long long> dp(amount+1,0);
        dp[0]=1;
        for(int i=0;i<coins.size();i+=1)
            for(int j=0;j<=amount-coins[i];j+=1)
                dp[j+coins[i]]=(dp[j+coins[i]]+dp[j])%(2147483648);
        return dp[amount];
    }
};