class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return {nums[0]};
        int n1=1e9+1,n2=1e9+1;
        int c1=0,c2=0;
        for(int i=0;i<n;i+=1){
            if(c1==0&&n2!=nums[i]){
                n1=nums[i];
                c1=1;
            }
            else if(c2==0&&n1!=nums[i]){
                n2=nums[i];
                c2=1;
            }
            else if(nums[i]==n1)
                c1+=1;
            else if(nums[i]==n2)
                c2+=1;
            else{
                c1-=1;
                c2-=1;
            }
        }
        int tc1=0,tc2=0;
        for(int i=0;i<n;i+=1){
            if(nums[i]==n1)
                tc1+=1;
            else if(nums[i]==n2)
                tc2+=1;
        }
        vector<int> ans;
        if(tc1>n/3) ans.push_back(n1);
        if(tc2>n/3) ans.push_back(n2);
        return ans;
    }
};