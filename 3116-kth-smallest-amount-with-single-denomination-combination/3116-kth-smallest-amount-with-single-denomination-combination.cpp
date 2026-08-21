class Solution {
public:

    long long countValid(long long x, vector<int>& coins) {

        int n = coins.size();
        long long ans = 0;

        // Try every non-empty subset of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long long l = 1;
            int bits = 0;

            // Find which coins are selected
            for (int i = 0; i < n; i++) {

                if (mask & (1 << i)) {

                    bits++;

                    l = lcm(l, (long long)coins[i]);
                }
            }

            // How many numbers <= x are divisible
            // by all selected coins?
            long long ways = x / l;

            // Inclusion-Exclusion
            if (bits % 2 == 1)
                ans += ways;
            else
                ans -= ways;
        }

        return ans;
    }


    long long findKthSmallest(vector<int>& coins, int k) {

        long long low = 1;

        long long high =
            1LL * (*min_element(coins.begin(), coins.end())) * k;


        while (low < high) {

            long long mid =
                low + (high - low) / 2;

            if (countValid(mid, coins) >= k)
                high = mid;

            else
                low = mid + 1;
        }

        return low;
    }
};