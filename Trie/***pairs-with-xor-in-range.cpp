// https://leetcode.com/problems/count-pairs-with-xor-in-a-range/

/*
Example 1:
Input: nums = [1,4,2,7], low = 2, high = 6
Output: 6
Explanation: All nice pairs (i, j) are as follows:
    - (0, 1): nums[0] XOR nums[1] = 5 
    - (0, 2): nums[0] XOR nums[2] = 3
    - (0, 3): nums[0] XOR nums[3] = 6
    - (1, 2): nums[1] XOR nums[2] = 6
    - (1, 3): nums[1] XOR nums[3] = 3
    - (2, 3): nums[2] XOR nums[3] = 5

Example 2:
Input: nums = [9,8,4,2,1], low = 5, high = 14
Output: 8
Explanation: All nice pairs (i, j) are as follows:
​​​​​    - (0, 2): nums[0] XOR nums[2] = 13
    - (0, 3): nums[0] XOR nums[3] = 11
    - (0, 4): nums[0] XOR nums[4] = 8
    - (1, 2): nums[1] XOR nums[2] = 12
    - (1, 3): nums[1] XOR nums[3] = 10
    - (1, 4): nums[1] XOR nums[4] = 9
    - (2, 3): nums[2] XOR nums[3] = 6
    - (2, 4): nums[2] XOR nums[4] = 5
*/

class Node
{
    vector<Node *> link;
    int count = 0;

public:
    Node()
    {
        link.assign(2, nullptr);
    }

    void put(int bit, Node *node)
    {
        link[bit] = node;
    }

    bool containsKey(int bit)
    {
        return link[bit] != nullptr;
    }

    Node *get(int bit)
    {
        return link[bit];
    }

    int getCount(int bit)
    {
        return link[bit]->count;
    }

    void incCount(int bit)
    {
        link[bit]->count++;
    }
};

class Solution
{
public:
    Node *root = new Node();

    void insert(int num)
    {
        Node *node = root;
        for (int i = 15; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
                node->put(bit, new Node());
            node->incCount(bit); // inc count of numbers every time this node is visited
            node = node->get(bit);
        }
    }

    int getPairs(int num, int k)
    {
        Node *node = root;
        int cntPairs = 0;
        for (int i = 15; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            int bit_k = (k >> i) & 1;

            // bit_k == 1
            if (bit_k)
            {
                if (node->containsKey(bit)) // val has same bit as num then add count of nums
                    cntPairs += node->getCount(bit);
                if (node->containsKey(1 - bit)) // if opposite bit present, move to it
                    node = node->get(1 - bit);
                else
                    break; // if not present then stop as it would increase the xor val
            }
            // bit_k == 0
            else
            {
                if (node->containsKey(bit))
                    node = node->get(bit);
                else
                    break;
            }
        }
        return cntPairs;
    }

    int countPairs(vector<int> &nums, int low, int high)
    {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            cnt += getPairs(nums[i], high + 1) - getPairs(nums[i], low);
            insert(nums[i]);
        }
        return cnt;
    }
};