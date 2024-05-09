// https://leetcode.com/problems/fruit-into-baskets/

/*
Example 1:
Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.

Example 2:
Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].

Example 3:
Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
*/

/*
Explanation:
Loop all fruit c in tree,
Note that a and b are the last two different types of fruit that we met,
c is the current fruit type,
so it's something like "....aaabbbc..."

Case 1 c == b:
fruit c already in the basket,
and it's same as the last type of fruit
cur += 1
count_b += 1

Case 2 c == a:
fruit c already in the basket,
but it's not same as the last type of fruit
cur += 1
count_b = 1
a = b, b = c

Case 3 c != b && c!= a:
fruit c not in the basket,
cur = count_b + 1
count_b = 1
a = b, b = c
*/

// esentially, you find the longest consecutive subarray with 2 elements
int totalFruit(vector<int> &fruits)
{
    int len = 0, cur = 0, cntLast = 0, a = -1, b = -1;
    for (int c : fruits)
    {
        cur = c == a || c == b ? cur + 1 : cntLast + 1;
        cntLast = c == b ? cntLast + 1 : 1;
        if (b != c)
            a = b, b = c;

        len = max(cur, len);
    }
    return len;
}