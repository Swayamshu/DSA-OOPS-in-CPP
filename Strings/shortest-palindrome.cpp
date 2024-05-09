// https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2023-09-01

/*
Example 1:
Input: s = "aacecaaa"
Output: "aaacecaaa"

Example 2:
Input: s = "abcd"
Output: "dcbabcd"
*/

vector<int> KMP(string &s)
{
    int n = s.size();
    vector<int> kmp(n + 1);
    int i = 0, j = -1;
    kmp[0] = -1;

    while (i < n)
    {
        // jumping backwards in kmp array to find any other
        // possibility of match in cases of mismatches
        while (j != -1 && s[j] != s[i])
            j = kmp[j];

        j++, i++;
        kmp[i] = j;
    }

    return kmp;
}

string shortestPalindrome(string s)
{
    string x = s;
    reverse(x.begin(), x.end());

    string t = s + '#' + x;
    int n = t.size();
    vector<int> kmp = KMP(t);

    int len = kmp[n];

    string res = s.substr(len);
    reverse(res.begin(), res.end());

    return res + s;
}