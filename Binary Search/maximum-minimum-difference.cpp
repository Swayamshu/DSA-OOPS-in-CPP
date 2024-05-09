// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/description/

/*
Input: nums = [10,1,2,7,1,3], p = 2
Output: 1
Explanation: The first pair is formed from the indices 1 and 4,
 and the second pair is formed from the indices 2 and 5. 
The maximum difference is max(|nums[1] - nums[4]|, 
|nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
*/

bool can_form_pair(vector<int> &nums, int mid, int p)
{
    int cnt = 0;

    for (int i = 0; i < nums.size() - 1 && cnt < p;)
    {
        if (nums[i + 1] - nums[i] <= mid)
        {
            cnt++;
            i += 2;
        }
        else
            i++;
    }

    return cnt >= p;
}

int minimizeMax(vector<int> &nums, int p)
{
    sort(nums.begin(), nums.end());

    int left = 0, right = nums.back() - nums.front();

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (can_form_pair(nums, mid, p))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}