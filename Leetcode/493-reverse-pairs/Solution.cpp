int ans=0;

class Solution {
public:

    void conquer(vector<int>& nums,vector<int> &temp,int l,int m,int r){
        int i=l,j=m;
        int it=i;

        while(i<m&&j<r){
            if(nums[i]*1LL>(nums[j]*2LL)){
                ans+=(m-i);
                j+=1;
            }
            else
                i+=1;
        }
        
        i=l,j=m;
        while(i<m&&j<r){
            if(nums[i]>=nums[j]){
                temp[it++]=nums[j];
                j+=1;
            }
            else{
                temp[it++]=nums[i];
                i+=1;
            }
        }
        while(i<m){
            temp[it++]=nums[i++];
        }
        while(j<r)
            temp[it++]=nums[j++];
        for(int i=l;i<r;i+=1)
            nums[i]=temp[i];
    }

    void divide(vector<int>& nums,vector<int> &temp,int l,int r){
        if(r-l>1){
            int m=(l+r)/2;
            divide(nums,temp,l,m);
            divide(nums,temp,m,r);
            conquer(nums,temp,l,m,r);
        }
    }
    int reversePairs(vector<int>& nums) {
        ans=0;
        vector<int> temp(nums.size());
        divide(nums,temp,0,nums.size());
        return ans;
    }
};