// https://leetcode.com/problems/burst-balloons/description/

/*
Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
*/

int getCoins(int start, int end, vector<int> &nums, vector<vector<int> > &dp)
{
    if (start > end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    if (start == end)
        return dp[start][end] = nums[start - 1] * nums[start] * nums[start + 1];

    for (int lastBurst = start; lastBurst <= end; ++lastBurst)
    {
        dp[start][end] = max(
            dp[start][end],
            nums[start - 1] * nums[lastBurst] * nums[end + 1] +
                getCoins(start, lastBurst - 1, nums, dp) +
                getCoins(lastBurst + 1, end, nums, dp));
    }

    return dp[start][end];
}

int maxCoins(vector<int> &nums)
{
    vector<int> newNums = {1};
    for (auto &num : nums)
        if (num)
            newNums.push_back(num);
    newNums.push_back(1);

    vector<vector<int> > dp(newNums.size() - 1, vector<int>(newNums.size() - 1, -1));

    return getCoins(1, newNums.size() - 2, newNums, dp);
}