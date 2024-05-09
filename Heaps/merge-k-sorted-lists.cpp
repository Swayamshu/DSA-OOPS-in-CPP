// https://leetcode.com/problems/merge-k-sorted-lists/description/

/*
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Input: lists = []
Output: []

Input: lists = [[]]
Output: []
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

// approach 1

class compare
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return nullptr;
        priority_queue<ListNode *, vector<ListNode *>, compare> minheap;

        for (auto node : lists)
            if (node)
                minheap.push(node);

        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        while (!minheap.empty())
        {
            ListNode *temp = minheap.top();
            minheap.pop();

            if (!head)
            {
                head = temp;
                tail = temp;
                if (tail->next)
                    minheap.push(tail->next);
            }
            else
            {
                tail->next = temp;
                tail = temp;
                if (tail->next)
                    minheap.push(tail->next);
            }
        }

        return head;
    }
};

// approach 2

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<int, vector<int>, greater<int> > minH;
    for (auto node : lists)
    {
        while (node)
        {
            minH.push(node->val);
            node = node->next;
        }
    }
    if (minH.empty())
        return nullptr;

    ListNode *head = new ListNode(minH.top());
    minH.pop();
    ListNode *curr = head;
    while (!minH.empty())
    {
        ListNode *temp = new ListNode(minH.top());
        minH.pop();
        curr->next = temp;
        curr = temp;
    }

    return head;
}