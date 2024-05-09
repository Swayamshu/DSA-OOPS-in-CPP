// Merge Sort Approach

int merge(int lo, int mid, int hi, vector<int> &nums)
{
    int cnt = 0;
    int j = mid + 1;

    for (int i = lo; i <= mid; i++)
    {
        while (j <= hi && nums[i] > 2LL * nums[j])
            j++;
        cnt += j - (mid + 1);
    }

    vector<int> copy;
    int l = lo, r = mid + 1;
    while (l <= mid && r <= hi)
    {
        if (nums[l] <= nums[r])
            copy.push_back(nums[l++]);
        else
            copy.push_back(nums[r++]);
    }

    while (l <= mid)
        copy.push_back(nums[l++]);
    while (r <= hi)
        copy.push_back(nums[r++]);

    for (int i = lo; i <= hi; i++)
        nums[i] = copy[i - lo];

    return cnt;
}

int mergeSort(int lo, int hi, vector<int> &nums)
{
    if (lo >= hi)
        return 0;

    int mid = lo + (hi - lo) / 2;

    int cnt = mergeSort(0, mid, nums) + mergeSort(mid + 1, hi, nums);
    cnt += merge(lo, mid, hi, nums);

    return cnt;
}

int reversePairs(vector<int> &nums)
{
    return mergeSort(0, nums.size() - 1, nums);
}

// Binary Indexed Tree or Fenwick Tree Method

void update(int idx, vector<int> &BIT)
{
    while (idx > 0)
    {
        BIT[idx] += 1;
        idx -= idx & -idx;
    }
}

int search(int idx, vector<int> &BIT)
{
    int sum = 0;
    while (idx < BIT.size())
    {
        sum += BIT[idx];
        idx += idx & -idx;
    }
    return sum;
}

int index(vector<int> &arr, long val)
{
    int lo = 0,
        hi = arr.size() - 1,
        mid;

    while (lo <= hi)
    {
        mid = lo + (hi - lo) / 2;

        if (arr[mid] >= val)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    return lo + 1;
}

int reversePairs(vector<int> &nums)
{
    int ans = 0;
    vector<int> mask = nums;
    vector<int> BIT(nums.size() + 1, 0);

    sort(mask.begin(), mask.end());

    for (int num : nums)
    {
        ans += search(index(mask, 2L * num + 1), BIT);
        update(index(mask, num), BIT);
    }
    return ans;
}