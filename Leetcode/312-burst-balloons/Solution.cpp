const int inf=1e8;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> a(n+2);
        a[0]=1;
        for(int i=1;i<=n;i+=1)
            a[i]=nums[i-1];
        a[n+1]=1;
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i+=1)
            dp[i][i]=a[i-1]*a[i]*a[i+1];
        for(int l=1;l<n;l+=1)
            for(int i=1;i+l<=n;i+=1){
                dp[i][i+l]=dp[i+1][i+l]+a[i-1]*a[i]*a[i+l+1];
                for(int k=i+1;k<i+l;k+=1)
                    dp[i][i+l]=max(dp[i][i+l],dp[i][k-1]+dp[k+1][i+l]+a[i-1]*a[k]*a[i+l+1]);
                dp[i][i+l]=max(dp[i][i+l],dp[i][i+l-1]+a[i-1]*a[i+l]*a[i+l+1]);
                }
        return dp[1][n];
    }
};