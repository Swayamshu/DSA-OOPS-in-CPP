// https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=eventual-safe-states

/*
Input: 
N = 5, K = 4
dict = {"baa","abcd","abca","cab","cad"}
Output:
1
Explanation:
Here order of characters is 
'b', 'd', 'a', 'c' Note that words are sorted 
and in the given language "baa" comes before 
"abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.
*/

// find topo sort

string findOrder(string dict[], int N, int K)
{
    vector<vector<int> > dag(K);

    for (int i = 0; i < N - 1; i++)
    {
        int j = 0, k = 0, flag = 0;

        while (j < dict[i].size() && k < dict[i + 1].size())
        {
            if (dict[i][j] != dict[i + 1][k] && flag == 0)
            {
                dag[dict[i][j] - 'a'].push_back(dict[i + 1][k] - 'a');
                flag = 1;
            }
            j++, k++;
        }
    }

    for (int i = 0; i < dag.size(); i++)
    {
        printf("%c -> ", i + 'a');
        for (int x : dag[i])
        {
            char ch = x + 'a';
            cout << ch << ", ";
        }
        cout << "\n";
    }

    vector<int> indeg(K, 0);
    for (int i = 0; i < dag.size(); i++)
        for (auto x : dag[i])
            indeg[x]++;

    string ans = "";
    queue<int> q;
    for (int i = 0; i < K; i++)
        if (indeg[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int n = q.front();
        q.pop();

        ans += n + 'a';

        for (auto c : dag[n])
        {
            indeg[c]--;
            if (indeg[c] == 0)
                q.push(c);
        }
    }

    return ans;
}