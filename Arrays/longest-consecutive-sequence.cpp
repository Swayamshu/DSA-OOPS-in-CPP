// Brute Force

unordered_map<int, int> m;
vector<bool> visited;

int traverse(int pos, vector<int> &nums)
{
    int res = 1;
    if (m.count(nums[pos] - 1))
    {
        int next = m[nums[pos] - 1];
        res += traverse(next, nums);
    }
    return res;
}

int longestConsecutive(vector<int> &nums)
{
    int n = nums.size();
    (n, 0);
    m.clear();
    visited = vector<bool>(n, 0);

    for (int i = 0; i < n; i++)
        m[nums[i]] = i;

    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            cnt = max(cnt, traverse(i, nums));
    return cnt;
}

// [modified] Hash-map -> no. of consecutive sub arrays with sum = k

int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> presum;
    int ans = 0,
        sum = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];

        if (sum == k)
            ans++;

        if (presum.find(sum - k) != presum.end())
            ans += presum[sum - k];

        presum[sum]++;
    }

    return ans;
}