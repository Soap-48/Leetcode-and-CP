class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size(),l=0,r=n-1,ans=nums[0];
        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]>nums[r])
                l=m+1;
            else{
                r=m-1;
                ans=min(ans,nums[m]);
            }
        }
        return ans;
    }
};