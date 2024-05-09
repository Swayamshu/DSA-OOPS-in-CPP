// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

// Brute Force

int majorityElement(vector<int> &nums) // Time: O(nlogn), Space(1)
{
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

/* Moore Voting Algorithm
    The intuition behind the Moore's Voting Algorithm is based on the fact that
    if there is a majority element in an array, it will always remain in the lead,
    even after encountering other elements.
*/

int majorityElement(vector<int> &nums) // Time: O(n), Space: O(1)
{
    int cnt = 0,
        cnd = 0;

    for (int num : nums)
    {
        if (cnt == 0)
            cnd = num;

        if (num == cnd)
            cnt++;
        else
            cnt--;
    }

    return cnd;
}

// Majority Element 2
// Boyer-Moore Voting Algorithm

vector<int> majorityElement(vector<int> &nums) // Time: O(n), Space: O(1)
{
    int num1 = INT_MIN,
        num2 = INT_MIN,
        cnt1 = 0,
        cnt2 = 0;

    for (int num : nums)
    {
        if (num1 == num)
            cnt1++;
        else if (num2 == num)
            cnt2++;
        else if (cnt1 == 0)
        {
            num1 = num;
            cnt1++;
        }
        else if (cnt2 == 0)
        {
            num2 = num;
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    vector<int> ans;
    int n = nums.size();
    cnt1 = 0, cnt2 = 0;

    for (int num : nums)
    {
        if (num1 == num)
            cnt1++;
        if (num2 == num)
            cnt2++;
    }

    if (cnt1 > n / 3)
        ans.push_back(num1);
    if (cnt2 > n / 3)
        ans.push_back(num2);

    return ans;
}