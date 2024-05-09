// https://leetcode.com/problems/number-of-flowers-in-full-bloom/?envType=daily-question&envId=2023-10-11

/*
Input: flowers = [[1,6],[3,7],[9,12],[4,13]], poeple = [2,3,7,11]
Output: [1,2,2,2]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.

Input: flowers = [[1,10],[3,3]], poeple = [3,3,2]
Output: [2,2,1]
Explanation: The figure above shows the times when the flowers are in full bloom and when the people arrive.
For each person, we return the number of flowers in full bloom during their arrival.
*/

#define all(v) v.begin(), v.end()

vector<int> fullBloomFlowers(vector<vector<int> > &flowers, vector<int> &people)
{
    vector<int> start, end, ans;
    for (auto v : flowers)
        start.push_back(v[0]), end.push_back(v[1]);

    sort(all(start));
    sort(all(end));

    for (int time : people)
    {
        // include in cnt as start <= time
        int s = upper_bound(all(start), time) - start.begin();
        // exclude in cnt as  time <= end
        int e = lower_bound(all(end), time) - end.begin();
        ans.push_back(s - e);
    }

    return ans;
}
