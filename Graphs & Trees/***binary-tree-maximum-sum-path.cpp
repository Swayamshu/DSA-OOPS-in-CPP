// https://leetcode.com/problems/binary-tree-maximum-path-sum/description/

int sum;

int solve(TreeNode *root)
{
    if (!root)
        return 0;
    int l = max(0, solve(root->left));
    int r = max(0, solve(root->right));

    int sumAtNode = root->val + l + r;
    sum = max(sum, sumAtNode);

    return root->val + max(l, r);
}

int maxPathSum(TreeNode *root)
{
    sum = INT_MIN;
    solve(root);
    return sum;
}