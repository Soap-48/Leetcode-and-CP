class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,max=0;
        if(nums.size()==1)  return nums[0];
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            if(sum<0){
                sum=0;
    
            }
            else if(sum>max){
                max=sum;
            }
            
            
        }
        if(max==0){
                int min=nums[0];
                for(int i:nums)
                    if(i>min)   min=i;
                return min;
        }
        return max;
    }
};