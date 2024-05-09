// https://leetcode.com/problems/create-maximum-number/

/*
Example 1:
Input: nums1 = [3,4,6,5], nums2 = [9,1,2,5,8,3], k = 5
Output: [9,8,6,5,3]

Example 2:
Input: nums1 = [6,7], nums2 = [6,0,4], k = 5
Output: [6,7,6,0,4]

Example 3:
Input: nums1 = [3,9], nums2 = [8,9], k = 3
Output: [9,8,9]
*/

vector<int> maxNum(vector<int> &nums, int k)
{
    int drop = nums.size() - k; // for not removing more than (n - k) elements
    vector<int> st;             // stack
    for (int i : nums)
    {
        while (drop && st.size() && st.back() < i)
            st.pop_back(), drop--;

        st.push_back(i);
    }
    st.resize(k);
    return st;
}

vector<int> merge(vector<int> nums1, vector<int> nums2)
{
    vector<int> out;
    while (nums1.size() + nums2.size())
    {
        // & essentially gets hold of the nums instance
        vector<int> &now = nums1 > nums2 ? nums1 : nums2;
        out.push_back(now[0]);
        // nums[0] is deleted using the held instance of nums
        now.erase(now.begin());
    }
    return out;
}

// alternate merge method
vector<int> merge2(vector<int> nums1, vector<int> nums2)
{
    vector<int> out;
    auto i1 = nums1.begin(), end1 = nums1.end();
    auto i2 = nums2.begin(), end2 = nums2.end();
    while (i1 != end1 || i2 != end2)
        out.push_back(lexicographical_compare(i1, end1, i2, end2) ? *i2++ : *i1++);
    return out;
}

vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n1 = nums1.size(), n2 = nums2.size();
    vector<int> ans;
    for (int k1 = max(k - n2, 0); k1 <= min(k, n1); k1++)
        ans = max(ans, merge(maxNum(nums1, k1), maxNum(nums2, k - k1)));
    return ans;
}
