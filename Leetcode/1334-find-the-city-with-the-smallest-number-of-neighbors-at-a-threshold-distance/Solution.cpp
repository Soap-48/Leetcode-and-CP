class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //floyd warhsall victim
        vector<vector<int>> a(n,vector<int>(n,1e8));
        for(vector<int> &i:edges){
            a[i[0]][i[1]]=i[2];
            a[i[1]][i[0]]=i[2];
        }
        for(int i=0;i<n;i+=1)
            a[i][i]=0;
        for(int i=0;i<n;i+=1)
            for(int j=0;j<n;j+=1)
                for(int k=0;k<n;k+=1)
                    a[j][k]=min(a[j][k],a[j][i]+a[i][k]);
        int ans=-1,val=n+1;
        for(int i=0;i<n;i+=1){
            int c=0;
            for(int j=0;j<n;j+=1)
                if(a[i][j]<=distanceThreshold)
                    c+=1;
            if(c<=val){
                val=c;
                ans=i;
            }
        }
        return ans;
    }
};