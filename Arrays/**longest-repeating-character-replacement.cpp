// https://leetcode.com/problems/longest-repeating-character-replacement/

/*
Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.
*/

int characterReplacement(string s, int k)
{
    unordered_map<char, int> cnt;
    int maxf = 0, len = 0;
    for (int j = 0; j < s.size(); j++)
    {
        maxf = max(maxf, ++cnt[s[j]]);
        if (len - maxf < k)
            len++;
        else
            cnt[s[j - len]]--;
    }
    return len;
}