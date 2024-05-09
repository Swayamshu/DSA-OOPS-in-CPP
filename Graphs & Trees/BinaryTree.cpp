#include <bits/stdc++.h>

typedef long long ll;

#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define FORN(a, b, c) for (int(a) = (b); (a) >= (c); --(a))
#define FORll(a, b, c) for (long long(a) = (b); (a) < (c); ++(a))
#define FORNll(a, b, c) for (long long(a) = (b); (a) >= (c); --(a))

const ll MOD = 1e9 + 7;

using namespace std;

template <typename T>

struct Node // binary tree
{
    T key;
    Node *left;
    Node *right;

    Node(T data)
    {
        key = data;
        right = left = nullptr;
    }
};

void inorder(Node *root) // Time: O(n), Aux Space: O(height of binary tree)
{
    if (root != nullptr)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

void preorder(Node *root) // Time: O(n), Aux Space: O(h)
{
    if (root != nullptr)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root) // Time: O(n), Aux Space: O(h)
{
    if (root != nullptr)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
    }
}

int height(Node *root)
{
    if (root == nullptr)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

void printKthNodes(Node *root, int k)
{
    if (root == nullptr)
        return;
    if (k == 0)
        cout << root->key << " ";
    else
    {
        printKthNodes(root->left, k - 1);
        printKthNodes(root->right, k - 1);
    }
}

void printLevels(Node *root) // Level Order Traversal
{                            // Time: O(n), Aux Space: O(n) or theta(width of binary tree)
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    Node *curr;

    while (!q.empty())
    {
        curr = q.front();
        q.pop();

        cout << curr->key << " ";

        if (curr->left != nullptr)
            q.push(curr->left);
        if (curr->right != nullptr)
            q.push(curr->right);
    }
}

void printLevelsLineByLine(Node *root) // Time: O(n) Aux Space: O(n) or theta(width)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(nullptr);
    Node *curr;

    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();

        if (curr == nullptr)
        {
            cout << "\n";
            q.push(nullptr);
            continue;
        }

        cout << curr->key << " ";
        if (curr->left != nullptr)
            q.push(curr->left);
        if (curr->right != nullptr)
            q.push(curr->right);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}