// https://leetcode.com/problems/repeated-dna-sequences/description/

/*
Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
*/

/*
instead of using unordered_map<string, int> (hash map) normally which
will take more space and time due to key-string matching, we can 
convert the key-string to number using bit manipulation and then store
the count of each string there.

size of string = 10 
characters: A C G T -> can be converted into 4 diff no's
easiest way is to address them using -> s[i] & 7

0x3FFFFFFF -> 2 0's and 30 1's for 10 x 3 bits of key-string-num

*/

vector<string> findRepeatedDnaSequences(string s)
{
    unordered_map<int, int> mp;
    vector<string> ans;
    int t = 0, i = 0;

    while (i < 9)
    {
        // t is used key for (string -> int)
        t = (t << 3 & 0x3FFFFFFF) | s[i++] & 7;
    }

    while (i < s.size())
    {
        t = (t << 3 & 0x3FFFFFFF) | s[i++] & 7;
        cout << t << " ";
        if (++mp[t] == 2)
            ans.push_back(s.substr(i - 10, 10));
    }

    return ans;
}