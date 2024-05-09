// https://www.interviewbit.com/problems/matrix-median/

/*
Example Input
Input 1: A = [  [1, 3, 5],
                [2, 6, 9],
                [3, 6, 9]   ]
Input 2: A = [  [5, 17, 100]    ]

Example Output
Output 1: 5
Output 2: 17
*/

int findMedian(vector<vector<int> > &A)
{
    int n = A.size(),
        m = A[0].size(),
        k = (n * m + 1) / 2,
        a = INT_MAX,
        b = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        a = min(A[i][0], a);
        b = max(A[i][m - 1], b);
    }

    while (a < b)
    {
        int mid = (a + b) / 2,
            cnt = 0;

        for (int i = 0; i < n; i++)
            cnt += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();

        if (cnt < k)
            a = mid + 1;
        else
            b = mid;
    }

    return a;
}
