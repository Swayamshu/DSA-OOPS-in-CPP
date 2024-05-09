// Input: nums = [1,3,4,2,2]
// Output: 2

int findDuplicate(vector<int> &nums)
{
    while (nums[0] != nums[nums[0]])
        swap(nums[0], nums[nums[0]]);
    return nums[0];
}

// Floyd's tortoise and hare algorith (cycle detection)
// -> similar to linked list's cycle detection

int findDuplicate(vector<int> &nums)
{
    int slow = nums[0],
        fast = nums[0];

    // finding the intersection point
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // finding the "entrance" to the cycle
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}