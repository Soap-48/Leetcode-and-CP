class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i+=1){
            if(i>0&&nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j+=1){
                if(j>i+1&&nums[j]==nums[j-1]) continue;
                long long t=target*1ll-nums[i]-nums[j];
                int l=j+1,r=n-1;
                while(l<r){
                    if(nums[l]*1ll+nums[r]>t)
                        r-=1;
                    else if(nums[l]*1ll+nums[r]<t)
                        l+=1;
                    else{
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l+=1;r-=1;
                        while(l<n&& nums[l]==nums[l-1]) l+=1;
                        while(r>0&& nums[r]==nums[r+1]) r-=1;
                    }
                }
            }
        }
        return ans;
    }
};