class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i+=1){
            for(int j=1;j<=m;j+=1){
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        string ans;
        int i=n,j=m;
        while(i>0&&j>0){
            if(str1[i-1]==str2[j-1]){
                ans+=str1[i-1];
                i-=1;j-=1;
            }
            else if(dp[i][j]==dp[i-1][j])
                i-=1;
            else
                j-=1;
        }
        reverse(ans.begin(),ans.end());
        string tt;
        int a=0,b=0,c=0;
        while(a<n&&b<m&&c<dp[n][m]){
            while(a<n&&str1[a]!=ans[c]){
                tt+=str1[a];
                a+=1;
            }
            while(b<m&&str2[b]!=ans[c]){
                tt+=str2[b];
                b+=1;
            }
            tt+=ans[c];
            c+=1;a+=1;b+=1;
        }
        while(a<n){
            tt+=str1[a];
            a+=1;
        }
        while(b<m){
            tt+=str2[b];
            b+=1;
        }
        //cout<<ans;
        return tt;
    }
};