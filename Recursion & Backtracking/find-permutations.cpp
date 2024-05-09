// https://leetcode.com/problems/permutations/description/

/*
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

void solve(vector<int> &nums, vector<int> &curr, unordered_map<int, int> &hashmap, vector<vector<int> > &ans)
{
    if (curr.size() == nums.size())
    {
        ans.push_back(curr);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (hashmap.count(nums[i]))
            continue;

        curr.push_back(nums[i]);
        hashmap[nums[i]] = 1;
        solve(nums, curr, hashmap, ans);
        curr.pop_back();
        hashmap.erase(nums[i]);
    }
}

vector<vector<int> > permute(vector<int> &nums)
{
    vector<vector<int> > ans;
    vector<int> curr;
    unordered_map<int, int> hashmap;
    sort(nums.begin(), nums.end());
    solve(nums, curr, hashmap, ans);
    return ans;
}