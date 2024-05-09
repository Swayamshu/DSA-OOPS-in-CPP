// https://leetcode.com/problems/linked-list-in-binary-tree/description/

/*
Input: head = [4,2,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree. 

Input: head = [1,4,2,6], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true

Input: head = [1,4,2,6,8], root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// brute force solution -> Time: O(N * min(H, L)), Space: O(min(H, L))
// optimised soln using kmp matching -> Time: O(N + L), Space: O(H + L)

class Solution
{
    vector<int> getList(ListNode *head)
    {
        vector<int> nums;
        while (head != nullptr)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return nums;
    }

    vector<int> computeLPS(vector<int> &nums)
    {
        int n = nums.size(), len = 0;
        vector<int> lps(n, 0);

        for (int i = 1; i < n;)
        {
            if (nums[i] == nums[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else
            {
                if (len != 0)
                    len = lps[len - 1];
                else
                    lps[i++] = 0;
            }
        }
        return lps;
    }

    bool checkListInTree(TreeNode *root, int pos, vector<int> &nums, vector<int> &lps)
    {
        if (pos == lps.size())
            return true;
        if (root == nullptr)
            return false;

        while (pos > 0 && root->val != nums[pos])
            pos = lps[pos - 1]; // jumping backward in lps if match not found

        if (root->val == nums[pos])
            pos++;

        bool check_left = checkListInTree(root->left, pos, nums, lps);
        bool check_right = checkListInTree(root->right, pos, nums, lps);

        return check_left + check_right;
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (root == nullptr)
            return false;

        vector<int> nums = getList(head);
        vector<int> lps = computeLPS(nums);
        bool check_root = checkListInTree(root, 0, nums, lps);

        return check_root;
    }
};