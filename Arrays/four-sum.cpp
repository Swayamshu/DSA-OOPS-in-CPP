vector<vector<int> > fourSum(vector<int> &nums, int target)
{
    if (nums.size() < 4)
        return {};
    vector<vector<int> > ans;
    set<vector<int> > s;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 3; i++)
    {
        for (int j = i + 1; j < nums.size() - 2; j++)
        {
            long newTarget = (long)target - (long)nums[i] - (long)nums[j];
            int start = j + 1, end = nums.size() - 1;

            while (start < end)
            {
                if (nums[start] + nums[end] < newTarget)
                    start++;
                else if (nums[start] + nums[end] > newTarget)
                    end--;
                else
                {
                    s.insert({nums[i], nums[j], nums[start], nums[end]});
                    start++;
                    end--;
                }
            }
        }
    }

    for (auto v : s)
        ans.push_back(v);

    return ans;
}