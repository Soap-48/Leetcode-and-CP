class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
        dp[0][0]=1;
        // for(int i=1;i<=s3.size();i+=1){
        //     for(int j=1;j<=min(i,(int)s1.size());j+=1){
        //         if(i-j<=s2.size()&&dp[j-1][i-j]!=0){
        //             if(s3[i-1]==s1[j-1])
        //                 dp[j][i-j]=1;
        //             if(i-j<s2.size()&&s3[i-1]==s2[i-j])
        //                 dp[j-1][i-j+1]=1;
        //         }
        //     }
        // }
        for(int i=0;i<=s1.size();i+=1){
            for(int j=0;j<=s2.size();j+=1){
                if(i<s1.size()&&dp[i][j]==1&&s3[i+j]==s1[i])
                    dp[i+1][j]=1;
                if(j<s2.size()&&dp[i][j]==1&&s3[i+j]==s2[j])
                    dp[i][j+1]=1;
            }
        }
        return dp[s1.size()][s2.size()];
    }
};