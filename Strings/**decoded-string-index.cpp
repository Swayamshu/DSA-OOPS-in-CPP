// https://leetcode.com/problems/decoded-string-at-index/?envType=daily-question&envId=2023-09-27

/*
Example 1:
Input: s = "leet2code3", k = 10
Output: "o"
Explanation: The decoded string is "leetleetcodeleetleetcodeleetleetcode".
The 10th letter in the string is "o".

Example 2:
Input: s = "ha22", k = 5
Output: "h"
Explanation: The decoded string is "hahahaha".
The 5th letter is "h".

Example 3:
Input: s = "a2345678999999999999999", k = 1
Output: "a"
Explanation: The decoded string is "a" repeated 8301530446056247680 times.
The 1st letter is "a".
*/

string decodeAtIndex(string s, int k)
{
    long N = 0, i; // N = size of string

    for (i = 0; N < k; i++)
        N = isdigit(s[i]) ? N * (s[i] - '0') : N + 1;

    while (i--)
    {
        if (isdigit(s[i]))
            N /= (s[i] - '0'), k %= N;
        else if (k == 0 || k == N--)
            return string(1, s[i]);
    }
    return "";
}