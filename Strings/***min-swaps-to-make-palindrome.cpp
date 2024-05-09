// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome/

/*
Example 1:
Input: s = "aabb"
Output: 2
Explanation:
We can obtain two palindromes from s, "abba" and "baab". 
- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.

Example 2:
Input: s = "letelt"
Output: 2
Explanation:
One of the palindromes we can obtain from s in 2 moves is "lettel".
One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
Other palindromes such as "tleelt" can also be obtained in 2 moves.
It can be shown that it is not possible to obtain a palindrome in less than 2 moves.
*/

int minMovesToMakePalindrome(string s)
{
    int ans = 0;
    while (s.size())
    {
        int i = s.find(s.back());

        if (i == s.size() - 1)
            ans += s.size() / 2;
        else
            ans += i, s.erase(i, 1);
        s.pop_back();
    }
    return ans;
}