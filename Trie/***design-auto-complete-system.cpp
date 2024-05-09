#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>

using namespace std;

class TrieNode
{
    map<char, TrieNode *> link;
    map<string, int> hits;
    bool is_word;

public:
    TrieNode()
    {
        link = map<char, TrieNode *>();
        hits = map<string, int>();
        is_word = false;
    }

    bool contains(char key)
    {
        return link.count(key);
    }

    void put(char key, TrieNode *node)
    {
        link[key] = node;
    }

    TrieNode *get(char key)
    {
        return link[key];
    }

    void setCount(string sentence, int cnt)
    {
        hits[sentence] += cnt;
    }

    bool isWord()
    {
        return is_word;
    }

    void setWord()
    {
        is_word = true;
    }

    map<string, int> getAllHits()
    {
        return hits;
    }
};

class AutoCompleteSystem
{
    TrieNode *root;
    string prefix;
    int size;

    void add(string sentence, int hits)
    {
        TrieNode *node = root;
        for (char key : sentence)
        {
            if (!node->contains(key))
                node->put(key, new TrieNode());
            node = node->get(key);
            node->setCount(sentence, hits);
        }
        node->setWord();
    }

public:
    AutoCompleteSystem(vector<string> &sentences, vector<int> &counts, int hits_size)
    {
        root = new TrieNode();
        prefix = "";
        size = hits_size;

        for (int i = 0; i < sentences.size(); i++)
        {
            // cout << counts[i] << " " << sentences[i] << "\n";
            add(sentences[i], counts[i]);
        }
    }

    string getPrefix()
    {
        return prefix;
    }

    vector<string> input(char ch)
    {
        if (ch == '#')
        {
            add(prefix, 1);
            prefix = "";
            return vector<string>();
        }

        prefix += ch;
        TrieNode *node = root;

        for (char key : prefix)
        {
            if (!node->contains(key))
                return vector<string>();
            node = node->get(key);
        }

        deque<pair<int, string> > top_hits;
        map<string, int> hits_map = node->getAllHits();

        for (auto match : hits_map)
        {
            string sentence = match.first;
            int hit_count = match.second;

            if (top_hits.size() && top_hits.front().first >= hit_count)
                top_hits.push_back(make_pair(hit_count, sentence));
            else
                top_hits.push_front(make_pair(hit_count, sentence));

            while (top_hits.size() > size)
                top_hits.pop_back();
        }

        vector<string> top_k_hits;
        // cout << top_hits.size();
        while (!top_hits.empty())
        {
            string sentence = top_hits.front().second;
            top_hits.pop_front();
            top_k_hits.push_back(sentence);
        }

        return top_k_hits;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<string> sentences = {"i love you", "island", "i love leetcode", "isonman"};
    vector<int> hits = {5, 3, 2, 2};
    vector<char> inputs = {'i', ' ', 'l', 'r', '#'};

    AutoCompleteSystem *search_bar = new AutoCompleteSystem(sentences, hits, 3);

    for (char c : inputs)
    {
        vector<string> result = search_bar->input(c);
        cout << search_bar->getPrefix() << "\n";
        for (int j = 0; j < result.size(); j++)
        {
            cout << j + 1 << ": " << result[j] << "\n";
        }
        cout << "\n";
    }

    return 0;
}