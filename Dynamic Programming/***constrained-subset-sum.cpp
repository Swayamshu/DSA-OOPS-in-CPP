// https://leetcode.com/problems/constrained-subsequence-sum/

/*
Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Example 2:
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

Example 3:
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
*/

// knapsack approach
// time: O(N * K)
class Solution
{
    int min_sum;
    vector<map<int, int> > dp;

    int subsetSum(int idx, int prev, vector<int> &nums, int k)
    {
        if (idx == nums.size())
        {
            if (prev == -1)
                return min_sum;
            return 0;
        }
        if (dp[idx].count(prev))
            return dp[idx][prev];

        int skip_curr = subsetSum(idx + 1, prev, nums, k);
        int take_curr = min_sum;
        if (prev == -1 || idx - prev <= k)
        {
            take_curr = nums[idx] + subsetSum(idx + 1, idx, nums, k);
        }

        return dp[idx][prev] = max(skip_curr, take_curr);
    }

public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)`
        {
            dp[i] = nums[i];
        }

        int ans = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = i - 1; i - j <= k && j >= 0; j--)
            {
                dp[i] = max(dp[i], nums[i] + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        // time: O(n * k)
        return ans;
    }
};

// more optimized using priority queue
// maintain window of k
// time : O(N * log(K))

class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        vector<int> dp = nums;
        priority_queue<pair<int, int> > pq;
        pq.push({dp[0], 0});

        int ans = dp[0];
        for (int i = 1; i < nums.size(); i++)
        {
            while (!pq.empty() && pq.top().second < i - k)
                pq.pop();

            dp[i] = max(dp[i], nums[i] + pq.top().first);
            pq.push({dp[i], i});

            ans = max(ans, dp[i]);
        }

        // time: O(n * log(k))
        return ans;
    }
};

// more optimized
// using deque to maintain sums of window K in decreasing order
// Time: O(N) -> beacuse all elements are pushed and popped at most once
// *Space: O(K) (IF INPLACE MODIFICATIONS ARE DONE ON ARRAY)
//              -> at most K elements in deque
// Space: O(N) -> sum array
class Solution
{
public:
    int constrainedSubsetSum(vector<int> &nums, int k)
    {
        vector<int> sum = nums;
        deque<int> dq;
        int ans = sum[0];

        for (int i = 0; i < nums.size(); i++)
        {
            // dq -> maintains window K -> dq.front() = j
            while (!dq.empty() && dq.front() < i - k)
                dq.pop_front();

            // dq.front() -> MAX_SUM till that index
            if (!dq.empty())
                sum[i] = max(sum[i], nums[i] + sum[dq.front()]);

            // maintain deque in DECREASING order
            // remove all sums from end if <= curr max_sum
            // as these sums are within window K but are less, so they're not needed
            while (!dq.empty() && sum[i] >= sum[dq.back()])
                dq.pop_back();

            dq.push_back(i);
            ans = max(ans, sum[i]);
        }

        return ans;
    }
};