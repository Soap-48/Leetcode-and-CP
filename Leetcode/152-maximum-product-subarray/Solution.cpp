class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long ans=-1e10;
        int i=0,ii=0,n=nums.size();
        while(i<n){
            ii=i;
            int c=0,li=0;long long prod=1;
            while(i<n&&nums[i]!=0){
                prod=prod*nums[i];
                if(nums[i]<0)
                    li=i;
                c+=1;
                i+=1;
            }
            if(prod<0){
                if(c>1){
                long long val1=1,val2=1;
                while(nums[ii]>0){
                    val1=val1*nums[ii];
                    ii+=1;
                }
                val1=val1*(nums[ii]);
                for(int l=li;l<i;l+=1)
                    val2=val2*nums.at(l);
                val2=val2;
                prod=prod/(max(val1,val2));
                }
                
            }
            if(c>0) ans=max(ans,prod);
            if(i<n&&nums[i]==0)
                    ans=max(ans,0LL);
            i+=1;
        }
        return ans;
    }
};