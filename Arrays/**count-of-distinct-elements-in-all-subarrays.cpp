void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    unordered_map<ll, ll> mp;
    ll ans, res = 0;

    FOR(i, 0, n)
    {
        if (mp[v[i]] == 0)
            ans += i + 1;
        else
            ans += i - mp[v[i]] + 1;

        mp[v[i]] = i + 1;
        // cout << ans << " ";
        res += ans;
    }

    cout << res;
}