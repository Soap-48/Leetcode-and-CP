class Solution {
public:
    int rob(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=nums[i-1];
            for(int j=0;j<i-1;j+=1){ dp[i]=max(dp[i],dp[j]+nums[i-1]);}
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};