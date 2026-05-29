class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        long long ans=0;
        for(auto &i:nums){
            int j=i;
            while(j>0){
                if(j%10==digit)
                    ans+=1;
                j/=10;
            }
        }
        return ans;
    }
};