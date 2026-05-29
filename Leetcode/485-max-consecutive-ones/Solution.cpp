class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0,n=nums.size();int ans=0;
        for(int i=0;i<n;i+=1){
            if(nums[i]!=1)  c=0;
            else {c+=1;
            if(c>ans) 
            ans=c;}
        }
        return ans;
    }
};