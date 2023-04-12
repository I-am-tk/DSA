class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = nums[0];
        for(auto val: nums){
            sum += val;
            maxSum = max(sum, maxSum);
            if(sum < 0){
                sum = 0;
            }
        }
        return maxSum;
    }
};