class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        long long ans=0;
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<pair<int,int>>> dp(n+1,vector<pair<int,int>>(m+1,{0,0}));
        for(int i=0;i<=n;i+=1)
            for(int j=0;j<=m;j+=1)
                dp[i][j]={i+1,j+1};
        for(int i=1;i<=n;i+=1){
            for(int j=1;j<=m;j+=1){
                if(matrix[i-1][j-1]==1){
                    auto a=dp[i-1][j-1];
                    auto c=dp[i][j-1],b=dp[i-1][j];
                    if(b.first>a.first){
                        a.second-=(a.first-b.first);
                        a.first=b.first;
                    }
                    if(c.second>a.second){
                        a.first-=a.second-c.second;
                        a.second=c.second;
                    }
                    dp[i][j]=a;
                    ans+=(i-a.first+1);
                }
            }
        }
        return ans;
    }
};