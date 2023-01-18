class Solution {
public:
    int normalSum(vector<int>& nums)
    {
        int n = nums.size();
        int res = nums[0];
        int currMax = nums[0];
        for(int i=1;i<n;i++)
        {
            currMax = max(currMax+nums[i],nums[i]);
            res = max(res,currMax);
        }
        return res;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxNormalSum = normalSum(nums);
        if(maxNormalSum < 0)
           return maxNormalSum;
        int totalSum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            totalSum += nums[i];
            nums[i] = -1*nums[i];
        }
        int circularSum = totalSum + normalSum(nums);
        return max(maxNormalSum,circularSum);
    }
};