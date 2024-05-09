// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/description/

int shortestSubarray(vector<int> &A, int k)
{
    int n = A.size(), len = n + 1;
    vector<long> nums(A.begin(), A.end());
    deque<int> dq;

    for (int i = 0; i < n; i++)
    {
        if (0 < i)
            nums[i] += nums[i - 1];

        if (nums[i] >= k)
            len = min(len, i + 1);

        while (!dq.empty() && nums[i] - nums[dq.front()] >= k)
        {
            len = min(len, i - dq.front());
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] >= nums[i])
            dq.pop_back();

        dq.push_back(i);
    }

    return len <= n ? len : -1;
}