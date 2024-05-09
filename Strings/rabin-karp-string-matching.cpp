// https://leetcode.com/problems/repeated-dna-sequences/description/

int num(char c)
{
    switch (c)
    {
    case 'A':
        return 0;
    case 'C':
        return 1;
    case 'G':
        return 2;
    case 'T':
        return 3;
    }
    return -1;
}

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> ans;
    unordered_map<long, int> mp;
    unordered_set<long> visited;

    int n = s.size();
    long hash = 0;

    for (int i = 0; i < 10; i++)
        hash = 4 * hash + num(s[i]);
    mp[hash]++;

    for (int i = 1; i <= n - 10; i++)
    {
        hash -= pow(4, 9) * num(s[i - 1]);
        hash = 4 * hash + num(s[i + 9]);
        mp[hash]++;

        if (mp[hash] > 1 && visited.count(hash) == 0)
        {
            ans.push_back(s.substr(i, 10));
            visited.insert(hash);
        }
    }

    return ans;
}

// better optimised bit hashing technique:

vector<string> findRepeatedDnaSequences(string s)
{
    unordered_map<int, int> mp;
    vector<string> ans;
    int t = 0, i = 0;

    while (i < 9)
    {
        // t is used key for (string -> int)
        t = (t << 3 & 0x3FFFFFFF) | s[i++] & 7;
    }

    while (i < s.size())
    {
        t = (t << 3 & 0x3FFFFFFF) | s[i++] & 7;
        cout << t << " ";
        if (++mp[t] == 2)
            ans.push_back(s.substr(i - 10, 10));
    }

    return ans;
}