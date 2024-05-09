// https://leetcode.com/problems/word-ladder/description/

/*
Example 1:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
*/

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    int cnt = 1;
    unordered_set<string> words(wordList.begin(), wordList.end());
    queue<string> q;
    q.push(beginWord);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            string word = q.front();
            q.pop();

            if (word == endWord)
                return cnt;
            words.erase(word);

            for (int j = 0; j < word.size(); j++)
            {
                char c = word[j];
                for (int k = 0; k < 26; k++)
                {
                    word[j] = 'a' + k;
                    if (words.find(word) != words.end())
                        q.push(word);
                }
                word[j] = c;
            }
        }
        cnt++;
    }

    return 0;
}