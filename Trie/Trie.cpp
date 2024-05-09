#include <iostream>
#include <vector>

using namespace std;

class Node
{
    vector<Node *> link;
    bool end;

public:
    Node()
    {
        link.assign(26, nullptr);
        end = false;
    }

    bool containsKey(char ch)
    {
        return link[ch - 'a'] != nullptr;
    }

    void put(char ch, Node *node)
    {
        link[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return link[ch - 'a'];
    }

    void endWord()
    {
        end = true;
    }

    bool isEnd()
    {
        return end;
    }

    void printNode()
    {
        for (int i = 0; i < 26; i++)
            if (link[i] != nullptr)
                cout << char('a' + i) << " ";
        cout << " \n";
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

    void insert(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
                node->put(ch, new Node());
            node = node->get(ch);
        }
        node->endWord();
    }

    bool search(string word)
    {
        Node *node = root;
        for (char ch : word)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (char ch : prefix)
        {
            if (!node->containsKey(ch))
                return false;
            node = node->get(ch);
        }
        return true;
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

    int t;
    cin >> t;
    Trie t1;

    while (t--)
    {
        int op;
        cin >> op;

        string s;
        cin >> s;

        switch (op)
        {
        case 1:
            t1.insert(s);
            break;
        case 2:
            cout << t1.search(s) << "\n";
            break;
        case 3:
            cout << t1.startsWith(s) << "\n";
            break;
        }
    }

    return 0;
}