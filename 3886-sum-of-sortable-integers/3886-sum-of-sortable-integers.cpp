class Solution {
public:
    bool isRotation(vector<int>& nums, vector<int>& sorted,
                    int start, int k) {
        vector<int> lps(k, 0);

        // Build KMP LPS array for the sorted segment.
        for (int i = 1, len = 0; i < k; ) {
            if (sorted[start + i] == sorted[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search the sorted segment in the doubled original block.
        int j = 0;

        for (int i = 0; i < 2 * k - 1; i++) {
            int x = nums[start + i % k];

            while (j > 0 && x != sorted[start + j]) {
                j = lps[j - 1];
            }

            if (x == sorted[start + j]) {
                j++;
            }

            if (j == k) {
                return true;
            }
        }

        return false;
    }

    long long sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool ok = true;

            for (int start = 0; start < n; start += k) {
                if (!isRotation(nums, sorted, start, k)) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans += k;
            }
        }

        return ans;
    }
};