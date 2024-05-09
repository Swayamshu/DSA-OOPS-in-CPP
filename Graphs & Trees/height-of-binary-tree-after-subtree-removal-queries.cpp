// https://leetcode.com/problems/height-of-binary-tree-after-subtree-removal-queries/description

/*
Input: root = [1,3,4,2,null,6,5,null,null,null,null,null,7], queries = [4]
Output: [2]
Explanation: The diagram above shows the tree after removing the subtree rooted at node with value 4.
The height of the tree is 2 (The path 1 -> 3 -> 2).

Input: root = [5,8,9,2,1,3,7,4,6], queries = [3,2,4,8]
Output: [3,2,3,2]
Explanation: We have the following queries:
- Removing the subtree rooted at node with value 3. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 4).
- Removing the subtree rooted at node with value 2. The height of the tree becomes 2 (The path 5 -> 8 -> 1).
- Removing the subtree rooted at node with value 4. The height of the tree becomes 3 (The path 5 -> 8 -> 2 -> 6).
- Removing the subtree rooted at node with value 8. The height of the tree becomes 2 (The path 5 -> 9 -> 3).
*/

unordered_map<int, int> lh, rh, res;

int findHeight(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int left = findHeight(root->left),
        right = findHeight(root->right);

    lh[root->val] = left;
    rh[root->val] = right;

    return 1 + max(left, right);
}

void newHeight(TreeNode *root, int lvl, int height)
{
    if (root == nullptr)
        return;

    res[root->val] = height;

    newHeight(root->left, lvl + 1, max(height, lvl + rh[root->val]));
    newHeight(root->right, lvl + 1, max(height, lvl + lh[root->val]));
}

vector<int> treeQueries(TreeNode *root, vector<int> &queries)
{
    int m = queries.size();
    lh.clear(), rh.clear(), res.clear();
    vector<int> ans(m, 0);

    if (root == nullptr)
        return ans;

    findHeight(root);
    newHeight(root, 0, 0);

    for (int i = 0; i < m; i++)
        ans[i] = res[queries[i]];
    return ans;
}