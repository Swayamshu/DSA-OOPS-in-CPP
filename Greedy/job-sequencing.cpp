// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

/*
    Input:
    N = 4
    Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}

    Output:
    2 60

    Explanation: Job1 and Job3 can be done with
    maximum profit of 60 (20+40).

    Input:
    N = 5
    Jobs = {(1,2,100),(2,1,19),(3,2,27),
            (4,1,25),(5,1,15)}

    Output:
    2 127

    Explanation: 2 jobs can be done with
    maximum profit of 127 (100+27).
*/

/*
    struct Job {
        int id;
        int dead;
        int profit;
    }
*/

vector<int> JobScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comp);

    int d = 0;
    for (int i = 0; i < n; i++)
        d = max(arr[i].dead, d);

    vector<int> slot(d + 1, 0);
    int cnt = 0, profit = 0;
    for (int j = 0; j < n; j++)
    {
        for (int i = arr[j].dead; i > 0; i--)
        {
            if (slot[i] == 0)
            {
                slot[i] = 1;
                cnt++;
                profit += arr[j].profit;
                break;
            }
        }
    }

    return {cnt, profit};
}

static bool comp(Job a, Job b)
{
    return b.profit < a.profit;
}