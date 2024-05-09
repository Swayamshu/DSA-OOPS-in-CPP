// https://leetcode.com/problems/reverse-nodes-in-k-group/

/**
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    int cnt = 0;
    ListNode *curr = head, *ptr = head;
    while (curr != nullptr)
    {
        cnt++;
        curr = curr->next;
    }

    cnt /= k;
    stack<int> st; // reverse nodes
    int k1 = k;

    curr = head;
    while (curr != nullptr && cnt)
    {
        st.push(curr->val);
        k1--;
        curr = curr->next;

        if (k1 == 0)
        {
            while (!st.empty())
            {
                ptr->val = st.top();
                st.pop();
                ptr = ptr->next;
            }
            cnt--;
            k1 = k;
        }
    }
    return head;
}
