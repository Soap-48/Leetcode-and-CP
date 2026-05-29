const int inf=-1;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if(n==1)
            return 1;
        vector<int> ans(n,inf);
        vector<int> q;
        q.push_back(-1);
        if(ratings[0]<=ratings[1]){
            ans[0]=1;
            q.push_back(0);
        }
        for(int i=1;i<n-1;i+=1)
            if(ratings[i]<=ratings[i-1]&&ratings[i]<=ratings[i+1]){
                ans[i]=1;
                q.push_back(i);
            }
        if(ratings[n-1]<=ratings[n-2]){
            ans[n-1]=1;
            q.push_back(n-1);
        }
        q.push_back(n);
        for(int i=1;i<q.size()-1;i+=1){
            for(int j=q[i]+1;j<q[i+1];j+=1)
                if(ratings[j]>ratings[j-1])
                    ans[j]=max(ans[j],ans[j-1]+1);
                else
                    break;
            for(int j=q[i]-1;j>q[i-1];j-=1)
                if(ratings[j]>ratings[j+1])
                    ans[j]=max(ans[j],ans[j+1]+1);
                else
                    break;
        }
        int val=0;
        for(int i=0;i<n;i+=1)
            val+=ans[i];
        //,cout<<ans[i]<<' ';
        return val;
    }
};