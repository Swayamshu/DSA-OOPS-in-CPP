#include <iostream>
#include <vector>

#define print(v)     \
    for (auto i : v) \
        cout << i << " ";

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
{
    int n = nums.size(), maxsum = 0;
    vector<int> sum = {0}, posLeft(n, 0), posRight(n, n - k), ans(3, 0);

    for (int i : nums)
        sum.push_back(i + sum.back());

    for (int i = k, tot = sum[k] - sum[0]; i < n; i++)
        if (sum[i + 1] - sum[i - k + 1] > tot)
        {
            posLeft[i] = i - k + 1;
            tot = sum[i + 1] - sum[i - k + 1];
        }
        else
            posLeft[i] = posLeft[i - 1];

    for (int i = n - k - 1, tot = sum[n] - sum[n - k]; i >= 0; i--)
        if (sum[i + k] - sum[i] >= tot)
        {
            posRight[i] = i;
            tot = sum[i + k] - sum[i];
        }
        else
            posRight[i] = posRight[i + 1];

    for (int i = k; i <= n - 2 * k; i++)
    {
        int l = posLeft[i - 1],
            r = posRight[i + k];

        int tot = (sum[l + k] - sum[l]) + (sum[i + k] - sum[i]) + (sum[r + k] - sum[r]);

        if (tot > maxsum)
        {
            maxsum = tot;
            ans = {l, i, r};
        }
    }

    print(sum);
    cout << " \n";
    print(posLeft);
    cout << " \n";
    print(posRight);
    cout << " \n";

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int &i : arr)
        cin >> i;

    vector<int> ans = maxSumOfThreeSubarrays(arr, k);
    print(ans);

    return 0;
}