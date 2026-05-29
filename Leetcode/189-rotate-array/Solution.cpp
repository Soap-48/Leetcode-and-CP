class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
                k=k%n;
        if(k==0||n<=1)    return;
        int aux[k];
        for(int i=n-k;i<n;i+=1){
            aux[i-n+k]=nums[i];
        }
        int i=n-1;
        for(;i>=k;i-=1)
            nums[i]=nums[i-k];
        for(;i>=0;i-=1)
            nums[i]=aux[i];
    }
    
};