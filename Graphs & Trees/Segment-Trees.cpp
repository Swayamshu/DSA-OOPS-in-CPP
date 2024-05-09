#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
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
        cout << i << " ";
#define all(a) a.begin(), a.end()

const ll MOD = 1e9 + 7;

using namespace std;

class SegmentTree
{
private:
    vector<int> arr, tree;
    int n;

public:
    SegmentTree(vector<int> &v)
    {
        n = v.size();
        arr = v;
        tree.resize(4 * n); // why 4 * n ?
        build(1, 0, n - 1); // idx = 1 because build tree at root index = 1
    }

    void build(int idx, int left, int right)
    {
        if (left == right)
        {
            tree[idx] = arr[left];
            return;
        }

        int mid = left + (right - left) / 2;

        build(2 * idx, left, mid);
        build(2 * idx + 1, mid + 1, right);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1]; // range query logic (here -> +)
    }

    void update(int idx, int val, int rootIdx = 1, int left = 0, int right = -1)
    {
        if (right == -1)
            right = n - 1;

        if (left == right)
        {
            tree[rootIdx] = val;
            return;
        }

        int mid = left + (right - left) / 2;

        if (idx < mid)
            update(idx, val, 2 * rootIdx, left, mid);
        else
            update(idx, val, 2 * rootIdx + 1, mid + 1, right);

        tree[rootIdx] = tree[2 * rootIdx] + tree[2 * rootIdx + 1];
    }

    int query(int idx, int left, int right, int qLeft, int qRight)
    {
        if (qRight < left || right < qLeft)
            return 0;
        if (qLeft <= left && right <= qRight)
            return tree[idx];

        int mid = left + (right - left) / 2;

        int lQuery = query(2 * idx, left, mid, qLeft, qRight);
        int rQuery = query(2 * idx + 1, mid + 1, right, qLeft, qRight);

        return lQuery + rQuery;
    }

    int query(int left, int right)
    {
        return query(1, 0, n - 1, left, right);
    }

    void printTree()
    {
        queue<int> q;
        q.push(1);

        while (!q.empty())
        {
            int sz = q.size();
            FOR(i, 0, sz)
            {
                int idx = q.front();
                q.pop();
                cout << tree[idx] << " ";

                if (2 * idx < 4 * n)
                    q.push(2 * idx);
                if (2 * idx + 1 < 4 * n)
                    q.push(2 * idx + 1);
            }
            cout << "\n";
        }
    }
};

void solve()
{
    // vector<int> v = {4, 2, 6, 4, 8, 9, 1, 13};
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    SegmentTree segTree(a);
    // cout << segTree.query(0, 8) << "\n";
    // segTree.update(4, 10);
    // segTree.printTree();
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << l << ", " << r << ": " << segTree.query(--l, --r) << "\n";
    }
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