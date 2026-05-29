class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> a(n+1),b(n+1);
        a[0]=0;b[n]=0;
        for(int i=0;i<n;i+=1){
            if(customers[i]=='Y')
                a[i+1]=a[i];
            else
                a[i+1]=a[i]+1;
        }
        for(int i=n-1;i>=0;i-=1){
            if(customers[i]=='Y')
                b[i]=b[i+1]+1;
            else
                b[i]=b[i+1];
        }
        int val=INT_MAX,ans=-1;
        for(int i=0;i<=n;i+=1){
            int k=a[i]+b[i];
            if(k<val){
                val=k;
                ans=i;
            }
        }
        return ans;
    }
};