class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        int n=tasks.size();
        sort(tasks.begin(),tasks.end(),[](auto &x,auto &y){
            // if(x[1]!=y[1])
            //     return y[1]<x[1];
            // else
            //     return y[0]>x[0];
            if(x[1]-x[0]!=y[1]-y[0])
                return x[1]-x[0]>y[1]-y[0];
            else
                return x[1]>y[1];
        });
        long long l=0,r=0;
        for(int i=0;i<n;i+=1){
            l+=tasks[i][0];
            r+=tasks[i][1];
        }
        long long ans=l;
        //r+=l;
        l-=1;r+=1;
        while(r-l>1){
            long long m=(l+r)/2;
            bool flag=true;
            long long left=m;
            for(int i=0;i<n;i+=1){
                if(left<tasks[i][1]){
                    flag=false;
                    break;
                }
                left-=tasks[i][0];
            }
            if(flag){
                r=m;
                ans=m;
            }
            else
                l=m;
        }
        return ans;
    }
};