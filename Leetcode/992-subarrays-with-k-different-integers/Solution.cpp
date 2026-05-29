class Solution {
public:
    int ffg(vector<int> &arr, int k) {
        int ans=0,n=arr.size();
        int l=0,r=0,c=0;
        map<int,int> m;
        for(;r<n;r+=1){
            if(m[arr[r]]==0)
                c+=1;
            m[arr[r]]+=1;
            if(c>k){
                while(c>k && l<=r){
                    m[arr[l]]-=1;
                    if(m[arr[l]]==0)
                        c-=1;
                    l+=1;
                }
            }
            ans+=r-l+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return ffg(nums,k)-ffg(nums,k-1);
    }
};