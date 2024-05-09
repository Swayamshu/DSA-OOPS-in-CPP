// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

int maxSubArray(vector<int> &nums)
{
    int maxSum = nums[0],
        curSum = nums[0];

    for (int i = 1; i < nums.size(); i++)
    {
        curSum = nums[i] + max(0, curSum);
        maxSum = max(maxSum, curSum);
    }

    return maxSum;
}