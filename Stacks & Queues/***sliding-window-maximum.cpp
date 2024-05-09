// https://leetcode.com/problems/sliding-window-maximum/

/*
Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]
*/

// Approach 1: Deque

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans(n - k + 1);
    deque<int> dq; // dq front has the max num's index always

    for (int i = 0; i < n; i++)
    {
        // remove all prev nums smaller than curr num from the window
        while (!dq.empty() && nums[dq.back()] <= nums[i])
            dq.pop_back();

        dq.push_back(i); // add the curr num index to the window

        if (dq.front() == i - k) // window limit reached so remove last num
            dq.pop_front();

        if (i + 1 - k >= 0) // note the max nums of all windows
            ans[i - k + 1] = nums[dq.front()];
    }

    return ans;
}

// Approach 2: Priority Queue

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    priority_queue<pair<int, int> > pq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
        pq.push({nums[i], i});
    ans.push_back(pq.top().first);

    for (int i = k; i < nums.size(); i++)
    {
        pq.push({nums[i], i});

        while (i - k >= pq.top().second)
            pq.pop(); // if max num is out of window, remove it

        ans.push_back(pq.top().first);
    }

    return ans;
}