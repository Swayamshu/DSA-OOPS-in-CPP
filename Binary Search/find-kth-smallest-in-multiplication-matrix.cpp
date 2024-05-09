// https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/

/*
Input: m = 3, n = 3, k = 5
Output: 3
Explanation: The 5th smallest number is 3.

Input: m = 2, n = 3, k = 6
Output: 6
Explanation: The 6th smallest number is 6.
*/

int findKthNumber(int m, int n, int k)
{
    int start = 0, end = m * n, mid, cnt;

    while (start <= end)
    {
        mid = start + (end - start) / 2;
        cnt = 0;

        for (int i = 1; i <= m; i++)
            cnt += min(n, mid / i);

        if (cnt >= k)
            end = mid - 1;
        else
            start = mid + 1;
    }

    return start;