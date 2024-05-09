void nextPermutation(vector<int> &nums)
{
    int pos = nums.size() - 2;
    for (; pos >= 0; pos--)
        if (nums[pos] < nums[pos + 1])
            break;

    if (pos < 0)
        sort(nums.begin(), nums.end());
    else
    {
        int i = nums.size() - 1;
        for (; i >= 0; i--)
            if (nums[pos] < nums[i])
                break;

        swap(nums[pos], nums[i]);
        sort(nums.begin() + pos + 1, nums.end());
    }
}