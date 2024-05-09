#include <iostream>
#include <vector>

#define print(v)     \
    for (auto i : v) \
        cout << i << " ";

using namespace std;

// https://leetcode.com/problems/longest-happy-prefix/description/

/*
Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself
("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel").
The largest prefix which is also suffix is given by "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix.
They can overlap in the original string.
*/

vector<int> computeLPS(const string &pattern)
{
    int n = pattern.size();
    vector<int> lps(n, 0);
    int len = 0; // Length of the current longest prefix suffix

    for (int i = 1; i < n;)
    {
        if (pattern[i] == pattern[len])
        { // pattern matches prefix == suffix
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1]; // jumping backwards in lps
            else
            { // no prefix present then len = 0
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    for (char ch : s)
        cout << ch << " ";
    cout << "\n";
    vector<int> kmp = computeLPS(s);
    print(kmp);
    return 0;
}