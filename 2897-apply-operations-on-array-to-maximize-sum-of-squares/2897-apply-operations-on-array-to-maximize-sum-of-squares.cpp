
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        // Count how many numbers contain each set bit.
        vector<int> bitCount(31, 0);

        for (int num : nums) {
            for (int bit = 0; bit < 31; bit++) {
                if (num & (1 << bit)) {
                    bitCount[bit]++;
                }
            }
        }

        // Construct k numbers greedily.
        vector<long long> values(k, 0);

        for (int bit = 0; bit < 31; bit++) {
            for (int i = 0; i < k && bitCount[bit] > 0; i++) {
                values[i] |= (1LL << bit);
                bitCount[bit]--;
            }
        }

        // Calculate the sum of squares.
        long long ans = 0;

        for (long long x : values) {
            ans = (ans + x * x % MOD) % MOD;
        }

        return ans;
    }
};
