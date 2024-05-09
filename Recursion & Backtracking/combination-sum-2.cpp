// https://leetcode.com/problems/combination-sum-ii/description/

/*
    Input: candidates = [10,1,2,7,6,1,5], target = 8
    Output: 
    [
    [1,1,6],
    [1,2,5],
    [1,7],
    [2,6]
    ]
*/

void solve(int pos, vector<int> &candidates, int target, vector<int> &curr, vector<vector<int> > &ans)
{
    if (target == 0)
    {
        ans.push_back(curr);
        return;
    }
    if (pos == candidates.size())
        return;

    for (int i = pos; i < candidates.size(); i++)
    {
        if (i > pos && candidates[i] == candidates[i - 1])
            continue;

        if (target - candidates[i] >= 0)
        {
            curr.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i], curr, ans);
            curr.pop_back();
        }
    }
}

vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int> > ans;
    vector<int> curr;
    sort(candidates.begin(), candidates.end());
    solve(0, candidates, target, curr, ans);
    return ans;
}