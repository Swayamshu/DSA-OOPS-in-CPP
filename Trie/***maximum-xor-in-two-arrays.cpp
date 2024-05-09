#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>

using namespace std;

class Node
{
    vector<Node *> link;

public:
    Node()
    {
        link.assign(2, nullptr);
    }

    bool containsKey(int bit)
    {
        return link[bit] != nullptr;
    }

    void put(int bit, Node *node)
    {
        link[bit] = node;
    }

    Node *get(int bit)
    {
        return link[bit];
    }

    void printNode()
    {
        cout << (link[0] != nullptr ? 1 : 0) << (link[1] != nullptr ? 1 : 0) << " ";
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
                node->put(bit, new Node());
            node = node->get(bit);
        }
    }

    int getMaxXOR(int num)
    {
        Node *node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxXor = maxXor | (1 << i);
                node = node->get(1 - bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int n, m, ans = 0;
    cin >> n >> m;
    vector<int> v1(n), v2(m);
    for (int &i : v1)
        cin >> i;
    for (int &i : v2)
        cin >> i;

    Trie t;
    for (int i : v1)
        t.insert(i);

    for (int i : v2)
        ans = max(ans, t.getMaxXOR(i));

    cout << "Maximum XOR is = " << ans;
    return 0;
}