class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i+=1)
            if(!(nums[i]&1))
                m[nums[i]]+=1;
        int ans=-1;
        int c=0;
        if(m.empty())   return -1;
        else{
            for(auto &[i,j]:m){
                if(c<j) {ans=i;c=j;}
                else if(c==j)   ans=min(ans,i);
            }
            return ans;
        }
    }
};