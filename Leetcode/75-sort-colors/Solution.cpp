class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=-1,j=-1,k=0;
        while(k<nums.size()){
            switch(nums[k]){
                case 2: break;
                case 1: nums[k]=2;
                        nums[++j]=1;
                        break;
                case 0: nums[k]=2;
                        nums[++j]=1;
                        nums[++i]=0;
                        break;
            }
            k+=1;
        }
    }
};