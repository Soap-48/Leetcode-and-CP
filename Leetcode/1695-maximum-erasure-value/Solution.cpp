class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int i = 0, j = 0;
        int sum = 0, maxSum = 0;
        int n = nums.size();

        while (j < n) {
            if (seen.find(nums[j]) == seen.end()) {
                // Unique element, add to window
                sum += nums[j];
                seen.insert(nums[j]);
                maxSum = max(maxSum, sum);
                j++;
            } else {
                // Duplicate found, remove from start
                seen.erase(nums[i]);
                sum -= nums[i];
                i++;
            }
        }
        return maxSum;
    }
};
