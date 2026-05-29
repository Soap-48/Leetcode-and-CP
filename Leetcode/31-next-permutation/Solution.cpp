class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2,r=n-1;
        for(;i>=0;i-=1){
            if(nums[i]<nums[i+1]){
                r=i+1;
                for(int j=i+1;j<n;j++)
                    if(nums[j]>nums[i]&&nums[j]<=nums[r])
                        r=j;
                int k=nums[r];
                nums[r]=nums[i];
                nums[i]=k;
                break;
            }
        }
        i+=1;
        r=n-1;
        while(i<r){
            int k=nums[i];
            nums[i]=nums[r];
            nums[r]=k;
            i+=1;
            r-=1;
        }
    }
};