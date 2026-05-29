const int inf=1e8;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,inf);
        dp[0]=0;
        int i=0,maxi=i+nums[i];
        while(dp[n-1]==inf){
            int maxi=min(n-1,i+nums[i]);
            int nxt=maxi,k=-1;
            for(int j=maxi;j>i&&dp[j]==inf;j-=1){
                dp[j]=dp[i]+1;
                if(j+nums[j]>nxt){
                    nxt=j+nums[j];
                    k=j;
                }
            }
            maxi=nxt;
            i=k;
        }
        return dp[n-1];
    }
};