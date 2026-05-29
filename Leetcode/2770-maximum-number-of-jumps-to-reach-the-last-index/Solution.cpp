class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        dp[0]=0;
        for(int i=1;i<nums.size();i+=1)
            for(int j=0;j<i;j+=1)
                if(dp[j]!=-1&&((abs(nums[j]-nums[i]))<=target))
                    dp[i]=max(dp[i],dp[j]+1);
        return dp[nums.size()-1];
    }
};