// Input:
// 5
// 2 5 1 3 4
// Output:
// 4
// Explanation:
// We have a total of 4 pairs which satisfy the condition of inversion.
// (2, 1), (5, 1), (5, 3) and (5, 4).

void fenwickUpdate(int idx, int siz, vector<long long> &fenwick)
{
    while (idx <= siz)
    {
        // update current element in fenwick vector
        fenwick[idx] += 1;

        // increase the index to the child index in fenwick tree
        idx = idx + (idx & (-idx));
    }
}

long long fenwickSum(int idx, vector<long long> &fenwick)
{
    long long sum = 0;

    while (idx > 0)
    {
        // add value of current node
        sum += fenwick[idx];

        // move to parent node of current node
        idx = idx - (idx & (-idx));
    }

    return sum;
}

long long getInversions(long long *arr, int n)
{
    vector<vector<int> > m(n, vector<int>(2));
    vector<long long> fenwick(n + 1, 0), mask(n);

    // set up a map -> {arr[i], i}
    for (int i = 0; i < n; i++)
    {
        m[i][0] = arr[i];
        m[i][1] = i;
    }

    // sort map w.r.t arr[i] and update the permutation to mask
    sort(m.begin(), m.end());
    for (int i = 0; i < n; i++)
        mask[m[i][1]] = i + 1;

    long long ans = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        // calculate number of elements greater than current element
        ans += fenwickSum(mask[i] - 1, fenwick);

        // update visited element
        fenwickUpdate(mask[i], n, fenwick);
    }

    return ans;
}

// Merge Sort Approach

long long merge(long long arr[], long long temp[], int left, int mid, int right)
{
    long long inv = 0;
    int i = left, j = mid, k = right;

    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
        {
            temp[k++] = arr[j++];
            inv += mid - i;
        }
    }

    while ()
}

long long countInversions(long long arr[], long long temp[], int left, int right)
{
    int mid, inv = 0;
    if (right > left)
    {
        mid = left + (right - left) / 2;

        inv += countInversions(arr, temp, left, mid);
        inv += countInversions(arr, temp, mid + 1, right);

        inv += merge(arr, temp, left, mid + 1, right);
    }
    return inv;
}

int main()
{
    long long arr[] = {5, 3, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long temp[n];

    long long inv = countInversions(arr, temp, 0, n - 1);
    cout << "number of inversions are: " << inv << "\n";

    return 0;
}