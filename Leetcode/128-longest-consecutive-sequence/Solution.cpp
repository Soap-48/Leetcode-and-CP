class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
                if(nums.size()==0)  return 0;

        sort(nums.begin(),nums.end());
     //   for( int a: nums)
       //     cout<<a;
        int l=0,ans=0,i=nums[0];
        for(int a: nums){
            if(a==i){
                l+=1;
                if(l>ans)   ans=l;
            }
            else if(a==i-1){
                continue;
            }
            else {
                l=1;
                i=a;
            }
            ++i;
        }
        return ans;
    }
};