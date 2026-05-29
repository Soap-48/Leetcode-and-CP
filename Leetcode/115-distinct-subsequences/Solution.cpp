class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<pair<int,long long>>> dp(n+1,vector<pair<int,long long>>(m+1,{0,1}));
        for(int i=1;i<=n;i+=1)
            for(int j=1;j<=m;j+=1){
                dp[i][j].second=0;
                if(s[i-1]==t[j-1]){
                    dp[i][j].first=dp[i-1][j-1].first+1;
                    dp[i][j].second=dp[i-1][j-1].second;
                }
                else{
                    dp[i][j].first=max(dp[i-1][j].first,dp[i][j-1].first);
                }
                if(dp[i][j].first==dp[i-1][j].first)
                    dp[i][j].second+=dp[i-1][j].second;
                if(dp[i][j].first==dp[i][j-1].first)
                    dp[i][j].second+=dp[i][j-1].second;
                dp[i][j].second%=(1ll<<32);
            }
        if(dp[n][m].first!=m)
            return 0;
        return dp[n][m].second;
        // queue<pair<int,int>> q;
        // q.push({n,m});
        // while(!q.empty()){
        //     int siz=q.size();
        //     ans=max(ans,siz);
        //     for(int i=0;i<siz;i+=1){
        //         auto [x,y]=q.front();
        //         q.pop();
        //         if(x>0&&y>0){
        //             if(dp[x][y]-dp[x-1][y-1]==1){
                        
        //             }
        //         }
        //     }
        // }
    }
};