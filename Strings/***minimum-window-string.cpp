// https://leetcode.com/problems/minimum-window-substring/description/

/*
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (auto c : t)
        mp[c]++;

    int cnt = 0,
        len = INT_MAX,
        pos = 0,
        j = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] > 0)
            cnt++;
        mp[s[i]]--;

        if (cnt == t.size())
        {
            while (j < i && mp[s[j]] < 0)
                mp[s[j++]]++;

            if (i - j < len)
                len = i - (pos = j) + 1;
            mp[s[j++]]++;
            cnt--;
        }
    }

    return len == INT_MAX ? "" : s.substr(pos, len);
}