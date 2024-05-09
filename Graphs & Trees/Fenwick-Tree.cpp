#include <iostream>
#include <vector>

class FenwickTree
{
private:
    std::vector<int> BIT;
    int size;

public:
    FenwickTree(int n)
    {
        size = n;
        BIT.assign(n + 1, 0);
    }

    // Update the value at index 'i' by 'delta'.
    void update(int i, int delta)
    {
        // Incrementally update the Fenwick Tree from 'i' to the end.
        while (i <= size)
        {
            BIT[i] += delta;
            i += i & (-i); // Add the least significant set bit
        }
    }

    // Get the prefix sum of the first 'i' elements.
    int query(int i)
    {
        int sum = 0;
        while (i > 0)
        {
            sum += BIT[i];
            i -= i & (-i); // Remove the least significant set bit
        }
        return sum;
    }

    // Get the sum in the range [left, right].
    int queryRange(int left, int right)
    {
        return query(right) - query(left - 1);
    }
};

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();

    // Initialize the Fenwick Tree with zeros.
    FenwickTree fenwick(n);

    // Build the Fenwick Tree by updating it with the array elements.
    for (int i = 1; i <= n; ++i)
    {
        fenwick.update(i, arr[i - 1]);
    }

    // Example queries:
    int sum1 = fenwick.query(5);         // Prefix sum of first 5 elements (1+2+3+4+5)
    int sum2 = fenwick.queryRange(2, 7); // Sum of elements in the range [2, 7] (2+3+4+5+6+7)

    return 0;
}
