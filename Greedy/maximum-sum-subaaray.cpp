// https://cses.fi/problemset/task/1643/

/*
Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9
*/

// KADANE's Algorithm

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    ll maxSum = a[0], sum = a[0];
    FOR(i, 1, n)
    {
        sum = max(sum + a[i], (ll)a[i]);
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;
}
