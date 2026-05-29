class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i+=1){
            int a=i;
            vector<int> kk;
            for(int k=0;k<n;k+=1){
                if(a&1)
                    kk.push_back(nums[k]);
                a=a/2;
            }
            ans.push_back(kk);
        }
        return ans;
    }
};