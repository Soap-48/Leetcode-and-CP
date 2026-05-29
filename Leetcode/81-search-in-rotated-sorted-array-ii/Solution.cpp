class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1,ans=-1;
        while(l<=r){
            if(nums[l]==nums[r]){
                while(l<=r&& nums[l]==nums[r])
                    r-=1;
                if(l>r) return nums[l]==target;
            }
            int m=(l+r)/2;
            if(nums[m]==target)
                return true;
            if(nums[r]>=nums[m]){
                if(nums[m]<target&&nums[r]>=target)
                    l=m+1;
                else
                    r=m-1;
            }
            else if(nums[l]<=nums[m]){
                if(nums[m]>target&&nums[l]<=target)
                    r=m-1;
                else
                    l=m+1;
            }
        }
        return false;
    }
};