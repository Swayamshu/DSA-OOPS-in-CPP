// https://www.codingninjas.com/studio/problems/minimum-operations_8360665?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTab=0

/*
Sample Input 1:
2 1 12
3 2
Sample Output 1:
3
Explanation Of Sample Output 1:
Multiply 'start' with 2, start = 2 % 'mod' = 2.
Multiply 'start' with 2, start = 4 % 'mod' = 4.
Multiply 'start' with 3, start = 12 % 'mod' = 12.
So our answer is 3
*/

int mod = 1e3;

// bfs approach
int minimumOperations(int n, int start, int end, vector<int> &a)
{
    vector<int> ans(mod + 5, -1);
    queue<int> q;
    q.push(start);
    ans[start] = 0;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == end)
            return ans[curr];

        for (int i : a)
        {
            int val = (curr * i) % mod;

            if (ans[val] == -1)
            {
                ans[val] = ans[curr] + 1;
                q.push(val);
            }
        }
    }

    return -1;
}