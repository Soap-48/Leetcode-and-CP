class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element,count=0;
        for (int i:nums){
            if (count==0){
                element = i;
                count+=1;
            }
            else if(element==i)
                count+=1;
            else count-=1;
        }
        return element;
    }
};