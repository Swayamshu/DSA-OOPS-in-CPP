// https://leetcode.com/problems/subarray-sums-divisible-by-k/description/

/*
Example 1:
Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]

Example 2:
Input: nums = [5], k = 9
Output: 0

Explanation:
to calculate how many subarrays are divisible by K is logically equivalent to saying, how many ways can we pair up all prefix sum pairs (i,j) where i < j
such that (prefix[j] - prefix[i]) % K == 0.

Just from that information alone we easily get a O(n^2) solution.
Compute all prefix sums, then check all pair to see if k divides the difference between them.

However, if we just exploit some information w.r.t to the remainder of each prefix sum we can manipulate this into a linear algorithm. Here's how.

Number Theory Part
I noted above that we need to find all prefix sum pairs (i,j) such tha (p[j] - p[i]) % K == 0.
But this is only true, if and only if p[j] % K == p[i] % K
Why is this?

According the the division algorithm we can express p[j] and p[i] in the following way.
p[j] = bK + r0 where 0 <= r0 < K
p[i] = aK + r1 where 0<= r1 < K

Then p[j] - p[i] = (b*K + r0) - (a*K + r1)
= b*K - a*K + r0 - r1 = K*(b-a) + r0 - r1
Again: p[j] - p[i] = K*(b-a) + (r0-r1), in other words
K only divides p[j] - p[i] iff r0-r1 = 0 <-> r0 = r1 QED

But we should not forget about elements in the array that do not need a pairing, namely those that are are divisible by K. That's why I add mod[0] at the end.

Also counting pairs => N choose 2 = > n*(n-1) / 2.
*/

int subarraysDivByK(vector<int> &nums, int k)
{
    int sum = 0, n = nums.size();
    vector<int> rem(k); //  0...k-1 mod groups

    for (int i = 0; i < n; i++)
    {
        sum += nums[i];

        int group = sum % k;
        group += (group < 0) ? k : 0;

        rem[group]++;
    }

    int tot = 0;
    for (int r : rem)
        if (r > 1)
            tot += r * (r - 1) / 2; // nCr(n, 2)

    return tot + rem[0];
}