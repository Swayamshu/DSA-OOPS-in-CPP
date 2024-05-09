// https://leetcode.com/problems/subarray-sum-equals-k/

/*
Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/

int subarraySum(vector<int> &nums, int k)
{
    map<int, int> presum;
    int ans = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
            ans++;
        if (presum.count(sum - k))
            ans += presum[sum - k];
        presum[sum]++;
    }
    return ans;
}