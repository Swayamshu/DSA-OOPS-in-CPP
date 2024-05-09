// https://leetcode.com/problems/maximal-rectangle/description/

/*
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
*/

int getMaxHistogramArea(vector<int> &histogram)
{
    int n = histogram.size();

    vector<int> nsl(n, -1);
    stack<ii> sl;
    for (int i = 0; i < n; i++)
    {
        while (!sl.empty() && sl.top().s >= histogram[i])
            sl.pop();

        if (!sl.empty())
            nsl[i] = sl.top().f;

        sl.push({i, histogram[i]});
    }

    vector<int> nsr(n, n);
    stack<ii> sr;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!sr.empty() && histogram[i] <= sr.top().s)
            sr.pop();

        if (!sr.empty())
            nsr[i] = sr.top().f;

        sr.push({i, histogram[i]});
    }

    int area = 0;
    for (int i = 0; i < n; i++)
    {
        int h = histogram[i],
            w = nsr[i] - nsl[i] - 1,
            a = w * h;
        area = max(a, area);
    }

    return area;
}

int maximalRectangle(vector<vector<char> > &matrix)
{
    int n = matrix.size(),
        m = matrix[0].size(),
        area = 0;

    vector<int> histogram(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
                histogram[j] = 0;
            else
                histogram[j] += 1;
        }
        area = max(getMaxHistogramArea(histogram), area);
    }

    return area;
}