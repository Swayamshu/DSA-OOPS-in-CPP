// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

/*
    Input: n = 6 
    arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
    dep[] = {0910, 1200, 1120, 1130, 1900, 2000}

    Output: 3

    Explanation: Minimum 3 platforms are required to 
    safely arrive and depart all trains.
*/

int findPlatform(int arr[], int dep[], int n)
{
    map<int, int> times;
    for (int i = 0; i < n; i++)
    {
        times[arr[i]]++;
        times[dep[i] + 1]--;
    }

    int sum = 0, platforms = 0;
    for (auto t : times)
    {
        sum += t.second;
        platforms = max(sum, platforms);
    }

    return platforms;
}