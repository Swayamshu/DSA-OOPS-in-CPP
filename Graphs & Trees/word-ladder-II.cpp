// https://leetcode.com/problems/word-ladder-ii/description/

/*
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

vector<vector<string> > ans;
vector<vector<int> > adj, paths, parents;
int n;

bool isNbr(string &a, string &b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] != b[i])
            cnt++;
    return cnt == 1;
}

void dfs(int node, vector<int> &path)
{
    if (node == -1)
    {
        paths.push_back(path);
        return;
    }

    for (int par : parents[node])
    {
        path.push_back(par);
        dfs(par, path);
        path.pop_back();
    }
}

vector<vector<string> > findLadders(string beginWord, string endWord, vector<string> &wordList)
{
    ans.clear();
    n = wordList.size();
    int start = -1,
        end = -1;
    for (int i = 0; i < n; i++)
    {
        if (wordList[i] == beginWord)
            start = i;
        if (wordList[i] == endWord)
            end = i;
    }

    if (end == -1)
        return ans;
    if (start == -1)
    {
        wordList.push_back(beginWord);
        start = n;
        n++;
    }

    adj.resize(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isNbr(wordList[i], wordList[j]))
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }

    // bfs traversal for finding least path and setting parents
    parents.resize(n);
    vector<int> dist(n, 1005);
    queue<int> q;
    q.push(start);
    parents[start] = {-1}, dist[start] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int nbr : adj[curr])
        {
            if (dist[curr] + 1 < dist[nbr])
            {
                dist[nbr] = 1 + dist[curr];
                q.push(nbr);
                parents[nbr].clear();
                parents[nbr].push_back(curr);
            }
            else if (dist[curr] + 1 == dist[nbr])
                parents[nbr].push_back(curr);
        }
    }

    // dfs traversal for printing the shortest route path
    paths.clear();
    vector<int> path = {end};
    dfs(end, path);

    for (auto &v : paths)
        reverse(v.begin(), v.end());

    for (auto path : paths)
    {
        vector<string> p;
        for (int i : path)
            if (i != -1)
                p.push_back(wordList[i]);
        ans.push_back(p);
    }
    return ans;
}