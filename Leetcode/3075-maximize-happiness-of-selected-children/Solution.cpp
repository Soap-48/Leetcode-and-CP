class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(),happiness.rend());
        long long ans=0;
        for(int i=0;i<k;i+=1){
            if(happiness[i]>i){
                ans+=(happiness[i]-i);
            }
            else break;
        }
        return ans;
    }
};