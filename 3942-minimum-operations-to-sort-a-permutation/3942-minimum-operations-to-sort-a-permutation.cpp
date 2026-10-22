
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        bool asc = true, desc = true;

        for (int i = 0; i < n; i++) {
            if (nums[i] != (nums[0] + i) % n)
                asc = false;

            if (nums[i] != (nums[0] - i + n) % n)
                desc = false;
        }

        int ans = INT_MAX;

        // Ascending cyclic order: rotations can go either way,
        // with two reversals needed to simulate a right rotation.
        if (asc) {
            int shift = nums[0];
            int left = (n - shift) % n;
            int right = shift;

            ans = min(left, right + 2);
        }

        // Descending cyclic order: one reversal plus rotations.
        if (desc) {
            int shift = (nums[0] + 1) % n;

            int rotateBeforeReverse = shift;
            int rotateAfterReverse = (n - shift) % n;

            ans = min(ans, 1 + min(rotateBeforeReverse,
                                   rotateAfterReverse));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
