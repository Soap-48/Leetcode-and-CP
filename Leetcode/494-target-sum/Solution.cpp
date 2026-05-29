class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<long long> dp(2001,0);
        dp[1000]=1;
        for(int i=0;i<nums.size();i+=1){
            vector<long long> ndp(2001,0);
            for(int j=nums[i];j<=2000;j+=1)
                ndp[j]+=dp[j-nums[i]];
            for(int j=0;j<=2000-nums[i];j+=1)
                ndp[j]+=dp[j+nums[i]];
            dp=ndp;
        }
        return dp[target+1000];
    }
};