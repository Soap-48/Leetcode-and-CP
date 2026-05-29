const int inf=1e8;
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);cuts.push_back(n);
        int N=cuts.size();
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(N,vector<int>(N,inf));
        for(int i=1;i<N;i+=1)
            dp[i-1][i]=0;
        for(int l=1;l<N;l+=1){
            for(int i=0;i+l<N;i+=1){
                for(int k=i+1;k<i+l;k+=1)
                    dp[i][i+l]=min(dp[i][i+l],dp[i][k]+dp[k][i+l]+cuts[i+l]-cuts[i]);
            }
        }
        return dp[0][N-1];
    }
};
        // vector<vector<int>> dp(n+1,vector<int>(n+1,inf));
        // cuts.push_back(0);
        // sort(cuts.begin(),cuts.end());
        // for(int i=1;i<cuts.size();i+=1)
        //     dp[cuts[i-1]][cuts[i]]=0;
        // dp[cuts.back()][n]=0;
        