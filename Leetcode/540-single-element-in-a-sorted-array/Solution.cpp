class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size(),l=0,r=n-1;
        int ans=n-1;
        while(l<=r){
            int m=(l+r)/2;
            int last=m;
            if(m+1<n&&nums[m+1]==nums[m])
                last=m+1;
            if(last%2){
                l=m+1;
            }         
            else{
                ans=nums[m];
                r=m-1;
            }     
        }
        return ans;
    }
};