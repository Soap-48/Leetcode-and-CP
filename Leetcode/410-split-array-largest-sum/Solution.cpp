class Solution {
public:

    int possible(vector<int> &nums,int val){
        int tr=0,c=0;
        for(auto i:nums){
            if(tr+i<=val)
                tr+=i;
            else{
                c+=1;
                tr=i;
            }
        }
        return c;
    }

    int splitArray(vector<int>& nums, int k) {
        int n=nums.size(),a=(*max_element(nums.begin(),nums.end()));
        int sum=0,ans=a;
        for(auto i:nums)
            sum+=i;
        int l=a,r=sum;
        while(l<=r){
            int m=(l+r)/2;
            int flag=possible(nums,m);
            if(flag<k){
                ans=m;
                r=m-1;
            }
            else
                l=m+1;
        }
        return ans;
    }
};