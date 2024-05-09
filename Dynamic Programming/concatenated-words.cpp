// https://leetcode.com/problems/concatenated-words/description/

/*
Example 1:
Input: words = ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
"dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".

Example 2:
Input: words = ["cat","dog","catdog"]
Output: ["catdog"]
*/

// Time: O(n * L^2), Space: O(N * L)
vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    unordered_set<string> s(words.begin(), words.end());
    vector<string> ans;

    for (string word : words) // O(N)
    {
        int n = word.size();
        vector<bool> possible(n + 1, false);
        possible[0] = true;

        for (int i = 0; i < n; i++) // O(L)
        {
            if (!possible[i])
                continue;
            // if possible to make word till index i, then check ahead

            for (int j = i + 1; j <= n; j++) // O(L)
            {
                // next word len = j - i
                if (j - i < n && s.count(word.substr(i, j - i)))
                    possible[j] = true;
            }

            if (possible[n])
            {
                ans.push_back(word);
                break;
            }
        }
    }
    return ans;
}

// dfs approach
unordered_map<char, vector<string> > adj;
vector<int> dp;

static bool comp(string &w1, string &w2)
{
    return w1.size() < w2.size();
}

bool solve(int i, string &word)
{
    if (i == word.size())
        return true;
    if (i > word.size())
        return false;
    if (dp[i] != -1)
        return dp[i];

    char c = word[i];
    if (adj.count(c) == 0)
        return false;

    for (string w : adj[c])
    {
        int len = w.size();
        if (w == word.substr(i, len))
            if (solve(i + len, word))
                return dp[i] = true;
    }

    return dp[i] = false;
}

bool concatenatedWord(string &word)
{
    dp.assign(word.size(), -1);
    return solve(0, word);
}

vector<string> findAllConcatenatedWordsInADict(vector<string> &words)
{
    sort(words.begin(), words.end(), comp);

    adj.clear();
    adj[words[0][0]].push_back(words[0]);
    vector<string> ans;
    for (int i = 1; i < words.size(); i++)
    {
        if (concatenatedWord(words[i]))
            ans.push_back(words[i]);
        adj[words[i][0]].push_back(words[i]);
    }

    // for(auto it: adj) {
    //     cout << it.first <<": ";
    //     for(auto s: it.second) cout << s << " ";
    //     cout << "\n";
    // }

    return ans;
}