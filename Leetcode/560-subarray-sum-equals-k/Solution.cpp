class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        long long psum=0;
        int ans=0;
        multiset<long long> s;
        for(auto i:nums){
            psum+=i;
            s.insert(psum);
            if(psum==k)
                ans+=1;
            ans+=s.count(psum-k);
            if(k==0) ans-=1;
        }
        return ans;
    }
};