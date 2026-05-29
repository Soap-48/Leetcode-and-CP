class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        /*int i=-1,j=0,n=nums.size();
        if(n<=1)    return;
        if(nums[0]==0) while(j<n){
            if(nums[j]!=0){
                nums[++i]=nums[j];
                nums[j]=0;
            }
            j+=1;
        }
        else{
            i=0;
            while(j<n&&nums[j]!=0)
                ++j;
            while(j<n-1&&nums[++j]==0) ;
            j-=1;
            while(j<n){
            if(nums[j]!=0){
                nums[++i]=nums[j];
                nums[j]=0;
            }
            j+=1;
        }
        }*/

        int i=-1,j=0,n=nums.size();
        if(n<=1)    return;
        while(j<n&&nums[j]!=0)
        {
            ++i;++j;
        }
        while(j<n){
            if(nums[j]!=0){
                nums[++i]=nums[j];
                nums[j]=0;
            }
            j+=1;
        }

    }
};