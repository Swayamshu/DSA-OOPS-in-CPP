#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

typedef long long ll;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORll(a, b, c) for (long long(a) = (b); (a) < (c); ++(a))
#define FORNll(a, b, c) for (long long(a) = (b); (a) >= (c); --(a))
#define INF INT_MAX
#define INFll LLONG_MAX
#define ii pair<int, int>
#define f first
#define s second
#define print(arr)     \
    for (auto i : arr) \
        cout << i      \
             << " ";
#define all(a) a.begin(), a.end()

const ll MOD = 1e9 + 7;

using namespace std;

void merge(vector<int> &arr, const int left, const int mid, const int right)
{
    int n1 = mid - left + 1,
        n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);
    FOR(i, 0, n1)
    leftArr[i] = arr[left + i];
    FOR(i, 0, n2)
    rightArr[i] = arr[mid + i + 1];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] < rightArr[j])
            arr[k++] = leftArr[i++];
        else
            arr[k++] = rightArr[j++];
    }

    while (i < n1)
        arr[k++] = leftArr[i++];
    while (j < n2)
        arr[k++] = rightArr[j++];
}

void mergeSort(vector<int> &arr, const int left, const int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    mergeSort(v, 0, n - 1);
    print(v);
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

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}