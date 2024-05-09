// https://leetcode.com/problems/find-in-mountain-array/description/?envType=daily-question&envId=2023-10-12

/*
Example 1:
Input: array = [1,2,3,4,5,3,1], target = 3
Output: 2
Explanation: 3 exists in the array, at index=2 and index=5. Return the minimum index, which is 2.

Example 2:
Input: array = [0,1,2,4,2,1], target = 3
Output: -1
Explanation: 3 does not exist in the array, so we return -1.
*/

/*
TIP:
If I want to find the index, I always use while (left < right)
If I may return the index during the search, I'll use while (left <= right)
*/

int findPeak(MountainArray &arr)
{
    int left = 0, right = arr.length() - 1, mid;
    while (left < right) // find index -> left < right
    {
        mid = (left + right) >> 1;

        if (arr.get(mid - 1) < arr.get(mid) && arr.get(mid) > arr.get(mid + 1))
            return mid;
        else if (arr.get(mid - 1) < arr.get(mid) && arr.get(mid) < arr.get(mid + 1))
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int searchLeft(int left, int right, MountainArray &arr, int target)
{
    int mid;
    while (left <= right) // return index -> left <= right
    {
        mid = (left + right) >> 1;

        if (arr.get(mid) < target)
            left = mid + 1;
        else if (arr.get(mid) > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

int findInMountainArray(int target, MountainArray &arr)
{
    int peak = findPeak(arr), n = arr.length();

    int left = searchLeft(0, peak, arr, target),
        right = searchRight(peak, n - 1, arr, target);

    cout << peak << " " << left << " " << right;
    return left != -1 ? left : right;
}