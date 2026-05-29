    

#include <bits/stdc++.h>

const long long MOD=1e9+7;

using namespace std;

int main() {
	// your code goes here
	int h,w;
	cin>>h>>w;
	vector<vector<char>> grid(h+2,vector<char>(w+2,'#'));
	for(int i=1;i<=h;i+=1)
	    for(int j=1;j<=w;j+=1)
	        cin>>grid[i][j];
	vector<vector<long long>> dp(h+2,vector<long long>(w+2,0));
	dp[0][1]=1;
	for(int i=1;i<=h;i+=1)
	    for(int j=1;j<=w;j+=1)
	        if(grid[i][j]=='.')
	            dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
	 cout<<dp[h][w];
}

