class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i+=1){
            int t=-nums[i];
            int l=i+1,r=nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]==t){
                    ans.insert({nums[i],nums[l],nums[r]});
                    l+=1;
                }
                else if(nums[l]+nums[r]<t)
                    l+=1;
                else 
                    r-=1;
            }
        }
        vector<vector<int>> ta;
        for(auto i:ans)
            ta.push_back(i);
        return ta;
    }
};