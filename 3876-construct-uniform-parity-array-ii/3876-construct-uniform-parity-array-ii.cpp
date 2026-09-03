class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;

        // Find the smallest odd and smallest even number
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            } else {
                minEven = min(minEven, x);
            }
        }

        // All numbers are even
        if (minOdd == INT_MAX) {
            return true;
        }

        // All numbers are odd
        if (minEven == INT_MAX) {
            return true;
        }

        // We have both odd and even numbers.
        // We must make everything odd.
        return minOdd < minEven;
    }
};