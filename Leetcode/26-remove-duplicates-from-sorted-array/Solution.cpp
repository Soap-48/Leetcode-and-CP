class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        short int i = 0;
        {
        short int j = 1;
        while (j < nums.size()) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
            j+=1;
        }
        }
        return i + 1;
    }
};