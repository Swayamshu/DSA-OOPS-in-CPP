// https://leetcode.com/problems/find-the-longest-equal-subarray/description/

/*
Example 1:
Input: nums = [1,3,2,3,1,3], k = 3
Output: 3
Explanation: It's optimal to delete the elements at index 2 and index 4.
After deleting them, nums becomes equal to [1, 3, 3, 3].
The longest equal subarray starts at i = 1 and ends at j = 3 with length equal to 3.
It can be proven that no longer equal subarrays can be created.

Example 2:
Input: nums = [1,1,2,2,1,1], k = 2
Output: 4
Explanation: It's optimal to delete the elements at index 2 and index 3.
After deleting them, nums becomes equal to [1, 1, 1, 1].
The array itself is an equal subarray, so the answer is 4.
It can be proven that no longer equal subarrays can be created.
*/
//"hnisnfvikgrhkfoe"
// "hgkivsifrekfonnh"

    int
    longestEqualSubarray(vector<int> &nums, int k)
{
    int len = 0, most = 0;
    unordered_map<int, int> cnt;

    for (int i = 0, j = 0; i < nums.size(); i++)
    {
        // most = max freq elements in given window
        most = max(most, ++cnt[nums[i]]);

        while ((i - j + 1) - most > k) // sliding window
        {
            --cnt[nums[j]];
            j++;
        }

        len = max(len, most);
    }

    return len;
}