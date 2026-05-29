#include <bits/stdc++.h>
using namespace std;

//couldnt solve had to see editorial
int n;

double help(vector<vector<vector<double>>> &dp,double x,double y, double z){
    if(x<0||y<0||z<0)
        return 0;
    if(dp[x][y][z]!=-1)
        return dp[x][y][z];
    double val=n+x*help(dp,x-1,y,z)+y*help(dp,x+1,y-1,z)+z*help(dp,x,y+1,z-1);
    return dp[x][y][z]=val/(x+y+z);
}

int main() {
	// your code goes here
    cin>>n;
    int a;
    double x=0,y=0,z=0;
    for(int i=0;i<n;i+=1){
        cin>>a;
        if(a==1)
            x+=1;
        else if(a==2)
            y+=1;
        else
            z+=1;
    }
    vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(n+1,vector<double>(n+1,-1)));
    dp[0][0][0]=0;
    cout<< std::fixed << std::setprecision(10)<<help(dp,x,y,z);
    return 0;
}

